/*
** Box.cpp for raytracer in /home/lemper_a/rendu/Raytracer
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Sun Nov 15 10:11:38 2015 Antoine Lempereur
** Last update Sun Nov 22 15:16:36 2015 Antoine Lempereur
*/

#include	<math.h>

#include	"tools/Vector.h"
#include	"engine/Ray.h"
#include	"engine/Object.h"
#include	"engine/Box.h"
#include	"const.h"

namespace		Engine
{
  Box::Box()
  {
    this->boxes = NULL;
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

  void		Box::setSmallBox(Tools::Vector lowCorner, int pos,
				 double width, double height, double depth)
  {
    Tools::Vector	highCorner;

    highCorner.setValues(lowCorner.getX() + depth, lowCorner.getY() + width, lowCorner.getZ() + height);
    this->boxes[pos].lowCorner = lowCorner;
    this->boxes[pos].highCorner = highCorner;
  }

  void		Box::setBoxesInside()
  {
    this->boxes = new Box[8];
    /*
      0->en bas à gauche devant
      1->en bas à gauche derriere
      2->en bas à droite devant
      3->en bas à droite derriere
      4-> meme hose en haut
    */
    double	width = abs(this->lowCorner.getY() - this->highCorner.getY()) / 2;
    double	height = abs(this->lowCorner.getZ() - this->highCorner.getZ()) / 2;
    double	depth = abs(this->lowCorner.getX() - this->highCorner.getX()) / 2;
    double	p[3];
    Tools::Vector	lowCorner;
    p[0] = this->lowCorner.getX();
    p[1] = this->lowCorner.getY();
    p[2] = this->lowCorner.getZ();

    lowCorner = this->lowCorner;
    this->setSmallBox(lowCorner, 0, width, height, depth);
    lowCorner.setValues(p[0] + depth, p[1], p[2]);
    this->setSmallBox(lowCorner, 1, width, height, depth);
    lowCorner.setValues(p[0], p[1] + width, p[2]);
    this->setSmallBox(lowCorner, 2, width, height, depth);
    lowCorner.setValues(p[0] + depth, p[1] + width, p[2]);
    this->setSmallBox(lowCorner, 3, width, height, depth);
    lowCorner.setValues(p[0], p[1], p[2] + height);
    this->setSmallBox(lowCorner, 4, width, height, depth);
    lowCorner.setValues(p[0] + depth, p[1], p[2] + height);
    this->setSmallBox(lowCorner, 5, width, height, depth);
    lowCorner.setValues(p[0], p[1] + width, p[2] + height);
    this->setSmallBox(lowCorner, 6, width, height, depth);
    lowCorner.setValues(p[0] + depth, p[1] + width, p[2] + height);
    this->setSmallBox(lowCorner, 7, width, height, depth);
  }

  // Return dist from ray;
  // ray.inversed, ray.origin and both corners must be set
  double	Box::collide(Engine::Ray *ray)
  {
    Tools::Vector	v = ray->getInversed();
    Tools::Vector	t1;
    Tools::Vector	t2; // c'est pas genre super con de déclarer ça sous forme de classe ? il y a 0 interet
    double	tmax;
    double	tmin;

    if ((v.getY() > -ALMOST_ZERO && v.getY() < ALMOST_ZERO) ||
	(v.getZ() > -ALMOST_ZERO && v.getZ() < ALMOST_ZERO) ||
	(v.getX() > -ALMOST_ZERO && v.getX() < ALMOST_ZERO))
      return (1);
    t1.setX((this->lowCorner.getX() - ray->getOrigin().getX()) * v.getX());
    t1.setY((this->highCorner.getX() - ray->getOrigin().getX()) * v.getX());
    t1.setZ((this->lowCorner.getY() - ray->getOrigin().getY()) * v.getY());
    t2.setX((this->highCorner.getY() - ray->getOrigin().getY()) * v.getY());
    t2.setY((this->lowCorner.getZ() - ray->getOrigin().getZ()) * v.getZ());
    t2.setZ((this->highCorner.getZ() - ray->getOrigin().getZ()) * v.getZ());
    tmin = fmax(fmax(fmin(t1.getX(), t1.getY()), fmin(t1.getZ(), t2.getX())), fmin(t2.getY(), t2.getZ()));
    tmax = fmin(fmin(fmax(t1.getX(), t1.getY()), fmax(t1.getZ(), t2.getX())), fmax(t2.getY(), t2.getZ()));
    if (tmax < -ALMOST_ZERO)
      return (-1);
    if (tmin > tmax)
      return (-1);
    return (tmin);



    // HEY J'AI TROUVE UNE OPTI DE CE CODE :) je la code sans encapsulation parce que ça me pete les couilles

<<<<<<< HEAD
    // à tester, vérifier, toussa toussa mais ça me parrait bien.
    /*    double	min[3];
	  double	max[3];
=======
      // à tester, vérifier, toussa toussa mais ça me parrait bien.

	// en fait ça marche pas ><
    /*double	min[3];
      double	max[3];
>>>>>>> 6f304620d7c266bd89ae9121eed8bacaef6dd6c3

	  if (r->getInversed().getX() >= 0)
	  {
	  min[0] = this->lowCorner.getX() -
	  r->getOrigin().getX() * r->getInversed().getX();
	  max[0] = this->highCorner.getX() -
	  r->getOrigin().getX() * r->getInversed().getX();
	  }
	  else
	  {
	  min[0] = this->highCorner.getX() -
	  r->getOrigin().getX() * r->getInversed().getX();
	  max[0] = this->lowCorner.getX() -
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
	  min[1] = this->highCorner.getY() -
	  r->getOrigin().getY() * r->getInversed().getY();
	  max[1] = this->lowCorner.getY() -
	  r->getOrigin().getY() * r->getInversed().getY();
	  }
	  printf("%f\n", r->getInversed().getY());
	  //    exit(1);
	  if (min[0] > max[1] || min[1] > max[0])
	  return (-1);
	  printf("je suis là\n");
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
      if (!boxes)
	delete boxes;
    }
  }
