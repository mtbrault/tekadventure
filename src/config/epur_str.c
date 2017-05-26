/*
** epur_str.c for  in /home/BlackBIrdz/tekadventure/src/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Mon May 22 17:08:11 2017 LAABID Zakaria
** Last update Fri May 26 13:48:53 2017 Capitaine CASSE
*/

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	get_size(char *str)
{
  int		i;
  int		nb;
  char		stop;

  i = 0;
  nb = 0;
  stop = 1;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t' && str[i] != '\v')
	{
	  if (!stop)
	    {
	      nb += 1;
	      stop = 1;
	    }
	  nb += 1;
	}
      else
	stop = 0;
      i += 1;
    }
  return (nb);
}

char	*epur_str(char *str)
{
  char	*res;
  int	i;
  int	j;
  char	stop;

  if (str == NULL)
    return (NULL);
  while (*str == ' ' || *str == '\t' || *str == '\v')
    str += 1;
  i = get_size(str);
  if ((res = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (NULL);
  res[i] = 0;
  i = 0;
  j = 0;
  stop = 1;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t' && str[i] != '\v')
	{
	  if (!stop)
	    {
	      res[j++] = ' ';
	      stop = 1;
	    }
	  res[j++] = str[i];
	}
      else
	stop = 0;
      i += 1;
    }
  return (res);
}
