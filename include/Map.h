/*
** Map.h for prototype in /home/zanard_a/rendu/Projets_TEK1/prototype
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Jun 11 18:46:05 2015 Antoine Zanardi
** Last update Wed Jun 24 13:44:50 2015 Antoine Lempereur
*/

#ifndef		MAP_H_
# define	MAP_H_

# include	<SFML/Graphics.hpp>

# define        MAP_WIDTH	100
# define        MAP_HEIGHT	100
# define	W_CASE		60
# define	H_CASE		W_CASE / 2
# define	ROCK		0
# define	GROS_PAVE	1
# define	PETIT_PAVE	2
# define	ROCK2		3
# define	DARK_GRASS	4
# define	SWAMP		5
# define	GRASS		6
# define	FOREST		0


namespace	Engine
{
  class		Map
  {
  public:
    Map();
    ~Map();
  };

  class		Square
  {
  public:
    Square();
    Square(double alt, int type);
    ~Square();
    double		get_alt();
    int			get_type();
    void		change_type(int new_type);
    void		display_info_square();
    void		set_sprite(int, int);
    sf::Sprite		get_sprite();
  private:
    double		alt;
    int			type;
    sf::Sprite		sprite;
  };
};

#endif		/* !MAP_H_ */
