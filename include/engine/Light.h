/*
** light.h for raytracer in /home/descam_d/workspace/Raytracer/include/engine
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Sat Nov  7 13:21:40 2015 Corentin Descamps
** Last update Wed Nov 11 17:21:19 2015 Corentin Descamps
*/

#ifndef			LIGHT_H_
# define		LIGHT_H_

# include		"tools/Vector.h"
# include		"tools/Color.h"

namespace		Engine
{
  class			Light
  {
  public:
    Light();
    Light(Tools::Vector position, Tools::Color light);
    ~Light();
    Tools::Vector*	getPosition();
    Tools::Color*	getColor();

  private:
    Tools::Vector	*position;
    Tools::Color	*color;
  };
}

#endif		/* !LIGHT_H_ */
