/*
** NetworkManager.h for prototype in /home/vasseu_g/rendu/prototype
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun 18 20:27:31 2015 Adrien Vasseur
** Last update Thu Jun 18 20:50:15 2015 Adrien Vasseur
*/

#ifndef		NETWORKMANAGER_H_
# define	NETWORKMANAGER_H_

# include	<iostream>

# include	<SFML/Network.hpp>

namespace	Network
{
  class		NetworkManager
  {
  public:
    NetworkManager();
    ~NetworkManager();

    bool	init();
    void	connect();

  private:
    sf::IpAddress	*m_addr;
    unsigned short	m_port;
    sf::TcpSocket	*m_socket;
  };
};

#endif		/* !NETWORKMANAGER_H_ */
