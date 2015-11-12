/*
** Log.h for Raytracer in /home/vasseu_g/github/Raytracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Nov 12 21:23:09 2015 Adrien Vasseur
** Last update Thu Nov 12 22:06:38 2015 Adrien Vasseur
*/

#ifndef			LOG_H_
# define		LOG_H_

# include		<string>
# include		<fstream>
# include		<sstream>
# include		<iostream>
# include		<ctime>

class			Log
{
 public:
  static Log		&Instance();
  static void		error(std::string);
  static void		warning(std::string);
  static void		info(std::string);

  template<typename T>
  static std::string	toString(const T &nbr)
    {
      std::stringstream	stream;

      stream << nbr;
      return (stream.str());
    }

 private:
  Log();
  Log(const Log &);
  ~Log();

  Log			&operator = (const Log &);
  static Log		m_instance;

  std::ofstream		m_out;
  std::string		getDate();
};

#endif			/* !LOG_H_ */
