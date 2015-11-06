/*
** Unit.h for proto in /home/thieba_r/Documents/prototype
** 
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
** 
** Started on  Fri Jun 12 17:40:19 2015 Raphael Thiebault
** Last update Wed Jun 17 18:27:51 2015 Raphael Thiebault
*/

#ifndef	        UNIT_H_
# define        UNIT_H_

namespace	Engine
{
  class	        Unit
  {
  public:
    Unit();
    Unit(int, int, int);
    ~Unit();
    void		Move();
    MapSearchNode	*PathFinding(int, int);
  private:
    int		x;
    int		y;
    int		speed;
  };
};

#endif		/* !UNIT_H_ */
