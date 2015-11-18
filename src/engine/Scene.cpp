/*
** Scene.cpp for Raytracer in /home/vasseu_g/github/Raytracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Nov 12 20:38:27 2015 Adrien Vasseur
** Last update Thu Nov 12 21:02:09 2015 Adrien Vasseur
*/

#include	"engine/Scene.h"

namespace	Engine
{
  Scene::Scene()
  {
    m_parser = NULL;
    m_window = NULL;
  }

  Scene::~Scene()
  {
    if (!m_parser)
      delete m_parser;
    if (!m_window)
      delete m_window;
  }

  bool		Scene::init(int argv, char **argc)
  {
    m_parser = new Parser::SceneParser;
    if (!Displayer::EnvChecker::hasXEnv())
      return (false);
    m_window = new Displayer::Window;
    return (true);
  }

  void		Scene::run()
  {
	/*
	je pense pas qu'il faille lancer le loop et faire les calculs dans la même fonction
	
	double i = 0;
	double j = 0;
    sf::Uint8 *pixels = new sf::Uint8[this->width * this->height * 4];
	float	*dist = new float[this->width * this->height];

	while (i < this->width)
	{
		while (j < this->height)
		{
			Engine::Ray	ray(i, j, this); // c'est légal ça ?
			ray.compute(this);
			dist[j + i * sizeline] = ray.getDist();
			pixels[j + i * sizeline] = ray.getColor().getR();
			// pareil pour g et b, 0 pour a
			j++;
		}
		i++;
	}
	Display::Frame frame(pixels, dist);
	m_window->loop(frame)*/ // l'idée serait d'envoyer à loop toutes les frames
    m_window->loop();
  }
};
