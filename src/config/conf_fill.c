/*
** conf_fill.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Wed May  3 17:51:14 2017 LAABID Zakaria
** Last update Sat May 27 01:14:40 2017 LAABID Zakaria
*/

#include "config.h"
#include "tekadv.h"

static int	free_conf(char **conf)
{
  int		i;

  i = 0;
  while (conf[i])
    {
      free(conf[i]);
      i += 1;
    }
  free(conf);
  return (0);
}

int	is_here(char **conf, char *str, const int y)
{
  char		*start2;
  char		*end;
  int		i;

  i = 0;
  if ((start2 = my_strcat(CONF_LEVEL, my_str_nbr(y))) == NULL ||
      (end = my_strcat(CONF_LEVEL, my_str_nbr(y + 1))) == NULL)
    return (FAIL);
  while (conf[i] != NULL)
    {
      if (my_strncmp(start2, conf[i], my_strlen(start2)) == 0)
	break;
      i++;
    }
  while (conf[i] != NULL)
    {
      if ((my_strncmp(str, conf[i], my_strlen(str))) == 0)
	return (0);
      if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	return (FAIL);
      i++;
    }
  return (FAIL);
}

/* int		check_conf(t_level **lvl) */
/* { */
/*   int	i; */
/*   int	j; */
/*   int	k; */
/*   t_map		*maptmp; */
/*   t_tp		**tptmp; */
/*   int		**map; */

/*   i = 0; */
/*   while (lvl[i] != NULL) */
/*     { */
/*       if ((maptmp = (lvl[i])->map) == NULL || maptmp->name == NULL) */
/*       	printf("map NULL\n"); */
/*       else */
/*   	printf("name %s %s %s\n", maptmp->name, maptmp->bg, maptmp->music); */
/*       if ((tptmp = (lvl[i])->tp) != NULL) */
/*   	{ */
/*   	  while (*tptmp != NULL) */
/*   	    { */
/*   	      printf("tp %s %d %d\n", (*tptmp)->next_map, (*tptmp)->coords[0], (*tptmp)->coords[1]); */
/*   	      tptmp += 1; */
/*   	    } */
/*   	} */
/*       map = lvl[i]->map->content; */
/*       int	l; */
/*       k = 0; */
/*       while (map[k] != NULL) */
/* 	{ */
/* 	  l = 0; */
/* 	  while (map[k][l] != -42) */
/* 	    { */
/* 	      printf("%d ", map[k][l]); */
/* 	      l += 1; */
/* 	    } */
/* 	  printf("\n"); */
/* 	  k += 1; */
/* 	} */
/*       i += 1; */
/*     } */
/*   return (0); */
/* } */

t_game		*config_fill(char **argv)
{
  t_game	*game;
  t_level	**level;
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
  if ((level = config_data(conf)) == NULL)
    return (NULL);
  while (y < conf_counter(conf, CONF_LEVEL))
    {
      config_map_fill(level, conf, y);
      if (is_here(conf, "teleporter:", y + 1) == 0)
      	config_telep_fill(level, conf, y);
      if (is_here(conf, "mobs:", y + 1) == 0)
      	config_mob_fill(level, conf, y);
      if (is_here(conf, "event:", y + 1) == 0)
      	config_event_fill(level, conf, y);
      y++;
    }
  //  check_conf(level);
  game->level = build_graph(level);
  free_conf(conf);
  return (game);
}
