/*
** Window.h for prototype in /home/zanard_a/rendu/Projets_TEK1/prototype/displayer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Jun 11 11:52:31 2015 Antoine Zanardi
** Last update Fri Nov  6 17:24:53 2015 Adrien Vasseur
*/

#ifndef				WINDOW_H_
# define			WINDOW_H_

# include			<iostream>
# include			<exception>

# include			<SFML/Window.hpp>
# include			<SFML/Graphics.hpp>

# include			"Window_Config.h"

namespace			Displayer
{
  class				Window
  {
  public:
    Window();
    ~Window();

    void			loop();

  private:
    sf::RenderWindow		*window;
    Displayer::Window_Config	*config;
  };
};

#endif				/* !WINDOW_H_ */
