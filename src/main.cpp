/*
** main.cpp for prototype in /home/vasseu_g/rendu/prototype
**
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
**
** Started on  Thu Jun 18 17:44:25 2015 Adrien Vasseur
** Last update Wed Nov 11 15:11:28 2015 Antoine Lempereur
*/

#include	"displayer/Window.h"
#include	"displayer/EnvChecker.h"
#include	"tools/Vector.h"
#include	"tools/Color.h"
#include	"engine/Ray.h"
#include	"const.h"

using namespace	Tools;

int				main()
{
  Displayer::Window		*m_window;
  Vector			origin(0, 0, 0);
  Vector			direction(1, 0, 0);
  Engine::Ray			ray(origin, direction);

  printf("%f\n", 1 / ANTI_FISH_EYE_VALUE);
  if (Displayer::EnvChecker::hasXEnv())
    {
      m_window = new Displayer::Window;
      m_window->loop();
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}
