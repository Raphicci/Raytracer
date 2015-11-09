/*
** Color.cpp for raytracer in /home/lemper_a/rendu/raytracer/Raytracer/src/tools
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Sun Nov  8 10:31:42 2015 Antoine Lempereur
** Last update Mon Nov  9 17:21:43 2015 Antoine Lempereur
*/

#include	"tools/Color.h"

namespace	Tools
{
  Color::Color()
  {
    Color(0, 0, 0);
  }

  Color::Color(int r, int g, int b)
  {
    this->r = r;
    this->g = g;
    this->b = b;
  }

  void	Color::setR(int value)
  {
    this->r = value;
  }

  void	Color::setG(int value)
  {
    this->g = value;
  }

  void	Color::setB(int value)
  {
    this->b = value;
  }

  int	Color::getR()
  {
    return (this->r);
  }

  int	Color::getG()
  {
    return (this->b);
  }

  int	Color::getB()
  {
    return (this->b);
  }

  void		Color::PreventOverflow()
  {
    float	scale = 0;

    if (this->r > this->b && this->r >= this->g && this->r > 255)
      scale = 255 / (float)this->r;
    else if (this->g > this->b && this->g >= this->r && this->g > 255)
      scale = 255 / (float)this->g;
    else if (this->b > this->r && this->b >= this->g && this->b > 255)
      scale = 255 / (float)this->b;
    else
      return;
    this->r *= scale;
    this->g *= scale;
    this->b *= scale;

    // à cause de l'héritage on peut pas dépasser 255 donc c'est un peu chiant donc go pas hériter
  }

  void		Color::Mix(Color const& c)
  {
    this->r = (this->r + c.r) / 2;
    this->g = (this->g + c.g) / 2;
    this->b = (this->b + c.b) / 2;
  }

  Color::~Color()
  {

  }
};
