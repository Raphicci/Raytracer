/*
** Color.cpp for raytracer in /home/lemper_a/rendu/raytracer/Raytracer/src/tools
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Sun Nov  8 10:31:42 2015 Antoine Lempereur
** Last update Wed Nov 11 18:11:00 2015 Antoine Lempereur
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
  }

  void		Color::Mix(Color const& c)
  {
    this->r = (this->r + c.r) / 2;
    this->g = (this->g + c.g) / 2;
    this->b = (this->b + c.b) / 2;
  }

  void		Color::Mix(Color const& c, float coef)
  {
    this->r = this->r * (1 - coef) + c.r * coef;
    this->g = this->g * (1 - coef) + c.g * coef;
    this->b = this->b * (1 - coef) + c.b * coef;
  }

  sf::Color	Color::MixSfColor(sf::Color const& a, sf::Color const& b)
  {
	  sf::Color	col;
	  int r = (a.r + b.r) / 2;
	  int g = (a.g + b.g) / 2;
	  int b = (a.b + b.b) / 2;
	  col.r = (sf::Uint8)r;
	  col.g = (sf::Uint8)g;
	  col.b = (sf::Uint8)b;
	  col.a = 255;
	  return (col);
  }

  Color::~Color()
  {

  }
};
