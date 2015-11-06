/*
** Packet.cpp for prototype in /home/vasseu_g/rendu/prototype
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Fri Jun 19 11:44:56 2015 Adrien Vasseur
** Last update Fri Jun 19 18:34:14 2015 Adrien Vasseur
*/

#include	"Packet.h"
#include	<iostream>
namespace	Network
{
  Packet::Packet()
  {
    this->m_data.clear();
    this->m_readPos = 0;
    this->m_packetId = 0;
    this->m_hisize = 0;
    this->m_size = 0;
  }

  Packet::~Packet()
  {
    this->m_data.clear();
  }

  void Packet::addData(char *data, std::size_t size)
  {
    if (data && size > 0)
      {
	std::size_t start = m_data.size();
	m_data.resize(start + size);
	std::memcpy(&m_data[start], data, size);
      }
  }

  char Packet::getData()
  {
    if (this->m_readPos < this->m_data.size())
      return (this->m_data[this->m_readPos++]);
    return (0);
  }

  std::vector<char> Packet::serialize(unsigned short packetId)
  {
    std::vector<char>	pack;
    unsigned char	hisize;
    std::size_t		size;
    std::size_t		start;

    pack.clear();
    size = this->m_data.size();
    std::cout << "Content size " << size << std::endl;
    if (this->m_data.size() < 255)
      hisize = 1;
    else if (this->m_data.size() < 65535)
      hisize = 2;
    else
      hisize = 3;
    std::cout << "Hisize = " << (int) hisize << std::endl;
    packetId <<= 2;
    pack.push_back((packetId >> 8) & 255);
    pack.push_back((packetId + hisize) & 255);
    for (std::size_t i = 0; i < hisize; i++)
      pack.push_back((size << (8 * i)) & 255);
    start = pack.size();
    std::cout << "start = " << start << std::endl;
    pack.resize(start + size);
    std::memcpy(&pack[start], this->m_data.data(), size);
    std::cout << "SIze = " << pack.size() << std::endl;
    std::cout << "1 ET 2 " << (int) pack[0] << "   " << (int) pack[1] << std::endl;
    return (pack);
  }

  bool Packet::deserialize()
  {
    unsigned short	header;

    header = (this->m_data[0] << 8) + (this->m_data[1]);
    this->m_packetId = header >> 2;
    this->m_hisize = header & 0x3;
    this->m_size = 0;
    for (std::size_t i = 0; i < this->m_hisize; i++)
      this->m_size += this->m_data[i + 2] >> (8 * i);
    std::cout << "PACKET SIZE = " << this->m_size << std::endl;
    this->m_readPos += 2 + this->m_hisize;
    return (true);
  }

  Packet Packet::extract()
  {

  }
};
