/*
** Ray.h for rayestasoeur in /home/lemper_a/rendu/raytracer/Raytracer
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Sat Nov  7 16:21:52 2015 Antoine Lempereur
** Last update Sat Nov 21 20:14:40 2015 Antoine Lempereur
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

    void					setIntersection();
    void					normalize();
    void					compute(Engine::Scene *);
    void					setNormal();
    void					findClosestObject(std::vector<Engine::Object*>);
    void					setListBox(Engine::Scene const&);
    Tools::Vector				calcReflectedMainRay();
    Tools::Vector				calcRefractedMainRay();
    Tools::Color				getReflectedColor(Engine::Scene *);
    Tools::Color				getRefractedColor(Engine::Scene *);
    void					setColor(Engine::Scene const&);

    Tools::Color				getColor();
    /*Tools::Vector				getIntersection();
    Tools::Vector				getNormal();*/
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
	void					setSaves();
	Tools::Vector			calcIntersection(Tools::Vector, Tools::Vector, float)

    Engine::Object				*object;
    double					dist;
    bool					isLim;
    Tools::Vector				origin;
    Tools::Vector				originSimple;
    Tools::Vector				direction;
    Tools::Vector				directionSimple;
    Tools::Vector				inversed;
    /*Tools::Vector				intersection;
    Tools::Vector				normal;*/ // probablement pas besoin de la stocker en fait, sauf si ça sert post-calculs // pareil pour l'intersection en fait, on en a besoin souvent mais pas forcément besoin de le stocker
    Tools::Color				color;
    std::vector<Engine::Box>			boxes;
    int						countRef;
  };
}

#endif		/* !RAY_H_ */
