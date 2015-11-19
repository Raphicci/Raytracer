/*
** Ray.cpp for raytracer in /home/lemper_a/rendu/raytracer/Raytracer/src
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Mon Nov  9 21:36:06 2015 Antoine Lempereur
** Last update Wed Nov 18 17:02:09 2015 Antoine Lempereur
*/

#include	"engine/Ray.h"
#include	"const.h"

namespace	Engine
{
  Ray::Ray(Tools::Vector origin, Tools::Vector direction)
  {
    this->origin = origin;
    this->direction = direction;
	this->direction.normalize();//verifier que normaliser des le debut fout aps la merde
    this->inversed = this->direction; // logiquement ça fait bien une copie
    this->inversed.inverse();
	this->squared.setValues(this->direction.getX() * this->direction.getX(), this->direction.getY() * this->direction.getY(), this->direction.getZ() * this->direction.getZ());
  }

  void	Ray::setIntersection()
  {
    this->intersection.setX(this->origin.getX() + this->dist * this->direction.getX());
    this->intersection.setY(this->origin.getY() + this->dist * this->direction.getY());
    this->intersection.setZ(this->origin.getZ() + this->dist * this->direction.getZ());
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
    double	w = 1; // c'est juste pour que ça compile hein
    double	h = 1;

    x = w / 2 * ANTI_FISH_EYE_VALUE;
    y = w / 2 - i;
    z = h / 2 - j;
    this->origin = scene.getOrigin();
    this->direction.setValues(x, y, z);
    this->direction.rotate(0, 0, 0); // (scene.getRotation().getX(), scene.getRotation().getY(), scene.getRotation().getZ())
    this->direction.normalize();//verifier que normaliser des le debut fout aps la merde
    this->inversed = this->direction; // logiquement ça fait bien une copie
    this->inversed.inverse();
	this->squared.setValues(this->direction.getX() * this->direction.getX(), this->direction.getY() * this->direction.getY(), this->direction.getZ() * this->direction.getZ());
	//problème : this->inversed utile que pour l'inter avec box et this->squared que pour l'inter avec certains objets, donc pas utiles 100% du temps -> booleen isSet ? ou juste check que les valeurs sont toutes != 0 (vu qu'on bosse sur une direction, il n'y a jamais le cas 0/0/0)
  }

  void			Ray::findClosestObject(std::vector<Engine::Object*> objects)
  {
    unsigned int	i = 0;
    float		dist;

    if (objects.size() == 0)
      return;
    while (i < objects.size())
      {
	dist = objects[i]->Collide(this);
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
    this->findClosestObject(scene.getObject());
	*/
	  if (this->dist >= 0)
	  {
		  //this->setIntersection();
		  //this->setColor(scene, this->object.getNormal(this));
		  this->color.setRGB(255, 255, 255);
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
