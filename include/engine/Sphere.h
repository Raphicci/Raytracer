/*
** Sphere.h for azer in /home/lemper_a/rendu/Raytracer
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Fri Nov 20 16:45:08 2015 Antoine Lempereur
** Last update Fri Nov 20 17:49:27 2015 Antoine Lempereur
*/

//tamere raphi je suis obligé de faire un .h pour que ça compile

#ifndef		SPHERE_H_
# define	SPHERE_H_

# include	"engine/Object.h"
# include	"tools/Vector.h"

namespace	Engine
{
  class		Sphere : public Object
  {
  public:
    Sphere();
    ~Sphere();
    float		collide(Ray *);
    Tools::Vector	getNormal(Ray *);
    Sphere		*setRay(double);
    double		getRay();

  private:
    double		ray;
  };
};

#endif
