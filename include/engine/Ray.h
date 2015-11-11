/*
** Ray.h for rayestasoeur in /home/lemper_a/rendu/raytracer/Raytracer
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Sat Nov  7 16:21:52 2015 Antoine Lempereur
** Last update Wed Nov 11 18:13:45 2015 Antoine Lempereur
*/

#ifndef		RAY_H_
# define	RAY_H_

# include	"tools/Vector.h"
# include	"tools/Color.h"

using namespace Tools;

namespace	Engine
{
  class		Ray
  {
  public:
    Ray();
    Ray(Vector origin, Vector direction); // références / Copies ?
    Ray(double i, double j, Vector rotation, int w, int h);
    //void	findClosestObject(List<*Object>);
    //void	setColor(Scene scene);
    ~Ray();

  private:
    //Object	*obj  un pointeur sur l'obj rencontré
    float	dist;
    bool	isLim; // Limite ou pas, probablement utile pour les normales (a check)
    Vector	origin;
    Vector	direction;
    Vector	inversed; // pour les interbox, pour pas avoir à le calc à chq fois
    Vector	intersection;
    Vector	normal;
    Color	color;
    // bon ducoup c'est un peu chiant en fait, je vois pas l'interet de donner des méthodes aux classes si c'est pour qu'on puisse pas s'en servir plus tard
  };
}

#endif		/* !RAY_H_ */
