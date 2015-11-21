/*
** Window.h for prototype in /home/zanard_a/rendu/Projets_TEK1/prototype/displayer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Jun 11 11:52:31 2015 Antoine Zanardi
** Last update Fri Nov 20 16:31:34 2015 Antoine Lempereur
*/

#ifndef				WINDOW_H_
# define			WINDOW_H_

# include			<iostream>
# include			<exception>

# include			<vector>

# include			<SFML/Window.hpp>
# include			<SFML/Graphics.hpp>

# include			"Window_Config.h"
# include			"displayer/Frame.h"

namespace			Displayer
{
  class				Frame;

  class				Window
  {
  public:
    Window();
    ~Window();

    void			loop();
    void			handleEvents();
    void			loop(Displayer::Frame);
    void			loop(std::vector<Displayer::Frame>, int); // go laisser à l'user le choix des FPS

  private:
    sf::RenderWindow		*window;
    Displayer::Window_Config	*config;
  };
};

#endif				/* !WINDOW_H_ */
