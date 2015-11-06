/*
** Packet.h for prototype in /home/vasseu_g/rendu/prototype/MasterServer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Fri Jun 19 11:45:32 2015 Adrien Vasseur
** Last update Fri Jun 19 18:06:48 2015 Adrien Vasseur
*/

#ifndef		PACKET_H_
# define	PACKET_H_

# include	<vector>
# include	<cstring>

namespace	Network
{
  class		Packet
  {
  public:
    Packet();
    ~Packet();

    void	addData(char *, std::size_t);
    char	getData();

    std::vector<char>	serialize(unsigned short);
    bool	deserialize();

    Packet	extract();

  private:
    std::vector<char>	m_data;
    std::size_t		m_readPos;

    unsigned short	m_packetId;
    unsigned char	m_hisize;
    std::size_t		m_size;
  };
};

#endif		/* !PACKET_H_ */
