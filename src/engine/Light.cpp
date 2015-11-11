//
// Light.cpp for raytracer in /home/descam_d/workspace/Raytracer/src
// 
// Made by Corentin Descamps
// Login   <descam_d@epitech.net>
// 
// Started on  Sat Nov  7 13:25:49 2015 Corentin Descamps
// Last update Wed Nov 11 17:58:15 2015 Corentin Descamps
//

#include	"engine/Light.h"
#include	"tools/Vector.h"
#include	"tools/Color.h"

namespace	Engine
{
  Light::Light()
  {
    this->position = new Tools::Vector(0, 0, 0);
    this->color = new Tools::Color(0, 0, 0);
  }

  Light::Light(Tools::Vector position, Tools::Color color)
  {
    this->position = new Tools::Vector(position);
    this->color = new Tools::Color(color);
  }

  Light::~Light()
  {
    delete this->position;
    delete this->color;
  }

  Tools::Vector*	Light::getPosition()
  {
    return (this->position);
  }

  Tools::Color*		Light::getColor()
  {
    return (this->color);
  }

};
