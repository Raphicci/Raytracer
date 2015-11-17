/*
** Box.h for raytracer in /home/lemper_a/rendu/Raytracer
**
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
**
** Started on  Sun Nov 15 09:53:57 2015 Antoine Lempereur
** Last update Tue Nov 17 22:03:38 2015 Antoine Lempereur
*/

#ifndef		BOX_H_
# define	BOX_H_

# include	"tools/Vector.h"
# include	"engine/Ray.h"

namespace	Engine
{
  class		Box
  {
  public:
	  Box();
	  Box(Tools::Vector, Tools::Vector);
	  bool		isInsideBox(Engine::Box const&);
	  bool		contain(Tools::Vector const&);
	  double	collide(Engine::Ray const&);
	  void		setBoxesInside();
	  ~Box();

  private:
	  Tools::Vector	lowCorner;
	  Tools::Vector	highCorner;
	  std::vector<Engine::Object *> objects;
	  Box		*boxes;
  };
}

#endif		/* !BOX_H_ */
