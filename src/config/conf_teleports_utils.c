/*
** conf_teleports_utils.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Mon May  8 00:40:07 2017 LAABID Zakaria
** Last update Mon May 22 17:04:17 2017 LAABID Zakaria
*/

#include <stdlib.h>
#include <unistd.h>
#include "config.h"

int	config_telep_goto(char *start, char **conf, int y)
{
  char	*start2;
  char	*end;
  int	i;

  i = 0;
  y++;
  start2 = my_strcat(CONF_LEVEL, my_str_nbr(y));
  end = my_strcat(CONF_LEVEL, my_str_nbr(y+1));
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

int	config_telep_one(t_level **level, char **conf, int x, int y)
{
  char	*start;
  char	*end;
  int	i;

  while (x <= getconf_index(conf, TELEP_NB, y))
    {
      start = my_strcat(TELEP_TYPE, my_str_nbr(x));
      end = my_strcat(TELEP_TYPE, my_str_nbr(x + 1));
      i = config_telep_goto(start, conf, y);
      while (conf[i] != NULL)
	{
	  if (my_strncmp(TELEP_NAME, conf[i], L_TPNAME) == 0)
	    level[y]->tp[x - 1]->next_map = unquote((conf[i] + L_TPNAME));
	  if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	    break;
	  else if ((my_strncmp(MOBS, conf[i], L_MOB)) == 0)
	    break;
	  i++;
	}
      x++;
    }
  return (0);
}

int	config_telep_two(t_level **level, char **conf, int x, int y)
{
  char	*start;
  char	*end;
  int	i;

  while (x <= getconf_index(conf, TELEP_NB, y))
    {
      start = my_strcat(TELEP_TYPE, my_str_nbr(x));
      end = my_strcat(TELEP_TYPE, my_str_nbr(x + 1));
      i = config_telep_goto(start, conf, y);
      while (conf[i] != NULL)
	{
	  if (my_strncmp(TELEP_COORD, conf[i], L_COORD) == 0)
	    {
	      level[y]->mob[x - 1]->coords[0] = my_atoi(conf[i] + 8);
	      level[y]->mob[x - 1]->coords[1] = my_atoi(conf[i] + 11);
	    }
	  if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	    break;
	  else if ((my_strncmp(MOBS, conf[i], L_MOB)) == 0)
	    break;
	  i++;
	}
      x++;
    }
  return (0);
}
