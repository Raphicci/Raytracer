/*
** Frame.h for raytracer in /home/lemper_a/rendu/Raytracer
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Wed Nov 18 16:39:48 2015 Antoine Lempereur
** Last update Fri Nov 20 16:41:31 2015 Antoine Lempereur
*/

#ifndef		FRAME_H_
# define	FRAME_H_

# include	<SFML/Graphics.hpp>

# include	"engine/Object.h"

namespace	Displayer
{
  class		Frame
  {
  public:
    Frame();
    Frame(sf::Uint8 *, float *, unsigned int, unsigned int);
    ~Frame();

    void	setMotionBlur(Frame const&);
    void	setDist(float *);
    void	setDist(float, int, int);
    sf::Sprite	getSprite();
    static sf::Color	MixSfColor(sf::Color const&, sf::Color const&);

    unsigned int	getFramePos();

  private:
    sf::Texture			texture;
    sf::Texture			motionBlurTexture;
    sf::Sprite			sprite;
    sf::Sprite			motionBlurSprite;
    float				*dist; // ça risque de prendre bcp trop de place :(  mais ce serait bien de l'avoir
    //Engine::Object		*objects; pareil ça prendrait masse mémoire mais ça permettrait d'appliquer l'effet cartoon après le calcul, et probablement d'autre trucs
    unsigned int				framePos; // la position de cette frame dans la série
  };
};

//Dans le GUI créer 2 barres pour la profondeur de champ (distance et intensité), laisser la possibilité d'enable disable la profondeur de champ et le motion blur



// IDEE DE GENIE PROBABLEMENT COMPLETEMENT CONNE : UNE FOIS QUE TOUTES LES FRAMES SONT CALCULEE FAIRE LE FLOU DE MOUVEMENT EN FAISANT LA MOYENNE DE PLUSIEURS FRAMES

#endif				/* !FRAME_H_ */
