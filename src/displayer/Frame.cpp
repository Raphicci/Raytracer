/*
** Frame.cpp for raytracer in /home/lemper_a/rendu/Raytracer
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Wed Nov 18 16:40:47 2015 Antoine Lempereur
** Last update Sat Nov 21 15:51:56 2015 Antoine Lempereur
*/

#include	"displayer/Frame.h"

namespace	Displayer
{
  Frame::Frame()
  {

  }

  Frame::Frame(sf::Uint8 *pixels, float *dist,
	       unsigned int width, unsigned int height)
  {
    this->texture.create(width, height);
    this->texture.update(pixels);
    this->sprite.setTexture(this->texture);
    this->dist = dist;
  }

  sf::Sprite	Frame::getSprite()
  {
    return (this->sprite);
  }

  void	Frame::setDist(float *dist)
  {
    this->dist = dist;
  }

  unsigned int	Frame::getFramePos()
  {
	  return (this->framePos);
  }

  /*  void	Frame::setMotionBlur(Frame const& nextFrame) // ou une list de frame si on fait le blur sur plusieurs images (d'ailleurs plus le nombre de FPS est important plus le nombre d'image dont il faut faire la moyenne est important)
  {
    unsigned int	x;
    unsigned int	y;
    sf::Vector2u size = this->texture.getSize();
    sf::Color		previousColor;
    sf::Color		nextColor;

    x = 0;
    while (x < size.x)
      {
	while (y < size.y)
	  {
	    previousColor = this->image.getPixel(x, y);
	    nextColor = nextFrame.image.getPixel(x, y);
	    this->motionBlurImage.setPixel(x, y, Tools::Color::MixSfColor(previousColor, nextColor)); // l'image est déjà allouée dans le constructeur ?
	    y++;
	  }
	x++;
	}
  }*/

  Frame::~Frame()
  {

  }
};
