/*
** PacketWriter.h for prototype in /home/vasseu_g/rendu/prototype
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Fri Jun 19 14:35:35 2015 Adrien Vasseur
** Last update Fri Jun 19 15:30:43 2015 Adrien Vasseur
*/

#ifndef			PACKETWRITER_H_
# define		PACKETWRITER_H_

# include		<string>
# include		<vector>

# include		"Packet.h"

namespace		Network
{
  class			PacketWriter
  {
  public:
    static void		writeBool(Packet &, bool);
    static void		writeChar(Packet &, char);
    static void		writeShort(Packet &, short);
    static void		writeInt(Packet &, int);
    static void		writeLong(Packet &, long);
    static void		writeString(Packet &, std::string);

  private:
    static void		writeData(Packet &, std::vector<char>);
  };
};

#endif			/* !PACKETWRITER_H_ */
