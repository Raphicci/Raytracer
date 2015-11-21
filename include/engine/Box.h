/*
** Box.h for raytracer in /home/lemper_a/rendu/Raytracer
**
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
**
** Started on  Sun Nov 15 09:53:57 2015 Antoine Lempereur
** Last update Sat Nov 21 21:02:46 2015 Antoine Lempereur
*/

#ifndef		BOX_H_
# define	BOX_H_

# include	"tools/Vector.h"
# include	"engine/Ray.h"

namespace	Engine
{
  class		Ray;
  class		Object;

  class		Box
  {
  public:
	  Box();
	  Box(Tools::Vector, Tools::Vector);
	  bool		isInsideBox(Engine::Box const&);
	  bool		contain(Tools::Vector const&);
	  double	collide(Engine::Ray *);
	  void		setBoxesInside();
	  double	calcWidth();
	  double	calcHeight(); // le mettre en attr plutot ?
	  double	calcDepth();
	  void		setLowCorner(Tools::Vector);
	  void		setHighCorner(Tools::Vector);
	  Tools::Vector	getLowCorner();
	  Tools::Vector	getHighCorner();
	  ~Box();

  private:
	  Tools::Vector	lowCorner;
	  Tools::Vector	highCorner;
	  std::vector<Engine::Object *> objects;
	  Box		*boxes;
  };
}

#endif		/* !BOX_H_ */
