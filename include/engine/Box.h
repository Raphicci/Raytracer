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
	  double	Collide(Engine::Ray const&);
	  ~Box();

  private:
	  Tools::Vector	lowCorner;
	  Tools::Vector	highCorner;
  };
}

#endif		/* !BOX_H_ */
