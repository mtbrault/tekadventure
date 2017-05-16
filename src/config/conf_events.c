/*
** conf_events.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Mon May  8 00:27:18 2017 LAABID Zakaria
** Last update Sat May 13 19:34:05 2017 LAABID Zakaria
*/

#include <stdlib.h>
#include <unistd.h>
#include "config.h"

int	config_event_fill(t_level **level, char **conf, int y)
{
  int	x;

  x = 1;
  config_event_one(level, conf, x, y);
  config_event_two(level, conf, x, y);
  return (0);
}
