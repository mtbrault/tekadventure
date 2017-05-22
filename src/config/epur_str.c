/*
** epur_str.c for  in /home/BlackBIrdz/tekadventure/src/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Mon May 22 17:08:11 2017 LAABID Zakaria
** Last update Mon May 22 17:08:12 2017 LAABID Zakaria
*/

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*epur_str(char *str)
{
  char	*new_str;
  int	i;
  int	k;

  i = 0;
  k = 0;
  new_str = malloc(sizeof(char *) * my_strlen(str));
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] != '\0')
    {
      if ((str[i] != ' ' || str[i + 1] != ' ') &&
	  (str[i] != '\t' || str[i + 1] != '\t'))
	new_str[k++] = str[i];
      i++;
    }
  new_str[k] = '\0';
  if (new_str[k - 1] == ' ' || new_str[k - 1] == '\t')
    new_str[k - 1] = '\0';
  return (new_str);
}
