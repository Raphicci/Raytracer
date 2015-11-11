/*
** Ray.h for rayestasoeur in /home/lemper_a/rendu/raytracer/Raytracer
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Sat Nov  7 16:21:52 2015 Antoine Lempereur
** Last update Wed Nov 11 19:21:04 2015 Antoine Lempereur
*/

#ifndef		RAY_H_
# define	RAY_H_

# include	"tools/Vector.h"
# include	"tools/Color.h"
# include	"engine/Object.h"

namespace	Engine
{
  class		Ray
  {
  public:
    Ray(Tools::Vector origin, Tools::Vector direction); // références / Copies ?
    Ray(double i, double j, Tools::Vector rotation, int w, int h);
    void	setIntersection();
    void	normalize();
    void	setNormal();
    //void	findClosestObject(List<*Object>);
    //void	setColor(Scene scene);
    ~Ray();

  private:
    Engine::Object	*object;//  un pointeur sur l'obj rencontré
    float	dist;
    bool	isLim; // Limite ou pas, probablement utile pour les normales (a check)
    Tools::Vector	origin;
    Tools::Vector	direction;
    Tools::Vector	inversed; // pour les interbox, pour pas avoir à le calc à chq fois
    Tools::Vector	intersection;
    Tools::Vector	normal;
    Tools::Color	color;
  };
}

#endif		/* !RAY_H_ */
