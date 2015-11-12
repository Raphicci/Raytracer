/*
** Ray.h for rayestasoeur in /home/lemper_a/rendu/raytracer/Raytracer
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Sat Nov  7 16:21:52 2015 Antoine Lempereur
** Last update Thu Nov 12 22:26:02 2015 Antoine Lempereur
*/

#ifndef		RAY_H_
# define	RAY_H_

# include	<vector>

# include	"tools/Vector.h"
# include	"tools/Color.h"
# include	"engine/Object.h"
# include	"engine/Scene.h"

namespace	Engine
{
  class		Ray
  {
  public:
    Ray(Tools::Vector origin, Tools::Vector direction); // références / Copies ?
    Ray(double i, double j, Engine::Scene const&);
    void	setIntersection();
    void	normalize();
    void	compute(Engine::Scene const&);
    void	setNormal();
    void	findClosestObject(std::vector<Engine::Object*>);
    Tools::Vector	calcReflectedMainRay();
    Tools::Vector	calcRefractedMainRay();
    Tools::Color	getReflectedColor(Engine::Scene const&);
    Tools::Color	getRefractedColor(Engine::Scene const&);
    void	setColor(Engine::Scene const&);
    Tools::Color	getColor();
    ~Ray();

  private:
    Engine::Object	*object;
    float	dist;
    bool	isLim;
    Tools::Vector	origin;
    Tools::Vector	direction;
    Tools::Vector	inversed; // pour les interbox, pour pas avoir à le calc à chq fois
    Tools::Vector	intersection;
    Tools::Vector	normal;
    Tools::Color	color;
  };
}

#endif		/* !RAY_H_ */
