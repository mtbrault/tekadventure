/*
** conf_map.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Thu May  4 00:39:48 2017 LAABID Zakaria
** Last update Mon May 22 15:54:54 2017 LAABID Zakaria
*/

#include <stdlib.h>
#include <unistd.h>
#include "config.h"

int	map_content_index(char **conf, int index)
{
  int	count;

  count = 0;
  index++;
  while (conf[index] != NULL)
    {
      if ((my_strncmp(MAP_START, conf[index], my_strlen(MAP_START))) == 0)
        return (count);
      index++;
      count++;
    }
  return (count);
}

char	**map_content_fill(char **conf, int i, char *end)
{
  char	**content;
  int	x;

  while (conf[i] != NULL)
    {
      if ((my_strncmp(MAP_CONTENT, conf[i], my_strlen(MAP_CONTENT))) == 0)
        break;
      if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	break;
      i++;
    }
  content = malloc(sizeof(char *) * map_content_index(conf, i));
  i++;
  x = 0;
  while (conf[i] != NULL)
    {
      content[x++] = my_strdup(conf[i]);
      i++;
      if ((my_strncmp(MAP_START, conf[i], my_strlen(MAP_START))) == 0)
	return (content);
      if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	break;
    }
  return (content);
}

t_level	**config_map_fill_one(t_level **level, char **conf, int index)
{
  char	*start;
  char	*end;
  int	i;
  int	y;

  i = 0;
  y = index + 1;
  start = my_strcat(CONF_LEVEL, my_str_nbr(y));
  end = my_strcat(CONF_LEVEL, my_str_nbr(y + 1));
  if ((level[index]->map = malloc(sizeof(t_map))) == NULL)
    return (NULL);
  while (conf[i] != NULL)
    if (my_strncmp(start, conf[i++], my_strlen(start)) == 0)
      break;
  while (conf[i] != NULL)
    {
      if ((my_strncmp(MAP_NAME, conf[i], my_strlen(MAP_NAME)) == 0))
	level[index]->map->name = unquote(conf[i] + my_strlen(MAP_NAME));
      if ((my_strncmp(MAP_BG, conf[i], my_strlen(MAP_BG)) == 0))
	level[index]->map->bg = unquote(conf[i] + my_strlen(MAP_BG));
      if ((my_strncmp(end, conf[i], my_strlen(end)) == 0))
	break;
      i++;
    }
  return (level);
}

t_level	**config_map_fill_two(t_level **level, char **conf, int index)
{
  char	*start;
  char	*end;
  int	i;
  int	y;

  i = 0;
  y = index + 1;
  start = my_strcat(CONF_LEVEL, my_str_nbr(y));
  end = my_strcat(CONF_LEVEL, my_str_nbr(y + 1));
  if ((level[index]->map = malloc(sizeof(t_map))) == NULL)
    return (NULL);
  while (conf[i] != NULL)
    if (my_strncmp(start, conf[i++], my_strlen(start)) == 0)
      break;
  i = 0;
  while (conf[i] != NULL)
    if (my_strncmp(start, conf[i++], my_strlen(start)) == 0)
      break;
  level[index]->map->content = map_content_fill(conf, i, end);
  return (level);
}

t_level	**config_map_fill(t_level **level, char **conf, int index)
{
  config_map_fill_one(level, conf, index);
  config_map_fill_two(level, conf, index);
  return (level);
}
