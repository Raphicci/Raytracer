/*
** PacketWriter.cpp for prototype in /home/vasseu_g/rendu/prototype
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Fri Jun 19 14:35:15 2015 Adrien Vasseur
** Last update Fri Jun 19 15:44:03 2015 Adrien Vasseur
*/

#include	"PacketWriter.h"

namespace	Network
{
  void		PacketWriter::writeBool(Packet &packet, bool data)
  {
    PacketWriter::writeChar(packet, data);
  }

  void		PacketWriter::writeChar(Packet &packet, char data)
  {
    std::vector<char>	writer;

    writer.clear();
    writer.push_back(data);
    PacketWriter::writeData(packet, writer);
  }

  void		PacketWriter::writeShort(Packet &packet, short data)
  {
    std::vector<char>	writer;

    writer.clear();
    writer.push_back(data & 255);
    writer.push_back((data >> 8) & 255);
    PacketWriter::writeData(packet, writer);
  }

  void		PacketWriter::writeInt(Packet &packet, int data)
  {
    std::vector<char>	writer;

    writer.clear();
    writer.push_back(data & 255);
    writer.push_back((data >> 8) & 255);
    writer.push_back((data >> 16) & 255);
    writer.push_back((data >> 24) & 255);
    PacketWriter::writeData(packet, writer);
  }

  void		PacketWriter::writeLong(Packet &packet, long data)
  {
    std::vector<char>	writer;

    writer.clear();
    writer.push_back(data & 255);
    writer.push_back((data >> 8) & 255);
    writer.push_back((data >> 16) & 255);
    writer.push_back((data >> 24) & 255);
    writer.push_back((data >> 32) & 255);
    writer.push_back((data >> 40) & 255);
    writer.push_back((data >> 48) & 255);
    writer.push_back((data >> 56) & 255);
    PacketWriter::writeData(packet, writer);
  }

  void		PacketWriter::writeString(Packet &packet, std::string data)
  {
    std::size_t		size;
    std::size_t		ite;

    size = data.size();
    ite = 0;
    PacketWriter::writeLong(packet, size);
    while (ite < size)
      {
	PacketWriter::writeChar(packet, data[ite]);
	ite++;
      }
  }

  void		PacketWriter::writeData(Packet &packet, std::vector<char> data)
  {
    packet.addData(data.data(), data.size());
  }
};
