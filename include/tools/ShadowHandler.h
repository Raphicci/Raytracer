/*
** ShadowHandler.h for raytracer in /home/lemper_a/rendu/raytracer/Raytracer
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Fri Nov  6 17:14:36 2015 Antoine Lempereur
** Last update Thu Nov 12 16:22:48 2015 Antoine Lempereur
*/

#ifndef		SHADOWHANDLER_H_
# define	SHADOWHANDLER_H_

# include	"tools/DistributionHandler.h"

class	ShadowHandler : public DistributionHandler
{
 private:
  Vector	mainVec();
  float		value;
 public:
  ShadowHandler();
};

#endif		/* !SHADOWHANDLER */
