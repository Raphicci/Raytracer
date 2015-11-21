/*
** Sphere.cpp for Mabite in /home/thieba_r/Documents/GITHUB/Raytracer/src/engine
**
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
**
** Started on  Wed Nov 11 16:02:34 2015 Raphael Thiebault
** Last update Sat Nov 21 19:51:20 2015 Antoine Lempereur
*/

# include	"tools/Vector.h"
# include	"engine/Object.h"
# include	"engine/Ray.h"
# include	"engine/Sphere.h"

# define	MIN(x1, x2)	((x1 > x2 && x2 > 0) ? x2 : x1)


namespace		Engine
{
  Sphere::Sphere()
  {
    this->position.setValues(0, 0, 0);
    this->rotation.setValues(0, 0, 0);
    this->color.setRGB(255, 255, 255);
    this->ray = 10;
  }

  Sphere::Sphere(Tools::Vector position, Tools::Vector rotation, Tools::Color color, double ray)
  {
    this->position = position;
    this->rotation = rotation;
    this->color = color;
    this->ray = ray;
  }

  Sphere::~Sphere()
  {

  }

  float		Sphere::collide(Ray *ray)
  {
    double	equ[3];
    double	delta;

    //je croyais qu'on pouvait opti ça mais en fait non, à cause de la pos simple
    equ[0] = ray->getDirection().getX() * ray->getDirection().getX() +
      ray->getDirection().getY() * ray->getDirection().getY() +
      ray->getDirection().getZ() * ray->getDirection().getZ();
    equ[1] = 2 * (ray->getOrigin().getX() * ray->getDirection().getX() +
		  ray->getOrigin().getY() * ray->getDirection().getY() +
		  ray->getOrigin().getZ() * ray->getDirection().getZ());
    equ[2] = ray->getOrigin().getX() * ray->getOrigin().getX() +
      ray->getOrigin().getY() * ray->getOrigin().getY() +
      ray->getOrigin().getZ() * ray->getOrigin().getZ() -
      this->getRay() * this->getRay(); // hey cette ligne est toujours la même pour tous les rayons ayant la même origine, go trouver un moyen de précalculer !
    if ((delta = equ[1] * equ[1] - 4 * equ[0] * equ[2]) >= 0)
      {
	double root = sqrt(delta); // Grosse grosse optimisation !
	double diviser = 2 * equ[0];
	return  MIN((-equ[1] - root) / diviser, (-equ[1] + root) / diviser);
      }
    else
      return (-2.0);
    /*{
      if ((k = MIN((-equ.y - sqrt(delta)) / (2 * equ.x), (-equ.y + sqrt(delta)) / (2 * equ.x))) >= 0)
      {
      d->inter = get_inter(&d->eye_pos_n, *k, &d->v_pos_n);
      if (d->inter.x < o->lim.bot.x || d->inter.x > o->lim.top.x
      || d->inter.y < o->lim.bot.y || d->inter.y > o->lim.top.y
      || d->inter.z < o->lim.bot.z || d->inter.z > o->lim.top.z)
      check_lim(MAX((-equ.y - sqrt(delta)) / (2 * equ.x),
      (-equ.y + sqrt(delta)) / (2 * equ.x)), o, d, k);
      }
      }*/

  }

  Tools::Vector getNormal(Ray *ray)
  {
    Tools::Vector	v;

    v.setX(ray->getIntersection().getX()); // bien faire gaffe à ce que l'intersection soit bien celle en position simple à ce moment
    v.setY(ray->getIntersection().getY());
    v.setZ(ray->getIntersection().getZ());
    return (v);

    /*if (!(d->inter.is_sec))
      {*/
    //norm->x = ray.getInter().getX();
    //norm->y = d->inter.y;
    //norm->z = d->inter.z;
    /*}
      else
      {
      norm->x = -(d->inter.x);
      norm->y = -(d->inter.y);
      norm->z = -(d->inter.z);
      }*/
    //go_derotate(&norm->x, &norm->y, &norm->z, &d->obj->rot);
    //normalise(norm);
  }

  /*    Tools::Vector getShadow(Ray const *)
	{

	}*/

  Sphere *Sphere::setRay(double ray)
  {
    this->ray = ray;

    return this;
  }

  double Sphere::getRay()
  {
    return this->ray;
  }
};
