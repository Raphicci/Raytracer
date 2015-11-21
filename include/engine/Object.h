/*
** Object.h for Mabite in /home/thieba_r/Documents/GITHUB/Raytracer
** 
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
** 
** Started on  Wed Nov 11 15:06:39 2015 Raphael Thiebault
** Last update Sat Nov 21 15:55:22 2015 Antoine Lempereur
*/

#ifndef			OBJECT_H_
# define		OBJECT_H_

#include	"tools/Vector.h"
#include	"tools/Color.h"
#include	"engine/Ray.h"

namespace		Engine
{
  class			Ray; // Circular inclusion

  class			Object
  {
  public:
    Object();
    ~Object();

    virtual float collide(Engine::Ray *) = 0;
    Tools::Vector	getPosition();
    Tools::Vector	getRotation();
    Tools::Color	getColor();
    //virtual Tools::Vector getNormal(Engine::Ray const *) = 0;
    //virtual Tools::Vector getShadow(Engine::Ray const *) = 0;

  protected:
    Tools::Vector position;
    Tools::Vector rotation;
    //Tools::Vector taille;
    Tools::Color color;
    //Tools:Texture texture;
    // les constantes : reflexion(une valeur pour l'intensité, une pour la précision) transparence(intensité, precision, indice de réfraction) vitesse(en unité/frame), brillance, specularite
  };
}

#endif
