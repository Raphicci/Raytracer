/*
** Sphere.h for azer in /home/lemper_a/rendu/Raytracer
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Fri Nov 20 16:45:08 2015 Antoine Lempereur
** Last update Sat Nov 21 20:40:23 2015 Antoine Lempereur
*/

//tamere raphi je suis obligé de faire un .h pour que ça compile

#ifndef		SPHERE_H_
# define	SPHERE_H_

# include	"engine/Object.h"
# include	"tools/Vector.h"
# include	"engine/Box.h"

namespace	Engine
{
  class		Sphere : public Object
  {
  public:
    Sphere();
    Sphere(Tools::Vector, Tools::Vector, Tools::Color, double);
    ~Sphere();
    float		collide(Ray *);
    Tools::Vector	getNormal(Tools::Vector);
    Sphere		*setRay(double);
    double		getRay();
    void		setBox();

  private:
    double		ray;
  };
};

#endif
