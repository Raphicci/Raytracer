/*
** Scene.cpp for Raytracer in /home/vasseu_g/github/Raytracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Nov 12 20:38:27 2015 Adrien Vasseur
** Last update Sat Nov 21 22:09:58 2015 Antoine Lempereur
*/

#include	"engine/Scene.h"
#include	"engine/Object.h"
#include	"engine/Sphere.h"

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
    Engine::Sphere	*sphere1;
    Engine::Sphere	*sphere2;
    Engine::Sphere	*sphere3;
    Engine::Sphere	*sphere4;

    sphere1 = new Engine::Sphere(Tools::Vector(0, 0, -50), Tools::Vector(0, 0, 0), Tools::Color(0, 255, 255), 10);
    sphere2 = new Engine::Sphere(Tools::Vector(0, 50, 0), Tools::Vector(0, 0, 0), Tools::Color(255, 255, 0), 10);
    sphere3 = new Engine::Sphere(Tools::Vector(0, -50, 0), Tools::Vector(0, 0, 0), Tools::Color(255, 0, 255), 10);
    sphere4 = new Engine::Sphere(Tools::Vector(0, 0, 50), Tools::Vector(0, 0, 0), Tools::Color(0, 0, 255), 10);
    this->height = 1080;
    this->width = 1920;
    this->origin.setValues(-700, 150, 100);
    this->rotation.setValues(0, 0, 0);
    this->objects.push_back(sphere1);
    this->objects.push_back(sphere2);
    this->objects.push_back(sphere3);
    this->objects.push_back(sphere4);
    // fin test

    m_parser = new Parser::SceneParser;
    if (!Displayer::EnvChecker::hasXEnv())
      return (false);
    m_window = new Displayer::Window;
    this->setBox();
    return (true);
  }

  Tools::Vector	Scene::getOrigin()
  {
	  return (this->origin);
  }

  Tools::Vector	Scene::getRotation()
  {
	  return (this->rotation);
  }

  unsigned int	Scene::getWidth()
  {
    return (this->width);
  }

  unsigned int	Scene::getHeight()
  {
    return (this->height);
  }

  std::vector<Engine::Object *>	Scene::getObjects()
  {
	  return (this->objects);
  }

  Box		Scene::getBox()
  {
    return (this->box);
  }

  void		Scene::setBox()
  {
    unsigned int	i = 0;
    Tools::Vector	lowCorner;
    Tools::Vector	highCorner;
    Tools::Vector	lowC;
    Tools::Vector	highC;

    while (i < this->objects.size())
      {
	lowC = this->objects[i]->getBox().getLowCorner();
	highC = this->objects[i]->getBox().getHighCorner();
	if (i == 0)
	  {
	    lowCorner = lowC;
	    highCorner = highC;
	  }
	else
	  {
	    if (lowC.getX() < lowCorner.getX())
	      lowCorner.setX(lowC.getX());
	    if (lowC.getY() < lowCorner.getY())
	      lowCorner.setY(lowC.getY());
	    if (lowC.getZ() < lowCorner.getZ())
	      lowCorner.setZ(lowC.getZ());
	    if (highC.getX() > highCorner.getX())
	      highCorner.setX(highC.getX());
	    if (highC.getY() > highCorner.getY())
	      highCorner.setY(highC.getY());
	    if (highC.getZ() > highCorner.getZ())
	      highCorner.setZ(highC.getZ());
	  }
	i++;
      }
    this->box.setLowCorner(lowCorner);
    this->box.setHighCorner(highCorner);
  }

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

    while (j < this->height)
      {
	i = 0;
	positionY = j * sizeLine;
	positionDistY = j * this->width;
	while (i < this->width)
	  {
	    pos = positionY + i * 4;
	    Engine::Ray	ray(i, j, this);
	    ray.compute(this);
	    dist[(int)(positionDistY + j)] = ray.getDist();
	    pixels[pos] = ray.getColor().getR();
	    pixels[pos + 1] = ray.getColor().getG();
	    pixels[pos + 2] = ray.getColor().getB();
	    pixels[pos + 3] = 255;
	    i++;
	  }
	j++;
      }
    Displayer::Frame frame(pixels, dist, this->width, this->height);
    m_window->loop(frame); // l'idée serait d'envoyer à loop toutes les frames
  }
};
