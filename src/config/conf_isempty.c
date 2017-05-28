/*
** conf_isempty.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sun May 28 14:53:41 2017 LAABID Zakaria
** Last update Sun May 28 15:30:42 2017 LAABID Zakaria
*/

#include <fcntl.h>
#include "config.h"
#include "tekadv.h"

int     conf_isempty(t_level **level, char **conf)
{
  int	y;

  y = 0;
  while (y < conf_counter(conf, CONF_LEVEL))
    {
      if ((map_verif(level[y]->map)) == FAIL ||
	  (map_verif_second(level[y]->map)) == FAIL)
	return (FAIL);
      y++;
    }
  return (0);
}
