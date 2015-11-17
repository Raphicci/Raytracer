/*
** Scene.h for Raytracer in /home/vasseu_g/github/Raytracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Nov 12 20:33:42 2015 Adrien Vasseur
** Last update Thu Nov 12 21:03:21 2015 Adrien Vasseur
*/

#ifndef		SCENE_H_
# define	SCENE_H_

# include	<vector>
# include	"displayer/Window.h"
# include	"displayer/EnvChecker.h"
# include	"parser/SceneParser.h"

namespace	Parser
{
  class		SceneParser;
};

namespace	Engine
{
  class		Scene
  {
  public:
    Scene();
    ~Scene();

    bool	init(int, char **);
    void	run();

  private:
    Parser::SceneParser	*m_parser;
    Displayer::Window	*m_window;
	/*Tools::Vector		origin;
	sf::vector3f		rotation; // pourquoi eux ils ont le droit de mettre x, y, z en public ? c'est du racisme
	
	std::vector<Engine::Object *> objects
	int					height; // set hauteur / largeur différent de ceux du fichier de conf ?
	int					width;	
	int					antiAliasing;
	int					fps;
	*/
  };
};

#endif		/* !SCENE_H_ */
