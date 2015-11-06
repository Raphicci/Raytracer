//
// Window_Config.cpp for prototype in /home/zanard_a/rendu/Projets_TEK1/prototype
//
// Made by Antoine Zanardi
// Login   <zanard_a@epitech.net>
//
// Started on  Thu Jun 11 12:16:55 2015 Antoine Zanardi
// Last update Thu Jun 11 19:49:05 2015 Raphael Thiebault
//

#include	<map>
#include	"Window_Config.h"

namespace Displayer
{
  Window_Config::Window_Config()
  {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    parsing["aa"] = 1;
    parsing["width"] = desktop.width;
    parsing["height"] = desktop.height;
    parsing["sync"] = 0;
    parsing["fullscreen"] = 0;
  }

  Window_Config::~Window_Config()
  {
  }

  void		Window_Config::createFile()
  {
    std::ofstream	stream("config.ini");

    if (stream.is_open())
      {
	for (auto&x: parsing)
	  stream << x.first << "=" << x.second << "\n";
	stream.close();
      }
    else
      exit(EXIT_FAILURE);
  }

  void		Window_Config::parseFile()
  {
    std::ifstream	stream("config.ini");
    std::string		line;

    if (!(stream.is_open()))
      createFile();
    else
      while (std::getline(stream, line))
	parsing[line.substr(0, line.find("="))] =
	  std::stoi(line.substr(line.find("=") + 1), nullptr, 10);
    stream.close();
  }

  int		Window_Config::get(std::string key)
  {
    return (parsing[key]);
  }
};
