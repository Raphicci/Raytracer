/*
** Color.h for raytracer in /home/lemper_a/rendu/raytracer/Raytracer/include/tools
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Sun Nov  8 10:16:27 2015 Antoine Lempereur
** Last update Mon Nov  9 16:48:09 2015 Antoine Lempereur
*/


#ifndef		COLOR_H_
# define	COLOR_H_

# include	<iostream>
# include	<exception>

# include	<SFML/Graphics/Color.hpp>

namespace	Tools
{
  class		Color// : sf::Color
  {
  public:
    Color();
    Color(int r, int g, int b);
    int		getR();
    int		getG();
    int		getB();
    void	setR(int value);
    void	setG(int value);
    void	setB(int value);
    void	Mix(Color const&);
    void	Mix();// vecteurs;
    //void	Mix(); Liste
    void	PreventOverflow();
    ~Color();
  private:
    int		r;
    int		g;
    int		b;
  };
}

#endif
