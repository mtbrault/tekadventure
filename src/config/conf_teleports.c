/*
** conf_mobs.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Thu May  4 00:42:07 2017 LAABID Zakaria
** Last update Sat May 13 19:33:54 2017 LAABID Zakaria
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
  return (0);
}
