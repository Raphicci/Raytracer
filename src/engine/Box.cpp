//REFAIRE HEADER

#include	<math.h>

#include "tools/Vector.h"
#include "engine/Object.h"
#include "engine/Rayon.h"	


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

	double	Collide(Engine::Ray const& ray) 
	{
		Tools::Vector	v = ray.getInversed();
		Tools::Vector	t1;
		Tools::Vector	t2; // c'est pas genre super con de déclarer ça sous forme de classe ? il y a 0 interet
  double	tmax;
  double	tmin;

  t1.setX((this->lowCorner.getX() - ray.getOrigin().getX()) * v.getX());
  t1.setY((this->highCorner.getX() - ray.getOrigin().getX()) * v.getX());
  t1.setZ((this->lowCorner.getY() - ray.getOrigin().getY()) * v.getY());
  t2.setX((this->highCorner.getY() - ray.getOrigin().getY()) * v.getY());
  t2.setY((this->lowCorner.getZ() - ray.getOrigin().getZ()) * v.getZ());
  t2.setZ((this->highCorner.getZ() - ray.getOrigin().getZ()) * v.getZ());
  tmin = fmax(fmax(fmin(t1.getX(), t1.getY()), fmin(t1.getZ(), t2.getX())), fmin(t2.getY(), t2.getZ()));
  tmax = fmin(fmin(fmax(t1.getX(), t1.getY()), fmax(t1.getZ(), t2.getX())), fmax(t2.getY(), t2.getZ()));
  if (tmax < 0.0)
    return (-1);
  if (tmin > tmax)
    return (-1);
  return (tmin);
	}

	Box::~Box() 
	{
		
	}
}