/*
** conf_manager.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Fri May  5 14:44:37 2017 LAABID Zakaria
** Last update Thu May 25 20:09:04 2017 LAABID Zakaria
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "config.h"

int		conf_counter(char **conf, char *str)
{
  int		i;
  int		count;

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

char		**conf_init(char **argv)
{
  char		config[4096];
  char		**conf;
  int		fd;
  int		i;

  i = 0;
  if (check_file(argv[1]) == -1)
    {
      my_puterr(ERRCONF_NAME, 0);
      return (NULL);
    }
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
      my_puterr(ERRCONF_OPEN, 0);
      return (NULL);
    }
  read(fd, config, 4096);
  if ((conf = wordtab(config, '\n')) == NULL)
    return (NULL);
  while (conf[i] != NULL)
    {
      conf[i] = epur_str(conf[i]);
      i++;
    }
  /* if ((conf = del_commentary(conf)) == NULL) */
  /*   return (NULL); */
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
      if ((is_here(conf, "mobs:", x)) == 0)
	gen_mob_space(level, conf, x);
      if ((is_here(conf, "event:", x)) == 0)
	gen_event_space(level, conf, x);
      if ((is_here(conf, "teleporter:", x)) == 0)
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
}
