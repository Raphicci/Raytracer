/*
** Vector.h for rayestasoeur in /home/lemper_a/rendu/raytracer/Raytracer
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Sat Nov  7 16:21:52 2015 Antoine Lempereur
** Last update Sun Nov 15 13:23:14 2015 Antoine Lempereur
*/

#ifndef		VECTOR_H_
# define	VECTOR_H_

namespace	Tools
{
  class		Vector
  {
  public:
    Vector();
    Vector(double x, double y, double z);
    ~Vector();
    void	setX(double value);
    void	setY(double value);
    void	setZ(double value);
    double	getX();
    double	getY();
    double	getZ();
    void	setValues(double x, double y, double z);
    double	scalar(Vector const& vec);
    Vector	vectorProduct(Vector const& vec);
    void	reverse();
    void	inverse();
    void	rotateX(double);
    void	rotateY(double);
    void	rotateZ(double);
    void	rotate(double x, double y, double z);
    void	normalize();
    void	translate(double x, double y, double z);
    Vector	getRandomVec(double angle);
    Vector	operator+(Vector const&);

  private:
    double	x;
    double	y;
    double	z;
  };
}

#endif
