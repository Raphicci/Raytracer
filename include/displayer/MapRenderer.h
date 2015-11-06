/*
** MapRenderer.h for prototype in /home/vasseu_g/rendu/prototype/displayer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun 18 16:46:30 2015 Adrien Vasseur
** Last update Wed Jun 24 14:46:53 2015 Antoine Lempereur
*/

#ifndef		MAPRENDERER_H_
# define	MAPRENDERER_H_

# include	<iostream>

# include	<SFML/Window.hpp>
# include	<SFML/Graphics.hpp>

//# include	"displayer/Window.h"

namespace	Displayer
{
  class				Camera
  {
  public:
    Camera();
    ~Camera();
    void			move(double, double);
    int				getX();
    int				getY();
  private:
    int				x;
    int				y;
  };

  class		MapRenderer
  {
  public:
    MapRenderer();
    ~MapRenderer();

    bool	init();
    void	draw(sf::RenderWindow *, Displayer::Camera *);

  private:
    sf::Texture	*m_tex_pave;
    sf::Sprite	*m_spr_pave;
  };
};

#endif		/* !MAPRENDERER_H_ */
