//refaire header, indentation, et tester (toi aussi apprend à coder sans environnement grâce à WINDOWS !)

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
	  double	collide(Engine::Ray const&);
	  ~Box();

  private:
	  Tools::Vector	lowCorner;
	  Tools::Vector	highCorner;
	  std::vector<Engine::Object *> objects;
  };
}

#endif		/* !BOX_H_ */
