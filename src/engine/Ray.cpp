/*
** Ray.cpp for raytracer in /home/lemper_a/rendu/raytracer/Raytracer/src
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Mon Nov  9 21:36:06 2015 Antoine Lempereur
** Last update Wed Nov 11 19:04:06 2015 Antoine Lempereur
*/

#include	"engine/Ray.h"
#include	"const.h"

namespace	Engine
{
  Ray::Ray(Tools::Vector origin, Tools::Vector direction)
  {
    this->origin = origin;
    this->direction = direction;
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

  /*  Ray::Ray(double i, double j, Scene const& scene)
  {
    double	x;
    double	y;
    double	z;

    x = w / 2 * ANTI_FISH_EYE_VALUE;
    y = w / 2 - i;
    z = h / 2 - j;
    rotate;
    this->direction.setValues(x, y, z);
    this->inversed.setValues(1 / x, 1 / y, 1 / z);
    }*/

  /*  void	Ray::findClosestObject(std::list<Object*> objects)
  {
    int		i = 0;
    float	dist;

    if (objects.Length == 0)
      return;
    while (i < objects.Length)
      {
	dist = objects[i].Collide(this);
	if (i == 0)
	  {
	    this->dist = dist;
	    this->object = objects[i];
	  }
	else if (dist > 0 && dist < saveDist)
	  {
	    this->dist = dist;
	    this->object = objects[i];
	  }
	i++;
      }
  }*/

  /*void		Ray::setColor(Scene scene)
  {
    int		i = 0;
    int		color = 0;

    //shadowhandler : à calculer dans BigLightFunction, sert à opti le calcul des ombres, càd calculer le main rayon et les objets possiblement rencontré

    this->color.Mix(REFLECTEDCOLOR, this->object->getReflexion());
    this->color.Mix(TRANSPARENCEDCOLOR, this->object->getTransparency());
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
