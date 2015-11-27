/*
** Ray.cpp for raytracer in /home/lemper_a/rendu/raytracer/Raytracer/src
**
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
**
** Started on  Mon Nov  9 21:36:06 2015 Antoine Lempereur
** Last update Thu Nov 26 17:01:00 2015 Antoine Lempereur
*/

#include	"engine/Ray.h"
#include	"const.h"

namespace	Engine
{
  //Ray constructor, knowing origin and direction (useful for reflection and transparency)
  Ray::Ray(Tools::Vector origin, Tools::Vector direction)
  {
    this->origin = origin;
    this->direction = direction;
    this->direction.normalize();
    this->inversed = this->direction;
    this->inversed.inverse();
  }

  Tools::Vector	Ray::calcIntersection(Tools::Vector origin, Tools::Vector direction, float dist)
  {
    Tools::Vector	intersection;

    intersection.setX(origin.getX() + dist * direction.getX());
    intersection.setY(origin.getY() + dist * direction.getY());
    intersection.setZ(origin.getZ() + dist * direction.getZ());
    return (intersection);
  }

  //Normalize ray direction
  void	Ray::normalize()
  {
    this->direction.normalize();
  }

  //Ray constructor for a specific pixel
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

  // Set pos simple to calculate intersection with object
  void		Ray::setPosSimple(Tools::Vector pos, Tools::Vector rot)
  {
    this->originSimple = this->origin - pos;
    this->originSimple.rotate(rot); // rotate inverse ?
	this->directionSimple = this->direction;
    this->directionSimple.rotate(rot);
  }

  // Values to save if closer objects is found
  void		Ray::setSaves(float dist, Engine::Object *object, Tools::Vector &origin, Tools::Vector &direction)
  {
    this->dist = dist;
    this->object = object;
    origin = this->originSimple;
    direction = this->directionSimple;
  }

  // Set dist, object, originSimple and directionSimple for the closest object in a vector of objects
  // To reduce computing time, try to reduce size of vector
  void				Ray::findClosestObject(std::vector<Engine::Object*> objects)
  {
    unsigned int		i = 0;
    float			dist;
    Tools::Vector		saveOriginSimple(this->origin);
    Tools::Vector		saveDirectionSimple(this->direction);

    if (objects.size() == 0)
      return;
    // for each object
    while (i < objects.size())
      {
	// test intersection with bounding box
	if ((dist = objects[i]->getBox().collide(this)) >= 0)
	  {
	    this->setPosSimple(objects[i]->getPosition(), objects[i]->getRotation());
	    //test intersection with object
	    dist = objects[i]->collide(this);
	  }
	if (i == 0)
	  this->setSaves(dist, objects[i], saveOriginSimple, saveDirectionSimple);
	else if (dist > 0 && (dist < this->dist || this->dist < 0))
	  this->setSaves(dist, objects[i], saveOriginSimple, saveDirectionSimple);
	i++;
      }
    this->originSimple = saveOriginSimple;
    this->directionSimple = saveDirectionSimple;
  }

  //Calculate intersection and apply effects to set the final color
  void			Ray::compute(Engine::Scene *scene)
  {
    if (scene->getBox().collide(this) > 0)
      {
	this->findClosestObject(scene->getObjects());
	if (this->dist >= 0)
	  {
	    //this->setIntersection(); attention psition simple / reelle
	    //this->setColor(scene, this->object.getNormal(this));
	    this->color = this->object->getColor();
	  }
	else
	  this->color.setRGB(0, 0, 0); // IMAGE DE FOND ?!
      }
    else
      this->color.setRGB(0, 0, 0); // IMAGE DE FOND ?!
  }

  // Return reflection direction, normalized
  Tools::Vector		Ray::calcReflectedMainRay(Tools::Vector normal)
  {
    double		scal;
    Tools::Vector	reflected;

    scal = normal.scalar(this->direction);
    reflected.setX(this->direction.getX() - 2 * normal.getX() * scal);
    reflected.setY(this->direction.getY() - 2 * normal.getY() * scal);
    reflected.setZ(this->direction.getZ() - 2 * normal.getZ() * scal);
    reflected.normalize();
    return (reflected);
  }

  // Return refracted direction, normalized
  Tools::Vector		Ray::calcRefractedMainRay(Tools::Vector normal)
  {
    double		scal;
    double		common;
    Tools::Vector	refracted;
    double		nn;

    scal = normal.scalar(this->direction);
    nn = 1 / 1.5;// 1.5 à remplacer par indice de réfraction de l'obj
    common = nn * scal - sqrt(1 + (nn * nn) * ((scal * scal) - 1));
    refracted.setX(this->direction.getX() * nn + normal.getX() * common);
    refracted.setY(this->direction.getY() * nn + normal.getY() * common);
    refracted.setZ(this->direction.getZ() * nn + normal.getZ() * common);
    return (refracted);
  }

  // NOT TESTED YET
  Tools::Color	Ray::getReflectedColor(Scene *scene, Tools::Vector normal, Tools::Vector intersection)
  {
    Tools::Vector		reflected = this->calcReflectedMainRay(normal);
    //Tools::ReflectionHandler	handler(this->intersection + reflected, reflected);
    Ray			ray(intersection + reflected, reflected);

    ray.compute(scene);
    return (ray.getColor());
  }

  // NOT TESTED YET
  Tools::Color	Ray::getRefractedColor(Scene *scene, Tools::Vector normal, Tools::Vector intersection)
  {
    Tools::Vector		refracted = this->calcRefractedMainRay(normal);
    //Tools::ReflectionHandler	handler(this->intersection + reflected, reflected);
    Ray			ray(intersection + refracted, refracted);

    ray.compute(scene);
    return (ray.getColor());
  }

  Tools::Color		Ray::getColor()
  {
    return (this->color);
  }

  Tools::Vector		Ray::getInversed()
  {
    return (this->inversed);
  }

  Tools::Vector		Ray::getOrigin()
  {
    return (this->origin);
  }

  Tools::Vector		Ray::getDirection()
  {
    return (this->direction);
  }

  Tools::Vector	Ray::getOriginSimple()
  {
    return (this->originSimple);
  }

  Tools::Vector	Ray::getDirectionSimple()
  {
    return (this->directionSimple);
  }

  Engine::Object*	Ray::getObject()
  {
    return (this->object);
  }

  bool			Ray::getIsLim()
  {
    return (this->isLim);
  }

  double		Ray::getDist()
  {
    return (this->dist);
  }

  // NOT TESTED YET
  /*void			Ray::setColor(Scene const& scene)
  {
    int			i = 0;
    Tools::Color	color;
    Tools::Vector	interSimple(this->calcIntersection(this->originSimple, this->directionSimple, this->dist));
    Tools::Vector	interReel(this->calcIntersection(this->origin, this->direction, this->dist));
    Tools::Vector	normal(this->object.getNormal(interSimple));

    //shadowhandler : à calculer dans BigLightFunction, sert à opti le calcul des ombres, càd calculer le main rayon et les objets possiblement rencontré

    this->color.Mix(this->getReflectedColor(scene), this->object->getReflexion());
    this->color.Mix(this->getRefractedColor(scene),
    		    this->object->getTransparency());
    while (i < scene.getLights().Length)
      {
	color += scene.getLights()[i].BigLightFunction(scene, this, interReel, normal);
	i++;
      }
    this->color = color;
    this->color.PreventOverflow();
    }*/

  Ray::~Ray()
  {

  }
};
