/*
** SceneParser.h for Raytracer in /home/vasseu_g/github/Raytracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Nov 12 20:28:50 2015 Adrien Vasseur
** Last update Thu Nov 12 20:36:24 2015 Adrien Vasseur
*/

#ifndef		SCENEPARSER_H_
# define	SCENEPARSER_H_

# include	<string>

# include	"engine/Scene.h"

namespace	Parser
{
  class		SceneParser
  {
  public:
    SceneParser();
    ~SceneParser();

    bool	loadFromFile(Scene &, std::string);

  private:
  };
};

#endif		/* !SCENEPARSER_H_ */
