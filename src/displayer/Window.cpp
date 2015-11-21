/*
** Window.cpp for prototype in /home/vasseu_g/rendu/prototype
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun 18 17:01:24 2015 Adrien Vasseur
** Last update Fri Nov 20 16:33:14 2015 Antoine Lempereur
*/

# include	<sys/time.h>
# include	<vector>
# include	<stdlib.h>
# include	"displayer/Window.h"
# include	"displayer/Frame.h"

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

  void		Window::handleEvents()
  {
	  sf::Event	event;

	while (this->window->pollEvent(event))
	  {
	    if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
	      this->window->close();
	  }
  }

  void		Window::loop(Displayer::Frame frame)
  {
	while (this->window->isOpen())
	{
		this->handleEvents();
		this->window->clear();
		this->window->draw(frame.getSprite());
		this->window->display();
	}
  }

  void		Window::loop(std::vector<Displayer::Frame> frames, int frequency)
  {
	static unsigned int	i = 0;
	static int	wait = 1000000 / frequency; // c'est pas une grosse opti parce que ça arrive après tous les calculs, mais quand même
	static struct timeval	old;
	struct timeval			value;

	if (old.tv_usec == 0)
		gettimeofday(&old, NULL);
	while (this->window->isOpen())
	{
		this->handleEvents();
		gettimeofday(&value, NULL);
		this->window->clear();
		this->window->draw(frames[i].getSprite());
		this->window->display();
		// le truc en dessous c'est le vieux systeme mais je crois qu'il est mauvais lorsqu'il y a chgmt de secondes (a test)
		if (value.tv_usec > old.tv_usec + wait || value.tv_sec > old.tv_sec) // && pas de pause
			i++;
		if (i == frames.size())
			i = 0;
		gettimeofday(&old, NULL);
	}
  }
};
