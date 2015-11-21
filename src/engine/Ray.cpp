/*
** Ray.cpp for raytracer in /home/lemper_a/rendu/raytracer/Raytracer/src
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Mon Nov  9 21:36:06 2015 Antoine Lempereur
** Last update Sat Nov 21 21:37:29 2015 Antoine Lempereur
*/

#include	"engine/Ray.h"
#include	"const.h"

namespace	Engine
{
  Ray::Ray(Tools::Vector origin, Tools::Vector direction)
  {
    this->origin = origin;
    this->direction = direction;
    this->direction.normalize();
    this->inversed = this->direction;
    this->inversed.inverse();
  }

  void	Ray::setIntersection()
  {
    this->intersection.setX(this->origin.getX() +
			    this->dist * this->direction.getX());
    this->intersection.setY(this->origin.getY() +
			    this->dist * this->direction.getY());
    this->intersection.setZ(this->origin.getZ() +
			    this->dist * this->direction.getZ());
  }

  void	Ray::normalize()
  {
    this->direction.normalize();
  }

  Ray::Ray(double i, double j, Scene *scene)
  {
    double	x;
    double	y;
    double	z;

    x = scene->getWidth() / 2 * ANTI_FISH_EYE_VALUE;
    y = scene->getWidth() / 2 - i;
    z = scene->getHeight() / 2 - j;
    this->origin = scene->getOrigin();
    this->direction.setValues(x, y, z);
    this->direction.rotate(scene->getRotation());
    this->direction.normalize();
    this->inversed = this->direction;
    this->inversed.inverse();
  }

  void		Ray::swapToPosSimple(Tools::Vector pos, Tools::Vector rot)
  {
    this->origin = this->origin - pos;
    this->origin.rotate(rot);
    this->direction.rotate(rot);
  }

  void				Ray::findClosestObject(std::vector<Engine::Object*> objects)
  {
    unsigned int		i = 0;
    float			dist;
    Tools::Vector		save_origin(this->origin);
    Tools::Vector		save_direction(this->direction);

    if (objects.size() == 0)
      return;
    while (i < objects.size())
      {
	// cette maniere de gérer la position simple est pas ouf, go repenser le truc
	this->origin = save_origin;
	this->direction = save_direction;
	if ((dist = objects[i]->getBox().collide(this)) >= 0) // on perd du temps à faire ça sur les spheres, c'est juste pour voir ce qui marche atm
	  {
	    this->swapToPosSimple(objects[i]->getPosition(), objects[i]->getRotation());
	    //dist = objects[i]->collide(this);
	  }
	if (i == 0)
	  {
	    this->dist = dist;
	    this->object = objects[i];
	  }
	else if (dist > 0 && (dist < this->dist || this->dist < 0))
	  {
	    this->dist = dist;
	    this->object = objects[i];
	  }
	i++;
      }
  }

  void			Ray::compute(Engine::Scene *scene)
  {
    /*if (Scene.Box.collide(this) > 0)

     */
    this->findClosestObject(scene->getObjects());
    if (this->dist >= 0)
      {
	//this->setIntersection();
	//this->setColor(scene, this->object.getNormal(this));
	this->color = this->object->getColor();
      }
    else
      this->color.setRGB(0, 0, 0); // IMAGE DE FOND ?!
  }

  Tools::Vector		Ray::calcReflectedMainRay()
  {
    double		scal;
    Tools::Vector	reflected;

    scal = this->normal.scalar(this->direction); // direction doit etre en position normale
    reflected.setX(this->direction.getX() - 2 * this->normal.getX() * scal);
    reflected.setY(this->direction.getY() - 2 * this->normal.getY() * scal);
    reflected.setZ(this->direction.getZ() - 2 * this->normal.getZ() * scal);
    reflected.normalize();
    return (reflected);
  }

  Tools::Vector		Ray::calcRefractedMainRay()
  {
    double		scal;
    double		common;
    Tools::Vector	refracted;
    double		nn;

    scal = this->normal.scalar(this->direction);
    nn = 1 / 1.5;// 1.5 à remplacer par indice de réfraction de l'obj
    common = nn * scal - sqrt(1 + (nn * nn) * ((scal * scal) - 1));
    refracted.setX(this->direction.getX() * nn + this->normal.getX() * common);
    refracted.setY(this->direction.getY() * nn + this->normal.getY() * common);
    refracted.setZ(this->direction.getZ() * nn + this->normal.getZ() * common);
    return (refracted);
  }

  Tools::Color	Ray::getReflectedColor(Scene *scene)
  {
    Tools::Vector		reflected = this->calcReflectedMainRay();
    //Tools::ReflectionHandler	handler(this->intersection + reflected, reflected);
    Ray			ray(this->intersection + reflected, reflected);

    ray.compute(scene);
    return (ray.getColor());
  }

  Tools::Color	Ray::getRefractedColor(Scene *scene)
  {
    Tools::Vector		refracted = this->calcRefractedMainRay();
    //Tools::ReflectionHandler	handler(this->intersection + reflected, reflected);
    Ray			ray(this->intersection + refracted, refracted);

    ray.compute(scene);
    return (ray.getColor());
  }

  Tools::Color	Ray::getColor()
  {
    return (this->color);
  }

  Tools::Vector	Ray::getInversed()
  {
    return (this->inversed);
  }

  Tools::Vector	Ray::getIntersection()
  {
    return (this->intersection);
  }

  Tools::Vector	Ray::getNormal()
  {
    return (this->normal);
  }

  Tools::Vector	Ray::getOrigin()
  {
    return (this->origin);
  }

  Tools::Vector	Ray::getDirection()
  {
    return (this->direction);
  }

  Engine::Object*	Ray::getObject()
  {
    return (this->object);
  }

  bool				Ray::getIsLim()
  {
    return (this->isLim);
  }

  double			Ray::getDist()
  {
    return (this->dist);
  }

  /*void			Ray::setColor(Scene const& scene)
  {
    int			i = 0;
    Tools::Color	color;

    //shadowhandler : à calculer dans BigLightFunction, sert à opti le calcul des ombres, càd calculer le main rayon et les objets possiblement rencontré
    
    this->color.Mix(this->getReflectedColor(scene), this->object->getReflexion());
    this->color.Mix(this->getRefractedColor(scene),
		    this->object->getTransparency());
    while (i < scene.getLights().Length)
      {
	color += scene.getLights()[i].BigLightFunction(scene, this, shadowHandler);
	i++;
      }
    this->color = color;
    this->color.PreventOverflow();
  }*/

  Ray::~Ray()
  {

  }
};
