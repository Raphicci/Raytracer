/*
** SceneParser.h for Raytracer in /home/vasseu_g/github/Raytracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Nov 12 20:28:50 2015 Adrien Vasseur
** Last update Thu Nov 12 21:00:31 2015 Adrien Vasseur
*/

#ifndef		SCENEPARSER_H_
# define	SCENEPARSER_H_

# include	<string>

# include	"engine/Scene.h"

namespace	Engine
{
  class		Scene;
};

namespace	Parser
{
  class		SceneParser
  {
  public:
    SceneParser();
    ~SceneParser();

    bool	loadFromFile(Engine::Scene &, std::string);

  private:
    size_t	m_pos;
    std::string	m_buff;
  };
};

#endif		/* !SCENEPARSER_H_ */
