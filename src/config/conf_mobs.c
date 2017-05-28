/*
** conf_mobs.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Thu May  4 00:42:07 2017 LAABID Zakaria
** Last update Sun May 28 12:40:22 2017 Capitaine CASSE
*/

#include <stdlib.h>
#include <unistd.h>
#include "config.h"

int	config_goto(char *start, char **conf, int y)
{
  char	*start2;
  char	*end;
  int	i;

  i = 0;
  y++;
  start2 = my_strcat(CONF_LEVEL, my_str_nbr(y));
  end = my_strcat(CONF_LEVEL, my_str_nbr(y + 1));
  while (conf[i] != NULL)
    {
      if (my_strncmp(start2, conf[i], my_strlen(start2)) == 0)
	break;
      i++;
    }
  while (conf[i] != NULL)
    {
      if ((my_strncmp(start, conf[i], my_strlen(start))) == 0)
	return (i);
      if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	break;
      i++;
    }
  return (i);
}

int	config_mob_fill(t_level **level, char **conf, int y)
{
  int	x;

  x = 1;
  config_mob_one(level, conf, x, y);
  config_mob_two(level, conf, x, y);
  config_mob_three(level, conf, x, y);
  config_mob_four(level, conf, x, y);
  return (0);
}
