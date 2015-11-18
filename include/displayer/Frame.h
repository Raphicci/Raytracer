

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
	  sf::Image			motionBlurImage; // c'est lourd �stocker une image ?
	  float				*dist; // �a risque de prendre bcp trop de place :(  mais ce serait bien de l'avoir
	  Engine::Object	*objects; // pareil �a prendrait masse m�moire mais �a permettrait d'appliquer l'effet cartoon apr�s le calcul
	  int				framePos; // la position de cette frame dans la s�rie, pas sur que ce soit utile
	};
};

//Dans le GUI cr�er 2 barres pour la profondeur de champ (distance et intensit�), laisser la possibilit� d'enable disable la profondeur de champ et le motion blur



// IDEE DE GENIE PROBABLEMENT COMPLETEMENT CONNE : UNE FOIS QUE TOUTES LES FRAMES SONT CALCULEE FAIRE LE FLOU DE MOUVEMENT EN FAISANT LA MOYENNE DE PLUSIEURS FRAMES

#endif				/* !FRAME_H_ */
