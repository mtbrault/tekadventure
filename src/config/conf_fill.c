/*
** conf_fill.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Wed May  3 17:51:14 2017 LAABID Zakaria
** Last update Sat May 13 19:28:57 2017 LAABID Zakaria
*/

#include <stdlib.h>
#include <unistd.h>
#include "config.h"

int		config_fill(char **argv)
{
  t_level	**level;
  char		**conf;
  int		y;

  y = 0;
  if ((conf = conf_init(argv)) == NULL)
    return (-1);
  if ((level = config_data(conf)) == NULL)
    return (-1);
  while (y < conf_counter(conf, CONF_LEVEL))
    {
      config_map_fill(level, conf, y);
      config_telep_fill(level, conf, y);
      config_mob_fill(level, conf, y);
      config_event_fill(level, conf, y);
      y++;
    }
  return (0);
}
