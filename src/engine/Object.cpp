/*
** Object.cpp for raytracer in /home/lemper_a/rendu/Raytracer/src
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Fri Nov 20 17:00:28 2015 Antoine Lempereur
** Last update Sat Nov 21 20:42:41 2015 Antoine Lempereur
*/

# include	"tools/Vector.h"
# include	"engine/Object.h"
# include	"tools/Color.h"
# include	"engine/Box.h"

namespace		Engine
{
  Object::Object()
  {
    this->position.setValues(0, 0, 0);
    this->rotation.setValues(0, 0, 0);
    this->color.setRGB(255, 255, 255);
  }

  Tools::Vector	Object::getPosition()
  {
    return (this->position);
  }

  Tools::Vector	Object::getRotation()
  {
    return (this->rotation);
  }

  Tools::Color	Object::getColor()
  {
    return (this->color);
  }

  Box		Object::getBox()
  {
    return (this->box);
  }

  Object::~Object()
  {

  }
};
