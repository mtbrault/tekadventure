/*
** conf_lexing.c for  in /home/BlackBIrdz/tekadventure/src/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sun May 28 13:33:12 2017 LAABID Zakaria
** Last update Sun May 28 18:06:48 2017 LAABID Zakaria
*/

#include "tekadv.h"
#include "config.h"

t_line	line[4]=
{
  {"map:", 0},
  {"map-content:", 0},
  {"teleporter:", 0},
  {"event:", 0},
};

int	config_verif_goto(char *start, char **conf, int y)
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

int	conf_lexing(char **conf)
{
  char	*start;
  char	*end;
  int	i;
  int	y;
  int	next;

  y = 0;
  while (y < conf_counter(conf, CONF_LEVEL))
    {
      if ((start = my_strcat(CONF_LEVEL, my_str_nbr(y + 1))) != NULL &&
	  (end = my_strcat(CONF_LEVEL, my_str_nbr(y + 2))) != NULL &&
	  (i = config_verif_goto(start, conf, y)) >= 0)
	{
	  next = 0;
	  while (next < 4)
	    {
	      i = 0;
	      while (conf[i] != NULL)
		{
		  if (my_strncmp(line[next].conf, conf[i], my_strlen(conf[i])) == 0)
		    {
		      line[next].find = 1;
		      break;
		    }
		  if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
		    break;
		  i++;
		}
	      next++;
	    }
	  y++;
	}
      next = 0;
      while (next < 4)
	{
	  if (line[next].find == 0)
	    {
	      my_puterr("Error config file on:\n", 0);
	      my_puterr(line[next].conf, 0);
	      return (FAIL);
	    }
	  next++;
	}
    }
  return (0);
}
