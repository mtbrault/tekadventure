/*
** conf_mobs_utils.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Thu May  4 22:14:14 2017 LAABID Zakaria
** Last update Sat May 27 04:03:46 2017 LAABID Zakaria
*/

#include <stdlib.h>
#include <unistd.h>
#include "config.h"

int	config_mob_one(t_level **level, char **conf, int x, int y)
{
  char	*start;
  char	*end;
  int	i;

  while (x <= getconf_index(conf, MOBS_NB, y))
    {
      start = my_strcat(MOBS_TYPE, my_str_nbr(x));
      end = my_strcat(MOBS_TYPE, my_str_nbr(x + 1));
      i = config_goto(start, conf, y);
      while (conf[i] != NULL)
	{
	  if (my_strncmp(MOBS_NAME, conf[i], L_NAME) == 0)
	    level[y]->mob[x - 1]->name = unquote((conf[i] + L_NAME));
	  if (my_strncmp(MOBS_TEXT, conf[i], L_TEXT) == 0)
	    level[y]->mob[x - 1]->texture = unquote((conf[i] + L_TEXT));
	  if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	    break;
	  else if ((my_strncmp(EVENT, conf[i], L_EVENT)) == 0 ||
		   ((my_strncmp(CONF_LEVEL, conf[i], L_CONF)) == 0) ||
		   conf[i] == NULL)
	    break;
	  i++;
	}
      x++;
    }
  return (0);
}

int	config_mob_two(t_level **level, char **conf, int x, int y)
{
  char	*start;
  char	*end;
  int	i;

  while (x <= getconf_index(conf, MOBS_NB, y))
    {
      start = my_strcat(MOBS_TYPE, my_str_nbr(x));
      end = my_strcat(MOBS_TYPE, my_str_nbr(x + 1));
      i = config_goto(start, conf, y);
      while (conf[i] != NULL)
	{
	  if (my_strncmp(MOBS_LIFE, conf[i], L_LIFE) == 0)
	    level[y]->mob[x - 1]->life = nbrepur((conf[i] + L_LIFE));
	  if (my_strncmp(MOBS_DMG, conf[i], L_DMG) == 0)
	    level[y]->mob[x - 1]->damage = nbrepur((conf[i] + L_DMG));
	  if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	    break;
	  else if ((my_strncmp(EVENT, conf[i], L_EVENT)) == 0 ||
		   ((my_strncmp(CONF_LEVEL, conf[i], L_CONF)) == 0) ||
		   conf[i] == NULL)
	    break;
	  i++;
	}
      x++;
    }
  return (0);
}

int	config_mob_three(t_level **level, char **conf, int x, int y)
{
  char	*start;
  char	*end;
  int	i;

  while (x <= getconf_index(conf, MOBS_NB, y))
    {
      start = my_strcat(MOBS_TYPE, my_str_nbr(x));
      end = my_strcat(MOBS_TYPE, my_str_nbr(x + 1));
      i = config_goto(start, conf, y);
      while (conf[i] != NULL)
	{
	  if (my_strncmp(MOBS_PM, conf[i], L_PM) == 0)
	    level[y]->mob[x - 1]->pm = nbrepur((conf[i] + L_PM));
	  if (my_strncmp(MOBS_PA, conf[i], L_PA) == 0)
	    level[y]->mob[x - 1]->pa = nbrepur((conf[i] + L_PA));
	  if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	    break;
	  else if ((my_strncmp(EVENT, conf[i], L_EVENT)) == 0 ||
		   ((my_strncmp(CONF_LEVEL, conf[i], L_CONF)) == 0) ||
		   conf[i] == NULL)
	    break;
	  i++;
	}
      x++;
    }
  return (0);
}

int	config_mob_four(t_level **level, char **conf, int x, int y)
{
  char	*start;
  char	*end;
  int	i;

  while (x <= getconf_index(conf, MOBS_NB, y))
    {
      start = my_strcat(MOBS_TYPE, my_str_nbr(x));
      end = my_strcat(MOBS_TYPE, my_str_nbr(x + 1));
      i = config_goto(start, conf, y);
      while (conf[i] != NULL)
	{
	  if (my_strncmp(MOBS_COORD, conf[i], L_COORD) == 0)
	    {
	      level[y]->mob[x - 1]->coords[0] = my_atoi(conf[i] + 8);
	      level[y]->mob[x - 1]->coords[1] = my_atoi(conf[i] + 11);
	    }
	  if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	    break;
	  else if ((my_strncmp(EVENT, conf[i], L_EVENT)) == 0 ||
		   ((my_strncmp(CONF_LEVEL, conf[i], L_CONF)) == 0) ||
		   conf[i] == NULL)
	    break;
	  i++;
	}
      x++;
    }
  return (0);
}
