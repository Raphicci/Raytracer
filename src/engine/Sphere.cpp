/*
** Sphere.cpp for Mabite in /home/thieba_r/Documents/GITHUB/Raytracer/src/engine
** 
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
** 
** Started on  Wed Nov 11 16:02:34 2015 Raphael Thiebault
** Last update Wed Nov 11 16:02:36 2015 Raphael Thiebault
*/

#include "tools/Vector.h"
#include "engine/Object.h"
#include "engine/Rayon.h"	

# define	EYEX	0
# define	EYEY	0
# define	EYEZ	0
# define	MIN(x1, x2)	((x1 > x2 && x2 > 0) ? x2 : x1)


namespace		Engine
{
  class			Sphere : public Object
  {
  public:

    Sphere()
    {

    }

    ~Sphere()
    {

    }

    float collide(Rayon const * ray)
    {
    	double	equ[3];
		double	delta;

		equ[0] = ray.getX() * ray.getX() + ray.getY() * ray.getY() + ray.getZ() * ray.getZ();
	    equ[1] = 2 * (EYEX * ray.getX() + EYEY * ray.getY() + EYEZ * ray.getZ());
		equ[2] = EYEX * EYEX + EYEY * EYEY + EYEZ * EYEZ - this.getRay() * this.getRay();
		if ((delta = equ[1] * equ[1] - 4 * equ[0] * equ[2]) >= 0)
			return  MIN((-equ[1] - sqrt(delta)) / (2 * equ[0]), (-equ[1] + sqrt(delta)) / (2 * equ[0])));
		else
	    	return -2.0;
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

    Tools::Vector getNormal(Rayon const * ray)
    {
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
    
    Tools::Vector getShadow(Rayon const *)
    {

    }

    Sphere setRay(double rayon)
    {
    	this->ray = rayon;

    	return this;
    }

    double getRay()
    {
    	return this->ray;

    }

  private:

  	double ray;

  };
}