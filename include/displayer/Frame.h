

#ifndef				FRAME_H_
# define			FRAME_H_


namespace	Displayer
{
  class		frame
  {
  public:
	  frame();
	  frame(sf::Uint8 *, float *)
	  ~frame();

	  void	setTexture(sf::Uint8 *);
	  void	setSprite();
	  void	setMotionBlur(frame);
	  void	setDist(float *);
	  void	setDist(float, int, int);

  private:
	  sf::Image			image;
	  sf::Image			motionBlurImage; // c'est lourd àstocker une image ?
	  float				*dist; // ça risque de prendre bcp trop de place :(  mais ce serait bien de l'avoir
	  Engine::Object	*objects; // pareil ça prendrait masse mémoire mais ça permettrait d'appliquer l'effet cartoon après le calcul
	  int				framePos; // la position de cette frame dans la série, pas sur que ce soit utile
	};
};

//Dans le GUI créer 2 barres pour la profondeur de champ (distance et intensité), laisser la possibilité d'enable disable la profondeur de champ et le motion blur



// IDEE DE GENIE PROBABLEMENT COMPLETEMENT CONNE : UNE FOIS QUE TOUTES LES FRAMES SONT CALCULEE FAIRE LE FLOU DE MOUVEMENT EN FAISANT LA MOYENNE DE PLUSIEURS FRAMES

#endif				/* !FRAME_H_ */
