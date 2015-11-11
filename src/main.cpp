/*
** main.cpp for prototype in /home/vasseu_g/rendu/prototype
**
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
**
** Started on  Thu Jun 18 17:44:25 2015 Adrien Vasseur
** Last update Wed Nov 11 19:00:32 2015 Antoine Lempereur
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

  if (Displayer::EnvChecker::hasXEnv())
    {
      m_window = new Displayer::Window;
      m_window->loop();
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}
