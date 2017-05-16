/*
** conf_utils.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Mon May 15 13:46:01 2017 LAABID Zakaria
** Last update Tue May 16 14:32:51 2017 LAABID Zakaria
*/

#include <stdlib.h>
#include <unistd.h>
#include "config.h"

char	*getconf(char **conf, char *str)
{
  int	index;
  int	size_str;

  index = 0;
  size_str = my_strlen(str);
  while (conf[index] != NULL)
    {
      if (my_strncmp(str, conf[index], size_str) == 0)
	return ((char *)(conf[index] + size_str));
      ++index;
    }
  return (NULL);
}

int	getconf_nbr(char **conf, char *str)
{
  int	nbr;
  char	*new_str;

  new_str = epur_str(getconf(conf, str));
  nbr = my_atoi(new_str);
  return (nbr);
}

int	nbrepur(char *str)
{
  char *str2;

  str2 = epur_str(str);
  return (my_atoi(str2));
}

char	*unquote(char *str)
{
  int	i;
  int	y;
  char	*new_str;

  y = 0;
  i = 0;
  str = epur_str(str);
  if ((new_str = malloc(sizeof(char) * (my_strlen(str) - 1))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (str[i] == '"')
	i++;
      new_str[y++] = str[i++];
    }
  new_str[y - 1] = '\0';
  return (new_str);
}
