/*
** my_strdup.c for libkaas in /home/antoine.casse/Desktop/Lib
** 
** Made by Antoine Casse
** Login   <antoine.casse@epitech.net>
** 
** Started on  Mon Jan 23 15:42:26 2017 Antoine Casse
** Last update Tue Jan 24 16:29:04 2017 Antoine Casse
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
