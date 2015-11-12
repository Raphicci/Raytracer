/*
** Log.cpp for Raytracer in /home/vasseu_g/github/Raytracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Nov 12 21:11:57 2015 Adrien Vasseur
** Last update Thu Nov 12 22:06:57 2015 Adrien Vasseur
*/

#include	"tools/Log.h"

Log		Log::m_instance = Log();

Log::Log()
{
  m_out.open("raytracer.log", std::fstream::out | std::fstream::app);
  if (!m_out.is_open())
    Log::warning("Unable to open log file");
}

Log::Log(const Log &)
{

}

Log::~Log()
{
  if (m_out.is_open())
    m_out.close();
}

Log		&Log::operator = (const Log &)
{
  return (m_instance);
}

Log		&Log::Instance()
{
  return (m_instance);
}

void		Log::error(std::string msg)
{
  Log		&m_log = Log::Instance();

  std::cerr << m_log.getDate() << " [ERROR] " << msg << std::endl;
  if (m_log.m_out.is_open())
    m_log.m_out << m_log.getDate() << " [ERROR] " << msg << std::endl;
}

void		Log::warning(std::string msg)
{
  Log		&m_log = Log::Instance();

  std::cout << m_log.getDate() << " [WARNING] " << msg << std::endl;
  if (m_log.m_out.is_open())
    m_log.m_out << m_log.getDate() << " [WARNING] " << msg << std::endl;
}

void		Log::info(std::string msg)
{
  Log		&m_log = Log::Instance();

  std::cout << m_log.getDate() << " [INFO] " << msg << std::endl;
  if (m_log.m_out.is_open())
    m_log.m_out << m_log.getDate() << " [INFO] " << msg << std::endl;
}

std::string	Log::getDate()
{
  time_t	t = time(NULL);
  struct tm	*now = localtime(&t);
  std::string	date;

  date = "[";
  if (now->tm_mday < 10)
    date += "0";
  date += Log::toString(now->tm_mday) + "-";
  if (now->tm_mon + 1 < 10)
    date += "0";
  date += Log::toString(now->tm_mon + 1) + "-" +
    Log::toString(now->tm_year + 1900) + " ";
  if (now->tm_hour < 10)
    date += "0";
  date += Log::toString(now->tm_hour) + ":";
  if (now->tm_min < 10)
    date += "0";
  date += Log::toString(now->tm_min) + ":";
  if (now->tm_sec < 10)
    date += "0";
  date += Log::toString(now->tm_sec) + "]";
  return (date);
}
