/*
** Scene.cpp for Raytracer in /home/vasseu_g/github/Raytracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Nov 12 20:38:27 2015 Adrien Vasseur
** Last update Thu Nov 12 20:47:16 2015 Adrien Vasseur
*/

#include	"engine/Scene.h"

namespace	Engine
{
  Scene::Scene()
  {
    m_window = NULL;
  }

  Scene::~Scene()
  {
    if (!m_window)
      delete m_window;
  }

  bool		Scene::init(int argv, char **argc)
  {
    if (!Displayer::EnvChecker::hasXEnv())
      return (false);
    m_window = new Displayer::Window;
    return (true);
  }

  void		Scene::run()
  {
    m_window->loop();
  }
};
