/*
** NetworkManager.cpp for prototype in /home/vasseu_g/rendu/prototype
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun 18 20:28:58 2015 Adrien Vasseur
** Last update Fri Jun 19 10:20:51 2015 Adrien Vasseur
*/

#include	"network/NetworkManager.h"

namespace	Network
{
  NetworkManager::NetworkManager()
  {
    this->m_addr = NULL;
    this->m_socket = NULL;
    m_port = 2555;
  }

  NetworkManager::~NetworkManager()
  {
    if (this->m_addr)
      delete this->m_addr;
    if (this->m_socket)
      delete this->m_socket;
  }

  bool NetworkManager::init()
  {
    if (!this->m_addr)
      this->m_addr = new sf::IpAddress("127.0.0.1");
    if (!this->m_socket)
      this->m_socket = new sf::TcpSocket;
    return (true);
  }

  void NetworkManager::connect()
  {
    init();

    if (this->m_socket->connect(*this->m_addr, this->m_port) != sf::Socket::Done)
      {
	std::cerr << "[NETWORK] [ERROR] Unable to connect to master server" << std::endl;
      }
  }
};
