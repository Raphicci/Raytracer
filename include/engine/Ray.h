/*
** Ray.h for rayestasoeur in /home/lemper_a/rendu/raytracer/Raytracer
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Sat Nov  7 16:21:52 2015 Antoine Lempereur
** Last update Thu Nov 26 16:55:44 2015 Antoine Lempereur
*/

#ifndef		RAY_H_
# define	RAY_H_

# include	<vector>

# include	"tools/Vector.h"
# include	"tools/Color.h"
# include	"engine/Object.h"
# include	"engine/Scene.h"
# include	"engine/Box.h"

namespace	Engine
{
  class		Scene;

  class		Ray
  {
  public:
    Ray(Tools::Vector origin, Tools::Vector direction);
    Ray(double i, double j, Engine::Scene *);
    ~Ray();

    void					normalize();
    void					compute(Engine::Scene *);
    void					setNormal();
    void					findClosestObject(std::vector<Engine::Object*>);
    void					setListBox(Engine::Scene const&);
    Tools::Vector				calcReflectedMainRay(Tools::Vector);
    Tools::Vector				calcRefractedMainRay(Tools::Vector);
    Tools::Color				getReflectedColor(Engine::Scene *, Tools::Vector, Tools::Vector);
    Tools::Color				getRefractedColor(Engine::Scene *, Tools::Vector, Tools::Vector);
    void					setColor(Engine::Scene const&);

    Tools::Color				getColor();
    Tools::Vector				getInversed();
    Tools::Vector				getOrigin();
    Tools::Vector				getOriginSimple();
    Tools::Vector				getDirection();
    Tools::Vector				getDirectionSimple();
    Engine::Object*				getObject();
    bool					getIsLim();
    double					getDist();

  private:
    void					setPosSimple(Tools::Vector, Tools::Vector);
    void					setSaves(float, Engine::Object *, Tools::Vector &, Tools::Vector &);
    Tools::Vector				calcIntersection(Tools::Vector, Tools::Vector, float);

      Engine::Object				*object;
    double					dist;
    bool					isLim;
    Tools::Vector				origin;
    Tools::Vector				originSimple;
    Tools::Vector				direction;
    Tools::Vector				directionSimple;
    Tools::Vector				inversed;
    Tools::Color				color;
    std::vector<Engine::Box>			boxes;
    int						countRef;
  };
}

#endif		/* !RAY_H_ */
