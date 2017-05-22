/*
** conf_fill.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Wed May  3 17:51:14 2017 LAABID Zakaria
** Last update Mon May 22 15:48:12 2017 LAABID Zakaria
*/

#include <stdlib.h>
#include <unistd.h>
#include "config.h"
#include "tekadv.h"

t_game		*config_fill(char **argv)
{
  t_game	*game;
  char		**conf;
  int		y;

  y = 0;
  if ((game = malloc(sizeof(t_game))) == NULL)
    return (NULL);
  game->map_status = 0;
  if ((conf = conf_init(argv)) == NULL)
    return (NULL);
  if ((game->level = config_data(conf)) == NULL)
    return (NULL);
  while (y < conf_counter(conf, CONF_LEVEL))
    {
      config_map_fill(game->level, conf, y);
      config_telep_fill(game->level, conf, y);
      config_mob_fill(game->level, conf, y);
      config_event_fill(game->level, conf, y);
      y++;
    }
  return (game);
}
