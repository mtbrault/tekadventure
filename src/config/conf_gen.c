/*
** conf_gen.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Wed May  3 19:09:27 2017 LAABID Zakaria
** Last update Fri May 26 16:21:38 2017 Capitaine CASSE
*/

#include <stdlib.h>
#include <unistd.h>
#include "config.h"

t_level		**gen_event_space(t_level **level, char **conf, int index)
{
  int	size_event;
  int	i;

  i = 0;
  size_event = getconf_index(conf, EVENT_NB, index);
  if ((level[index]->event = malloc(sizeof(t_event) * (size_event + 1))) == NULL)
    return (NULL);
  while (i < size_event)
    {
      if ((level[index]->event[i] = malloc(sizeof(t_event))) == NULL)
	return (NULL);
      i += 1;
    }
  level[index]->event[size_event] = NULL;
  return (level);
}

t_level		**gen_telep_space(t_level **level, char **conf, int index)
{
  int	size_tp;
  int	i;

  i = 0;
  //  printf("hellol %d\n", index);
  size_tp = getconf_index(conf, TELEP_NB, index);
  if ((level[index]->tp = malloc(sizeof(t_tp) * (size_tp + 1))) == NULL)
    return (NULL);
  while (i < size_tp)
    {
      //  printf("malloc %d %d\n", index, i);
      if ((level[index]->tp[i] = malloc(sizeof(t_tp))) == NULL)
	return (NULL);
      i += 1;
    }
  level[index]->tp[size_tp] = NULL;
  return (level);
}

t_level		**gen_mob_space(t_level **level, char **conf, int index)
{
  int	size_mob;
  int	i;

  i = 0;
  size_mob = getconf_index(conf, MOBS_NB, index);
  if ((level[index]->mob = malloc(sizeof(t_mob) * (size_mob + 1))) == NULL)
    return (NULL);
  while (i < size_mob)
    {
      if ((level[index]->mob[i] = malloc(sizeof(t_mob))) == NULL)
	return (NULL);
      i += 1;
    }
  level[index]->mob[size_mob] = NULL;
  return (level);
}

t_level		**gen_config_space(t_level **level, char **conf)
{
  int	        size_level;
  int		i;

  size_level = conf_counter(conf, CONF_LEVEL);
  i = 0;
  if ((level = malloc(sizeof(t_level) * (size_level + 1))) == NULL)
    return (NULL);
  while (i < size_level)
    {
      if ((level[i] = malloc(sizeof(t_level))) == NULL)
	return (NULL);
      i += 1;
    }
  level[size_level] = NULL;
  return (level);
}
