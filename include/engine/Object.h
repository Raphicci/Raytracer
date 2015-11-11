/*
** Object.h for Mabite in /home/thieba_r/Documents/GITHUB/Raytracer
** 
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
** 
** Started on  Wed Nov 11 15:06:39 2015 Raphael Thiebault
** Last update Wed Nov 11 19:22:06 2015 Antoine Lempereur
*/

#ifndef			OBJECT_H_
# define		OBJECT_H_

#include	"tools/Vector.h"
#include	"tools/Color.h"
#include	"engine/Ray.h"

namespace		Engine
{
  class			Object
  {
  public:

    Object()
    {

    }

    ~Object()
    {

    }

    virtual float Collide(Engine::Ray const *);
    virtual Tools::Vector getNormal(Engine::Ray const *);
    virtual Tools::Vector getShadow(Engine::Ray const *);

  private:

  	Tools::Vector position;
  	Tools::Vector rotation;
  	//Tools::Vector taille; 
    Tools:Color color;
    //Tools:Texture texture;

  };
}

#endif
