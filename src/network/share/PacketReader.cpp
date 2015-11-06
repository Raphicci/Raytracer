/*
** PacketReader.cpp for prototype in /home/vasseu_g/rendu/prototype
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Fri Jun 19 13:26:48 2015 Adrien Vasseur
** Last update Fri Jun 19 15:50:45 2015 Adrien Vasseur
*/

#include	"PacketReader.h"
#include	<iostream>

namespace	Network
{
  bool		PacketReader::readBool(Packet &packet)
  {
    return (PacketReader::readChar(packet));
  }

  char		PacketReader::readChar(Packet &packet)
  {
    return (packet.getData());
  }

  short		PacketReader::readShort(Packet &packet)
  {
    return ((short) (((PacketReader::readChar(packet) & 255)) +
		     ((PacketReader::readChar(packet) & 255) << 8)));
  }

  int		PacketReader::readInt(Packet &packet)
  {
    return ((int) (((PacketReader::readChar(packet) & 255)) +
		   ((PacketReader::readChar(packet) & 255) << 8) +
		   ((PacketReader::readChar(packet) & 255) << 16) +
		   ((PacketReader::readChar(packet) & 255) << 24)));
  }

  long		PacketReader::readLong(Packet &packet)
  {
    return ((long) (((long)(PacketReader::readChar(packet) & 255)) +
		    ((long)(PacketReader::readChar(packet) & 255) << 8) +
		    ((long)(PacketReader::readChar(packet) & 255) << 16) +
		    ((long)(PacketReader::readChar(packet) & 255) << 24) +
		    ((long)(PacketReader::readChar(packet) & 255) << 32) +
		    ((long)(PacketReader::readChar(packet) & 255) << 40) +
		    ((long)(PacketReader::readChar(packet) & 255) << 48) +
		    ((long)(PacketReader::readChar(packet) & 255) << 56)));
  }

  std::string	PacketReader::readString(Packet &packet)
  {
    std::size_t	size;
    std::size_t	ite;
    std::string	data;

    size = PacketReader::readLong(packet);
    ite = 0;
    data.clear();
    while (ite < size)
      {
	data += PacketReader::readChar(packet);
	ite++;
      }
    return (data);
  }
};
