/*
** conf_verif.c for  in /home/BlackBIrdz/tekadventure/src/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Thu May 25 15:49:35 2017 LAABID Zakaria
** Last update Thu May 25 18:44:49 2017 LAABID Zakaria
*/

#include <tekadv.h>
#include "config.h"

static int	conf_line(char **conf)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (conf[i] != NULL)
    {
      if (conf[i][0] != '#')
	count++;
      i++;
    }
  return (count);
}

int		is_commentary(char **conf)
{
  int		y;

  y = 0;
  while (conf[y] != NULL)
    {
      if (conf[y][0] == '#')
	return (1);
      y++;
    }
  return (0);
}

char		**del_commentary(char **conf)
{
  char		**new_conf;
  int		y;
  int		x;

  y = 0;
  x = 0;
  if ((is_commentary(conf)) == 0)
    return (conf);
  if ((new_conf = malloc(sizeof(char *) * (conf_line(conf)))) == NULL)
    {
      my_puterr(ERRCONF_DEL, 0);
      return (NULL);
    }
  while (conf[y] != NULL)
    {
      if (conf[y][0] != '#')
	{
	  if ((new_conf[x] = my_strdup(conf[y])) == NULL)
	    {
	      my_puterr(ERRCONF_DEL, 0);
	      return (NULL);
	    }
	  x++;
	}
      y++;
    }
  conf[y] = NULL;
  return (new_conf);
}
