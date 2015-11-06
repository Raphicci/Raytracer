/*
** Gui.h for prototype in /home/descam_d/Documents/prototype
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Tue Jun 16 10:47:14 2015 Corentin Descamps
** Last update Tue Jun 16 16:10:41 2015 Corentin Descamps
*/

#ifndef		GUI_H_
# define	GUI_H_

# include	<SFML/Window.hpp>
# include	<SFML/Graphics/Texture.hpp>
# include	<SFML/Graphics/Sprite.hpp>
# include	<stdio.h>
# include	<string>

namespace Displayer
{
  class	Gui
  {
  public:
    Gui();
    ~Gui();
    void		Button(sf::Vector2i globalPosition);
    void		resizeSprite(sf::Vector2u winSize);
    const sf::Sprite&	fond();

  private:
    sf::Texture texture;
    sf::Sprite	sprite;
  };
}

#endif		/* !GUI_H_ */
