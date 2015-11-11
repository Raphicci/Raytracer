/*
** Object.h for Mabite in /home/thieba_r/Documents/GITHUB/Raytracer
** 
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
** 
** Started on  Wed Nov 11 15:06:39 2015 Raphael Thiebault
** Last update Wed Nov 11 15:07:13 2015 Raphael Thiebault
*/

#ifndef			OBJECT_H_
# define		OBJECT_H_

#include "tools/Vector.h"
#include "tools/Color.h"
#include "engine/Rayon.h"

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

    virtual float Collide(Rayon const *);
    virtual Tools::Vector getNormal(Rayon const *);
    virtual Tools::Vector getShadow(Rayon const *);

  private:

  	Tools::Vector position;
  	Tools::Vector rotation;
  	//Tools::Vector taille; 
    Tools:Color color;
    //Tools:Texture texture;

  };
}

#endif
