/*
** main.cpp for prototype in /home/vasseu_g/rendu/prototype
**
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
**
** Started on  Thu Jun 18 17:44:25 2015 Adrien Vasseur
** Last update Sun Nov 15 12:49:39 2015 Antoine Lempereur
*/

#include	"tools/Log.h"
#include	"engine/Scene.h"
#include	"tools/Vector.h"
#include	"tools/Color.h"
#include	"engine/Ray.h"
#include	"engine/Box.h"
#include	"const.h"

int				main(int argc, char **argv)
{
  Engine::Scene			scene;
  Tools::Vector			v1(2, 2, 2);
  Tools::Vector			v2(1, 1, 1);

  v1 = v1 + v2;
  Log::info(Log::toString(v1.getZ()));
  if (!scene.init(argc, argv))
    return (EXIT_FAILURE);
  scene.run();
  return (EXIT_SUCCESS);
}
