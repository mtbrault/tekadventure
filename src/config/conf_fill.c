/*
** conf_fill.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Wed May  3 17:51:14 2017 LAABID Zakaria
** Last update Thu May 25 20:10:27 2017 LAABID Zakaria
*/

#include "config.h"
#include "tekadv.h"

int		is_here(char **conf, char *str, int y)
{
  char		*start2;
  char		*end;
  int		i;

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
      if ((my_strcmp(str, conf[i], my_strlen(str))) == 0)
	return (0);
      if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	return (FAIL);
      i++;
    }
  return (FAIL);
}

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
  if ((conf_counter(conf, CONF_LEVEL)) == 0)
    {
      my_puterr(ERRCONF_CONF, 0);
      return (NULL);
    }
  if ((game->level = config_data(conf)) == NULL)
    return (NULL);
  while (y < conf_counter(conf, CONF_LEVEL))
    {
      config_map_fill(game->level, conf, y);
      if (is_here(conf, "teleporter:", y) == 0)
	config_telep_fill(game->level, conf, y);
      if (is_here(conf, "mobs:", y) == 0)
	config_mob_fill(game->level, conf, y);
      if (is_here(conf, "event:", y) == 0)
	config_event_fill(game->level, conf, y);
      y++;
    }
  my_putstr(game->level[0]->map->music); 
  return (game);
}
