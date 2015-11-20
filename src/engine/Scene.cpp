/*
** Scene.cpp for Raytracer in /home/vasseu_g/github/Raytracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Nov 12 20:38:27 2015 Adrien Vasseur
** Last update Wed Nov 18 17:30:52 2015 Antoine Lempereur
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
	//test
	Engine::Sphere	*sphere;

	sphere = new Engine::Sphere();
    this->height = 200;
    this->width = 200;
	this->origin.setValues(-300, 0, 0);
	this->rotation.setValues(0, 0, 0);
	this->objects.push_back(sphere);

	// fin test

    m_parser = new Parser::SceneParser;
    if (!Displayer::EnvChecker::hasXEnv())
      return (false);
    m_window = new Displayer::Window;
    return (true);
  }

  /*Tools::Vector	Scene::getOrigin() 
  {
	  return (this->origin);
  }

  Tools::Vector	Scene::getRotation() 
  {
	  return (this->rotation);
  }

  std::vector<Engine::Object *>	Scene::getObjects() 
  {
	  return (this->objects);
  }*/

  void		Scene::run()
  {
    // je pense pas qu'il faille lancer le loop et faire les calculs dans la même fonction mais on verra plus tard
    double i = 0;
    double j = 0;
    sf::Uint8 *pixels = new sf::Uint8[this->width * this->height * 4];
    float	*dist = new float[this->width * this->height];
    int		pos;
	int		sizeLine = this->width * 4;
	int		positionY;
	int		positionDistY;

    while (i < this->width)
      {
	j = 0;
	positionY = i * sizeLine;
	positionDistY = i * this->width;
	while (j < this->height)
	  {
	    pos = positionY + j * 4;
	    Engine::Ray	ray(i, j, this); // c'est légal ça ?  si c'est pas légal go tout mettre à nul dans le constructeur et faire des méthodes init
	    ray.compute(this);
	    dist[positionDistY + j] = ray.getDist();
	    pixels[pos] = ray.getColor().getR();
		pixels[pos + 1] = ray.getColor().getG();
		pixels[pos + 2] = ray.getColor().getB();
		pixels[pos + 3] = 255;
	    /*pixels[pos] = 255;
	    pixels[pos + 1] = 255; // go checker l'ordre, dans la minilibX c'etait inversé ça l'est peut etre aussi ici
	    pixels[pos + 2] = 255;
	    pixels[pos + 3] = 255;*/
	    j++;
	  }
	i++;
      }
    Displayer::Frame frame(pixels, dist, this->width, this->height);
    m_window->loop(frame); // l'idée serait d'envoyer à loop toutes les frames
    //m_window->loop();
  }
};
