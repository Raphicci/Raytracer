/*
** Vector.cpp for raytracer in /home/lemper_a/rendu/raytracer/Raytracer/src/tools
** 
** Made by Antoine Lempereur
** Login   <lemper_a@epitech.net>
** 
** Started on  Sat Nov  7 16:59:23 2015 Antoine Lempereur
** Last update Thu Nov 12 17:37:17 2015 Antoine Lempereur
*/

#include	<math.h>
#include	"tools/Vector.h"
#include	"const.h"

namespace	Tools
{
  Vector::Vector()
  {
    Vector(0, 0, 0);
  }

  Vector::Vector(double x, double y, double z)
  {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  void	Vector::setX(double value)
  {
    this->x = value;
  }

  void	Vector::setY(double value)
  {
    this->y = value;
  }

  void	Vector::setZ(double value)
  {
    this->z = value;
  }

  void	Vector::setValues(double x, double y, double z)
  {
    this->setX(x);
    this->setY(y);
    this->setZ(z);
  }

  double	Vector::getX()
  {
    return (this->x);
  }


  double	Vector::getY()
  {
    return (this->y);
  }


  double	Vector::getZ()
  {
    return (this->z);
  }

  double	Vector::scalar(Vector const& vec)
  {
    return (this->x * vec.x + this->y * vec.y + this->z * vec.z);
  }

  void		Vector::normalize()
  {
    double	n;

    n = sqrt(this->x * this->x + this->y * this->y + this->z + this->z);
    this->x /= n;
    this->y /= n;
    this->z /= n;
  }

  void		Vector::reverse()
  {
    this->x = -this->x;
    this->y = -this->y;
    this->z = -this->z;
  }

  void		Vector::inverse()
  {
    this->x = 1 / this->x;
    this->y = 1 / this->y;
    this->z = 1 / this->z;
  }

  void		Vector::rotateX(double value)
  {
    double	saveY = this->y;
    double	saveZ = this->z;

    this->y = cos(value) * saveY - sin(value) * saveZ;
    this->z = sin(value) * saveY + cos(value) * saveZ;
  }

  void		Vector::rotateY(double value)
  {
    double	saveX = this->x;
    double	saveZ = this->z;

    this->x = cos(value) * saveX + sin(value) * saveZ;
    this->z = -1 * sin(value) * saveX + cos(value) * saveZ;
  }

  void		Vector::rotateZ(double value)
  {
    double	saveY = this->y;
    double	saveX = this->x;

    this->y = sin(value) * saveX + cos(value) * saveY;
    this->x = cos(value) * saveX - sin(value) * saveY;
  }

  void		Vector::rotate(double x, double y, double z)
  {
    if (x < -ALMOST_ZERO || x > ALMOST_ZERO)
      this->rotateX(x);
    if (y < -ALMOST_ZERO || y > ALMOST_ZERO)
      this->rotateY(y);
    if (z < -ALMOST_ZERO || z > ALMOST_ZERO)
      this->rotateZ(z);
  }

  Vector	Vector::operator+(Vector const& vec)
  {
    Vector	result(this->x + vec.x, this->y + vec.y, this->z + vec.z);

    return (result);
  }

  Vector::~Vector()
  {

  }

  //reste à coder translate, vectorProduct
};
