/*
** main.cpp for prototype in /home/vasseu_g/rendu/prototype
**
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
**
** Started on  Thu Jun 18 17:44:25 2015 Adrien Vasseur
** Last update Mon Nov  9 17:22:31 2015 Antoine Lempereur
*/

#include	"displayer/Window.h"
#include	"displayer/EnvChecker.h"
#include	"tools/Vector.h"
#include	"tools/Color.h"

int				main()
{
  Displayer::Window		*m_window;
  Tools::Color			c(510, 255, 255);
  Tools::Color			toMix(0, 0, 0); // quand je met rien au lieu de set à 0 r est set à une valeur yolo, pourquoi ? 

  c.PreventOverflow();
  printf("%d %d %d\n", c.getR(), c.getG(), c.getB());
  c.Mix(toMix);
  printf("%d %d %d\n", c.getR(), c.getG(), c.getB());
  if (Displayer::EnvChecker::hasXEnv())
    {
      m_window = new Displayer::Window;
      m_window->loop();
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}
