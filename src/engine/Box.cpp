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

	double	Box::collide(Engine::Ray const& ray) 
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



  // HEY J'AI TROUVE UNE OPTI DE CE CODE :) je la code sans encapsulation parce que ça me pete les couilles

  // à tester, vérifier, toussa toussa mais ça me parrait bien.
  double	min[3];
  double	max[3];

  if (ray.inversed.x >= 0) 
  {
	  min[0] = this->lowCorner.x - r.origin.x * ray.inversed.x;
	  max[0] = this->highCorner.x - r.origin.x * ray.inversed.x;
  }
  else
  {
  	  max[0] = this->lowCorner.x - r.origin.x * ray.inversed.x;
	  min[0] = this->highCorner.x - r.origin.x * ray.inversed.x;
  }
  if (ray.inversed.y >= 0) 
  {
	  min[1] = this->lowCorner.y - r.origin.y * ray.inversed.y;
	  max[1] = this->highCorner.y - r.origin.y * ray.inversed.y;
  }
  else
  {
  	  max[1] = this->lowCorner.y - r.origin.y * ray.inversed.y;
	  min[1] = this->highCorner.y - r.origin.y * ray.inversed.y;
  }
  if (min[0] > max[1] || min[1] > max[0])
	  return (-1);
  if (min[1] > min[0])
	  min[0] = min[1];
  if (max[1] < max[0])
	  max[0] = max[1];  
  if (ray.inversed.z >= 0) 
  {
	  min[2] = this->lowCorner.z - r.origin.z * ray.inversed.z;
	  max[2] = this->highCorner.z - r.origin.z * ray.inversed.z;
  }
  else
  {
  	  max[2] = this->lowCorner.z - r.origin.z * ray.inversed.z;
	  min[2] = this->highCorner.z - r.origin.z * ray.inversed.z;
  }
  if (min[0] > max[2] || min[2] > max[0])
	  return (-1);
  if (min[2] > min[0])
	  min[0] = min[2];
  if (max[2] < max[0])
	  max[0] = max[2];  
  return (min[0]);
	}

	bool	Box::isInsideBox(Engine::Box const& box) 
	{
		
	}

	Box::~Box() 
	{
		
	}
}