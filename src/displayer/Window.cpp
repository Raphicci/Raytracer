/*
** Window.cpp for prototype in /home/vasseu_g/rendu/prototype
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun 18 17:01:24 2015 Adrien Vasseur
** Last update Mon Nov  9 16:14:59 2015 Adrien Vasseur
*/

#include	"displayer/Window.h"

namespace	Displayer
{
  Window::Window()
  {
    try
      {
	this->config = new Displayer::Window_Config;
	this->config->parseFile();
	if (this->config->get("fullscreen"))
	  this->window = new sf::RenderWindow(sf::VideoMode(config->get("width"), config->get("height")), "Prototype", sf::Style::Fullscreen);
	else
	  this->window = new sf::RenderWindow(sf::VideoMode(config->get("width"), config->get("height")), "Prototype");
      }
    catch (std::exception& e)
      {
	std::cout << e.what() << std::endl;
	exit(EXIT_FAILURE);
      }
  }

  Window::~Window()
  {
    delete this->window;
    delete this->config;
  }

  void		Window::loop()
    {
      sf::Event	event;

      while (this->window->isOpen())
	{
	  while (this->window->pollEvent(event))
	    {
	      if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
		this->window->close();
	    }
	  this->window->clear();
	  this->window->display();
	}
    }
};
