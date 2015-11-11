/*
** DistributionHandler.h for raytracer in /home/lemper_a/rendu/Raytracer/include
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Wed Nov 11 17:48:06 2015 Antoine Lempereur
** Last update Wed Nov 11 18:08:12 2015 Antoine Lempereur
*/


#ifndef		DISTRIBUTIONHANDLER_H_
# define	DISTRIBUTIONHANDLER_H_

#include	"tools/Vector.h"

namespace	Tools
{
  class		DistributionHandler
  {
  public:
    DistributionHandler(Tools::Vector, float angle, int nbrRayons);
    ~DistributionHandler();

  private:
    Tools::Vector		mainVector;
    std::vector<Objects *>	objects;
    float			angle;
    std::vector<Tools::Vector>	vectors;
  };
}

#endif
