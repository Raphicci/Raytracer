/*
** Scene.h for Raytracer in /home/vasseu_g/github/Raytracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Nov 12 20:33:42 2015 Adrien Vasseur
** Last update Wed Nov 18 17:01:14 2015 Antoine Lempereur
*/

#ifndef		SCENE_H_
# define	SCENE_H_

# include	<vector>
# include	"displayer/Window.h"
# include	"displayer/EnvChecker.h"
# include	"tools/Vector.h"
# include	"engine/Object.h"
# include	"parser/SceneParser.h"
//# include	<SFML/Graphics/vector.h>

namespace	Parser
{
  class		SceneParser;
};

namespace	Displayer
{
  class		Window;
}

namespace	Engine
{
  class		Object;

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
    Tools::Vector		origin;
    //sf::vector3f		rotation; // pourquoi eux ils ont le droit de mettre x, y, z en public ? c'est du racisme
    std::vector<Engine::Object *> objects;
    unsigned int					height; // set hauteur / largeur différent de ceux du fichier de conf ?
    unsigned int					width;
    int					antiAliasing;
    int					fps;
  };
};

#endif		/* !SCENE_H_ */
