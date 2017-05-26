/*
** conf_teleports.c for  in /home/BlackBIrdz/tekadventure/src/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Mon May 22 14:24:42 2017 LAABID Zakaria
** Last update Sat May 27 01:22:04 2017 LAABID Zakaria
*/

#include <stdlib.h>
#include <unistd.h>
#include "config.h"

int	config_telep_fill(t_level **level, char **conf, int y)
{
  int	x;

  x = 1;
  config_telep_one(level, conf, x, y);
  config_telep_two(level, conf, x, y);
  config_telep_three(level, conf, x, y);
  return (0);
}
