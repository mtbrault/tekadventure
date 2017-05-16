/*
** conf_events_utils.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Mon May  8 00:39:58 2017 LAABID Zakaria
** Last update Sat May 13 19:34:25 2017 LAABID Zakaria
*/

#include <stdlib.h>
#include <unistd.h>
#include "config.h"

int	config_event_goto(char *start, char **conf, int y)
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

int	config_event_one(t_level **level, char **conf, int x, int y)
{
  char	*start;
  char	*end;
  int	i;

  while (x <= getconf_index(conf, EVENT_NB, y))
    {
      start = my_strcat(EVENT_TYPE, my_str_nbr(x));
      end = my_strcat(EVENT_TYPE, my_str_nbr(x + 1));
      i = config_event_goto(start, conf, y);
      while (conf[i] != NULL)
	{
	  if (my_strncmp(EVENT_NAME, conf[i], L_NAME) == 0)
	    level[y]->event[x - 1]->name = unquote((conf[i] + L_NAME));
	  if (my_strncmp(EVENT_TEXT, conf[i], L_TEXT) == 0)
	    level[y]->event[x - 1]->texture = unquote((conf[i] + L_TEXT));
	  if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	    break;
	  else if ((my_strncmp(CONF_LEVEL, conf[i], L_CONF)) == 0)
	    break;
	  i++;
	}
      x++;
    }
  return (0);
}

int	config_event_two(t_level **level, char **conf, int x, int y)
{
  char	*start;
  char	*end;
  int	i;

  while (x <= getconf_index(conf, EVENT_NB, y))
    {
      start = my_strcat(EVENT_TYPE, my_str_nbr(x));
      end = my_strcat(EVENT_TYPE, my_str_nbr(x + 1));
      i = config_goto(start, conf, y);
      while (conf[i] != NULL)
	{
	  if (my_strncmp(EVENT_COORD, conf[i], L_COORD) == 0)
	    {
	      level[y]->event[x - 1]->coords[0] = conf[i][8] - '0';
	      level[y]->event[x - 1]->coords[1] = conf[i][10] - '0';
	    }
	  if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	    break;
	  else if ((my_strncmp(CONF_LEVEL, conf[i], L_CONF)) == 0)
	    break;
	  i++;
	}
      x++;
    }
  return (0);
}
