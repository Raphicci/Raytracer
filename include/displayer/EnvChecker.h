/*
** EnvChecker.h for prototype in /home/vasseu_g/rendu/prototype
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun 18 21:08:55 2015 Adrien Vasseur
** Last update Thu Nov 12 20:48:23 2015 Adrien Vasseur
*/

#ifndef		ENVCHECKER_H_
# define	ENVCHECKER_H_

# include	<iostream>

# include	<X11/Xlib.h>

namespace	Displayer
{
  class		EnvChecker
  {
  public:
    static bool	hasXEnv();
  };
};

#endif		/* !ENVCHECKER_H_ */
