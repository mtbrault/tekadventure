/*
** conf_map.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Thu May  4 00:39:48 2017 LAABID Zakaria
** Last update Fri May 26 16:58:56 2017 Capitaine CASSE
*/

#include <stdlib.h>
#include <unistd.h>
#include "config.h"

int	map_content_index(char **conf, int index)
{
  int	count;

  count = 0;
  if (conf[index] != NULL)
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

int	**map_content_fill(char **conf, int i, char *end)
{
  int	**content;
  int	x;

  while (conf[i] != NULL)
    {
      if ((my_strncmp(MAP_CONTENT, conf[i], my_strlen(MAP_CONTENT))) == 0)
        break;
      if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	break;
      i++;
    }
  if ((content = malloc(sizeof(int *) * (map_content_index(conf, i) + 1)))
      == NULL)
    return (NULL);
  content[map_content_index(conf, i)] = NULL;
  if (conf[i] != NULL)
    i += 1;
  x = 0;
  int	k;
  while (conf[i] != NULL)
    {
      k = 0;
      if ((content[x++] = my_intdup(conf[i++])) == NULL)
	return (NULL);
      while (content[x - 1][k] != -42)
	{
	  printf("%d ", content[x - 1][k]);
	  k += 1;
	}
      printf("\n");
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
    {
      //      printf("cmp %s %s\n", start, conf[i]);
      if (my_strncmp(start, conf[i++], my_strlen(start)) == 0)
	break;
    }
  while (conf[i] != NULL)
    {
      if ((my_strncmp(MAP_NAME, conf[i], my_strlen(MAP_NAME)) == 0))
	level[index]->map->name = unquote(conf[i] + my_strlen(MAP_NAME) + 1);
      if ((my_strncmp(MAP_BG, conf[i], my_strlen(MAP_BG)) == 0))
	level[index]->map->bg = unquote(conf[i] + my_strlen(MAP_BG) + 1);
      if ((my_strncmp(end, conf[i], my_strlen(end)) == 0))
	break;
      i++;
    }
  printf("%s\n", level[index]->map->name);
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
  while (conf[i] != NULL)
    if (my_strncmp(start, conf[i++], my_strlen(start)) == 0)
      break;
  i = 0;
  while (conf[i] != NULL)
    if (my_strncmp(start, conf[i++], my_strlen(start)) == 0)
      break;
  printf("fill %d\n", index);
  level[index]->map->content = map_content_fill(conf, i, end);
  return (level);
}

t_level	**config_map_fill_three(t_level **level, char **conf, int index)
{
  char	*start;
  char	*end;
  int	i;
  int	y;

  i = 0;
  y = index + 1;
  start = my_strcat(CONF_LEVEL, my_str_nbr(y));
  end = my_strcat(CONF_LEVEL, my_str_nbr(y + 1));
  while (conf[i] != NULL)
    if (my_strncmp(start, conf[i++], my_strlen(start)) == 0)
      break;
  while (conf[i] != NULL)
    {
      if ((my_strncmp(MAP_MUSIC, conf[i], my_strlen(MAP_MUSIC)) == 0))
	level[index]->map->music = unquote(conf[i] + my_strlen(MAP_MUSIC) + 1);
      if ((my_strncmp(end, conf[i], my_strlen(end)) == 0))
	break;
      i++;
    }
  return (level);
}

t_level	**config_map_fill(t_level **level, char **conf, int index)
{
  config_map_fill_one(level, conf, index);
  config_map_fill_two(level, conf, index);
  config_map_fill_three(level, conf, index);
  return (level);
}
