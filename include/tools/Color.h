/*
** Color.h for raytracer in /home/lemper_a/rendu/raytracer/Raytracer/include/tools
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Sun Nov  8 10:16:27 2015 Antoine Lempereur
** Last update Sat Nov 21 19:58:30 2015 Antoine Lempereur
*/


#ifndef		COLOR_H_
# define	COLOR_H_

# include	<iostream>
# include	<exception>

# include	<vector>

# include	<SFML/Graphics/Color.hpp>

namespace	Tools
{
  class		Color
  {
  public:
    Color();
    Color(int r, int g, int b);
    int		getR();
    int		getG();
    int		getB();
    void	setR(int value);
    void	setG(int value);
    void	setB(int value);
    void	setRGB(int r, int g, int b);
    void	Mix(Color const&);
    void	Mix(std::vector<Color const&>);
    void	Mix(Color const&, float);
    void	PreventOverflow();
    static sf::Color	MixSfColor(sf::Color const&, sf::Color const&);
    sf::Color	toSfColor(); //pour envoyer aux fonctions de la sfml  // peut etre pas besoin en fait, car on peut pas affichier directement une image donc c'est caca
    ~Color();

  private:
    int		r;
    int		g;
    int		b;
  };
}

#endif
