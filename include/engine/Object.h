/*
** Object.h for Mabite in /home/thieba_r/Documents/GITHUB/Raytracer
** 
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
** 
** Started on  Wed Nov 11 15:06:39 2015 Raphael Thiebault
** Last update Sat Nov 21 20:40:37 2015 Antoine Lempereur
*/

#ifndef			OBJECT_H_
# define		OBJECT_H_

#include	"tools/Vector.h"
#include	"tools/Color.h"
#include	"engine/Ray.h"
#include	"engine/Box.h"

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
    Box			getBox();
    virtual Tools::Vector getNormal(Tools::Vector) = 0;
    //virtual Tools::Vector getShadow(Engine::Ray const *) = 0;

  protected:
    Tools::Vector	position;
    Tools::Vector	rotation;
    //Tools::Vector taille;
    Tools::Color	color;
    Box			box;
    //Tools:Texture texture;
    // les constantes : reflexion(une valeur pour l'intensit�, une pour la pr�cision) transparence(intensit�, precision, indice de r�fraction) vitesse(en unit�/frame), brillance, specularite
  };
}

#endif
