/*
** conf_manager.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Fri May  5 14:44:37 2017 LAABID Zakaria
** Last update Mon May 22 16:42:43 2017 LAABID Zakaria
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "config.h"

int	conf_counter(char **conf, char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (conf[i] != NULL)
    {
      if ((my_strncmp(str, conf[i], my_strlen(str))) == 0)
	count++;
      i++;
    }
  return (count);
}

char	**conf_init(char **argv)
{
  char	config[4096];
  char	**conf;
  int	fd;
  int	i;

  i = 0;
  fd = open(argv[1], O_RDONLY);
  read(fd, config, 4096);
  conf = wordtab(config, '\n');
  while (conf[++i] != NULL)
    conf[i] = epur_str(conf[i]);
  return (conf);
}

t_level		**config_data(char **conf)
{
  int		x;
  t_level	**level;

  x = 0;
  if ((level = malloc(sizeof(t_level))) == NULL)
    return (NULL);
  if ((level = gen_config_space(level, conf)) == NULL)
    return (NULL);
  while (x < conf_counter(conf, CONF_LEVEL))
    {
      gen_mob_space(level, conf, x);
      gen_event_space(level, conf, x);
      gen_telep_space(level, conf, x);
      x++;
    }
  gen_config_space(level, conf);
  return (level);
}

void	conf_disp(char **conf)
{
  int	i;

  i = 0;
  while (conf[i] != NULL)
    {
      my_putstr(conf[i++]);
      my_putchar('\n');
    }
  return ;
}
