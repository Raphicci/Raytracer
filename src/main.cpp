/*
** main.cpp for prototype in /home/vasseu_g/rendu/prototype
**
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
**
** Started on  Thu Jun 18 17:44:25 2015 Adrien Vasseur
** Last update Sat Nov  7 17:28:10 2015 Antoine Lempereur
*/

#include	"displayer/Window.h"
#include	"displayer/EnvChecker.h"
#include	"tools/Vector.h"

int				main()
{
  Displayer::Window		*m_window;
  Tools::Vector			*vector1;
  Tools::Vector			*vector2;

  vector1 = new Tools::Vector(1, 1, 1);
  vector2 = new Tools::Vector(1, 0, 0);
  printf("%f\n", vector1->scalar(*vector2));
  vector1->normalize();
  printf("%f\n", vector1->getX());
  if (Displayer::EnvChecker::hasXEnv())
    {
      m_window = new Displayer::Window;
      m_window->loop();
    }
  return (0);
}
