/*
** Window_Config.h for prototype in /home/zanard_a/rendu/Projets_TEK1/prototype
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Jun 11 12:20:51 2015 Antoine Zanardi
** Last update Tue Jun 16 13:36:36 2015 Antoine Lempereur
*/

#ifndef		WINDOW_CONFIG_H_
# define	WINDOW_CONFIG_H_

#include	<map>
#include	<fstream>
#include	<iostream>
#include	<stdio.h>
#include	<string>
#include	<string.h>
#include	<SFML/Window.hpp>

namespace	Displayer
{
  class		Window_Config
  {
  public:
    Window_Config();
    ~Window_Config();
    void		parseFile();
    void		createFile();
    int		get(std::string);

  private:
    std::map<std::string, int> parsing;
  };
};
#endif		/* !WINDOW_CONFIG_H_ */
