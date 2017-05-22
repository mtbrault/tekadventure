/*
** my_strdup.c for libkaas in /home/antoine.casse/Desktop/Lib
** 
** Made by Antoine Casse
** Login   <antoine.casse@epitech.net>
** 
** Started on  Mon Jan 23 15:42:26 2017 Antoine Casse
** Last update Mon May 22 15:52:26 2017 LAABID Zakaria
*/

#include "lkaas.h"

char	*my_strdup(char *str)
{
  int	i;
  char	*res;

  i = 0;
  res = malloc(my_strlen(str));
  while (str[i])
    {
      res[i] = str[i];
      i += 1;
    }
  return (res);
}

int	*my_intdup(char *str)
{
  int	i;
  int	*res;

  i = 0;
  res = malloc(my_strlen(str));
  while (str[i])
    {
      res[i] = str[i] - '0';
      i += 1;
    }
  return (res);
}
