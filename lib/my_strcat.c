/*
** my_strcat.c for libkaas in /home/antoine.casse/Desktop/tekadventure
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Fri May 26 12:56:34 2017 Capitaine CASSE
** Last update Fri May 26 15:41:57 2017 Capitaine CASSE
*/

#include "lkaas.h"

char	*my_strcat(char *s1, char *s2)
{
  int	i;
  int	j;
  char	*res;

  if ((res = malloc(sizeof(char *) * (my_strlen(s1) + my_strlen(s2) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (s1[i])
    res[i] = s1[i++];
  j = 0;
  while (s2[j])
    res[i++] = s2[j++];
  res[i] = 0;
  return (res);
}
