/*
** SceneParser.cpp for Raytracer in /home/vasseu_g/github/Raytracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Nov 12 20:54:02 2015 Adrien Vasseur
** Last update Thu Nov 12 20:59:28 2015 Adrien Vasseur
*/

#include	"parser/SceneParser.h"

namespace	Parser
{
  SceneParser::SceneParser()
  {
    m_pos = 0;
  }

  SceneParser::~SceneParser()
  {
    m_buff.erase();
  }

  bool		loadFromFile(Engine::Scene &scene, std::string filename)
  {
    return (true);
  }
};
