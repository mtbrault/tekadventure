/*
** conf_teleports_utils.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Mon May  8 00:40:07 2017 LAABID Zakaria
** Last update Sat May 27 01:21:43 2017 LAABID Zakaria
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
  if ((start2 = my_strcat(CONF_LEVEL, my_str_nbr(y))) == NULL ||
      (end = my_strcat(CONF_LEVEL, my_str_nbr(y + 1))) == NULL)
    return (-1);
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
      if ((start = my_strcat(TELEP_TYPE, my_str_nbr(x))) == NULL ||
	  (end = my_strcat(TELEP_TYPE, my_str_nbr(x + 1))) == NULL ||
	  (i = config_telep_goto(start, conf, y)) < 0)
	return (0);
      while (conf[i] != NULL)
	{
	  if (my_strncmp(TELEP_NAME, conf[i], L_TPNAME) == 0)
	    level[y]->tp[x - 1]->next_map = unquote(conf[i] + L_TPNAME + 2);
	  if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	    break;
	  else if ((my_strncmp(MOBS, conf[i], L_MOB)) == 0 ||
		   (my_strncmp(CONF_LEVEL, conf[i], L_CONF) == 0)
		   || conf[i] == NULL)
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
  int	j;

  while (x <= getconf_index(conf, TELEP_NB, y))
    {
      start = my_strcat(TELEP_TYPE, my_str_nbr(x));
      end = my_strcat(TELEP_TYPE, my_str_nbr(x + 1));
      i = config_telep_goto(start, conf, y);
      while (conf[i] != NULL)
	{
	  if (my_strncmp(TELEP_COORD, conf[i], L_COORD) == 0)
	    {
	      j = 0;
	      while (conf[i][8 + j] != ',')
		j += 1;
	      j += 1;
	      level[y]->tp[x - 1]->coords[0] = my_atoi(conf[i] + 8);
	      level[y]->tp[x - 1]->coords[1] = my_atoi(conf[i] + 8 + j);
	    }
	  if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	    break;
	  else if ((my_strncmp(MOBS, conf[i], L_MOB)) == 0 ||
		   (my_strncmp(CONF_LEVEL, conf[i], L_CONF) == 0)
		   || conf[i] == NULL)
	    break;
	  i++;
	}
      x++;
    }
  return (0);
}

int	config_telep_three(t_level **level, char **conf, int x, int y)
{
  char	*start;
  char	*end;
  int	i;

  while (x <= getconf_index(conf, TELEP_NB, y))
    {
      if ((start = my_strcat(TELEP_TYPE, my_str_nbr(x))) == NULL ||
	  (end = my_strcat(TELEP_TYPE, my_str_nbr(x + 1))) == NULL ||
	  (i = config_telep_goto(start, conf, y)) < 0)
	return (0);
      while (conf[i] != NULL)
	{
	  if (my_strncmp(TELEP_TILE, conf[i], L_TILE) == 0)
	    level[y]->tp[x - 1]->path_tile = unquote(conf[i] + L_TILE + 2);
	  if (my_strncmp(TELEP_LOAD, conf[i], L_LOAD) == 0)
	    level[y]->tp[x - 1]->load = my_atoi(conf[i] + L_LOAD);
	  if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	    break;
	  else if ((my_strncmp(MOBS, conf[i], L_MOB)) == 0 ||
		   (my_strncmp(CONF_LEVEL, conf[i], L_CONF) == 0)
		   || conf[i] == NULL)
	    break;
	  i++;
	}
      x++;
    }
  return (0);
}
