/*
** main.cpp for prototype in /home/vasseu_g/rendu/prototype
**
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
**
** Started on  Thu Jun 18 17:44:25 2015 Adrien Vasseur
** Last update Thu Nov 12 17:15:35 2015 Antoine Lempereur
*/

#include	"displayer/Window.h"
#include	"displayer/EnvChecker.h"
#include	"tools/Vector.h"
#include	"tools/Color.h"
#include	"engine/Ray.h"
#include	"const.h"

int				main()
{
  Displayer::Window		*m_window;
  Tools::Vector			v1(2, 2, 2);
  Tools::Vector			v2(1, 1, 1);

  v1 = v1 + v2;
  printf("%f\n", v1.getZ());
  if (Displayer::EnvChecker::hasXEnv())
    {
      m_window = new Displayer::Window;
      m_window->loop();
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}
