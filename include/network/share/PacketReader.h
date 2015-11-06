/*
** PacketReader.h for prototype in /home/vasseu_g/rendu/prototype
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Fri Jun 19 13:27:53 2015 Adrien Vasseur
** Last update Fri Jun 19 13:36:33 2015 Adrien Vasseur
*/

#ifndef			PACKETREADER_H_
# define		PACKETREADER_H_

# include		<string>

# include		"Packet.h"

namespace		Network
{
  class			PacketReader
  {
  public:
    static bool		readBool(Packet &);
    static char		readChar(Packet &);
    static short	readShort(Packet &);
    static int		readInt(Packet &);
    static long		readLong(Packet &);
    static std::string	readString(Packet &);
  };
};

#endif			/* !PACKETREADER_H_ */
