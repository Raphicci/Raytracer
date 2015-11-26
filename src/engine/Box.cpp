/*
** Box.cpp for raytracer in /home/lemper_a/rendu/Raytracer
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Sun Nov 15 10:11:38 2015 Antoine Lempereur
** Last update Sat Nov 21 21:31:47 2015 Antoine Lempereur
*/

#include	<math.h>

#include	"tools/Vector.h"
#include	"engine/Ray.h"
#include	"engine/Object.h"
#include	"engine/Box.h"

namespace		Engine
{
  Box::Box()
  {

  }

  Box::Box(Tools::Vector lowCorner, Tools::Vector highCorner)
  {
    this->lowCorner = lowCorner;
    this->highCorner = highCorner;
  }

  void	Box::setLowCorner(Tools::Vector lowCorner)
  {
    this->lowCorner = lowCorner;
  }

  void	Box::setHighCorner(Tools::Vector highCorner)
  {
    this->highCorner = highCorner;
  }
    /*  void		Box::setBoxesInside()
	{
	double	width = abs(this->lowCorner.getY() - this->highCorner.getY()) / 2;
	double	height = abs(this->lowCorner.getZ() - this->highCorner.getZ()) / 2;
	double	depth = abs(this->lowCorner.getX() - this->highCorner.getX()) / 2;
	Tools::Vector	lowCorner;
	Tools::Vector	highCorner;
	highCorner.setValues(lowCorner.getX() + depth, lowCorner.getY() + width, lowCorner.getZ() + height);
	// bon vraiment l'encapsulation c'est chiant
	this->boxes[0].lowCorner = lowCorner;
	this->boxes[0].highCorner = etc...
	}*/

  // Return dist from ray;
  // ray.inversed, ray.origin and both corners must be set
  double	Box::collide(Engine::Ray *ray)
  {
    Tools::Vector	v = ray->getInversed();
    Tools::Vector	t1;
    Tools::Vector	t2; // c'est pas genre super con de déclarer ça sous forme de classe ? il y a 0 interet
    double	tmax;
    double	tmin;

    t1.setX((this->lowCorner.getX() - ray->getOrigin().getX()) * v.getX());
    t1.setY((this->highCorner.getX() - ray->getOrigin().getX()) * v.getX());
    t1.setZ((this->lowCorner.getY() - ray->getOrigin().getY()) * v.getY());
    t2.setX((this->highCorner.getY() - ray->getOrigin().getY()) * v.getY());
    t2.setY((this->lowCorner.getZ() - ray->getOrigin().getZ()) * v.getZ());
    t2.setZ((this->highCorner.getZ() - ray->getOrigin().getZ()) * v.getZ());
    tmin = fmax(fmax(fmin(t1.getX(), t1.getY()), fmin(t1.getZ(), t2.getX())), fmin(t2.getY(), t2.getZ()));
    tmax = fmin(fmin(fmax(t1.getX(), t1.getY()), fmax(t1.getZ(), t2.getX())), fmax(t2.getY(), t2.getZ()));
    if (tmax < 0.0)
      return (-1);
    if (tmin > tmax)
      return (-1);
    return (tmin);



      // HEY J'AI TROUVE UNE OPTI DE CE CODE :) je la code sans encapsulation parce que ça me pete les couilles

      // à tester, vérifier, toussa toussa mais ça me parrait bien.

	// en fait ça marche pas ><
    /*double	min[3];
      double	max[3];

      if (r->getInversed().getX() >= 0)
	{
	  min[0] = this->lowCorner.getX() -
	    r->getOrigin().getX() * r->getInversed().getX();
	  max[0] = this->highCorner.getX() -
	    r->getOrigin().getX() * r->getInversed().getX();
	}
      else
	{
	  max[0] = this->lowCorner.getX() -
	    r->getOrigin().getX() * r->getInversed().getX();
	  min[0] = this->highCorner.getX() -
	    r->getOrigin().getX() * r->getInversed().getX();
	}
      if (r->getInversed().getY() >= 0)
	{
	  min[1] = this->lowCorner.getY() -
	    r->getOrigin().getY() * r->getInversed().getY();
	  max[1] = this->highCorner.getY() -
	    r->getOrigin().getY() * r->getInversed().getY();
	}
      else
	{
	  max[1] = this->lowCorner.getY() -
	    r->getOrigin().getY() * r->getInversed().getY();
	  min[1] = this->highCorner.getY() -
	    r->getOrigin().getY() * r->getInversed().getY();
	}
      if (min[0] > max[1] || min[1] > max[0])
	return (-1);
      if (min[1] > min[0])
	min[0] = min[1];
      if (max[1] < max[0])
	max[0] = max[1];
      if (r->getInversed().getZ() >= 0)
	{
	  min[2] = this->lowCorner.getZ() - r->getOrigin().getZ() * r->getInversed().getZ();
	  max[2] = this->highCorner.getZ() - r->getOrigin().getZ() * r->getInversed().getZ();
	}
      else
	{
	  max[2] = this->lowCorner.getZ() - r->getOrigin().getZ() * r->getInversed().getZ();
	  min[2] = this->highCorner.getZ() - r->getOrigin().getZ() * r->getInversed().getZ();
	}
      if (min[0] > max[2] || min[2] > max[0])
	return (-1);
      if (min[2] > min[0])
	min[0] = min[2];
      if (max[2] < max[0])
	max[0] = max[2];
	return (min[0]);*/
  }

  Tools::Vector	Box::getLowCorner()
  {
    return (this->lowCorner);
  }

  Tools::Vector	Box::getHighCorner()
  {
    return (this->highCorner);
  }

    /*  bool	Box::isInsideBox(Engine::Box const& box)
	{

	}*/

    Box::~Box()
    {

    }
  }
