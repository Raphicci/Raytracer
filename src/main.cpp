/*
** main.cpp for prototype in /home/vasseu_g/rendu/prototype
**
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
**
** Started on  Thu Jun 18 17:44:25 2015 Adrien Vasseur
** Last update Fri Nov  6 17:28:08 2015 Adrien Vasseur
*/

#include	"displayer/Window.h"
#include	"displayer/EnvChecker.h"

int				main()
{
  Displayer::Window		*m_window;

  if (Displayer::EnvChecker::hasXEnv())
    {
      m_window = new Displayer::Window;
      m_window->loop();
    }
  return (0);
}
