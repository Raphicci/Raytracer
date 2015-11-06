/*
** EnvChecker.cpp for prototype in /home/vasseu_g/rendu/prototype
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun 18 21:12:26 2015 Adrien Vasseur
** Last update Thu Jun 18 21:16:12 2015 Adrien Vasseur
*/

#include	"displayer/EnvChecker.h"

namespace	Displayer
{
  bool		EnvChecker::hasXEnv()
  {
    Display	*disp;

    if (!(disp = XOpenDisplay(NULL)))
      {
	std::cerr << "Failed to open X11 display; make sure the DISPLAY environment variable is set correctly\n";
	return (false);
      }
    XCloseDisplay(disp);
    return (true);
  }
};
