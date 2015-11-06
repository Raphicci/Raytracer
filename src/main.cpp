/*
** main.cpp for prototype in /home/vasseu_g/rendu/prototype
**
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
**
** Started on  Thu Jun 18 17:44:25 2015 Adrien Vasseur
** Last update Fri Nov  6 16:42:22 2015 Antoine Lempereur
*/

#include	<SFML/Graphics.hpp>
#include	<vector>
#include	<iostream>
#include	"Window_Config.h"
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
