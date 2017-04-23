/*
** my_puterr.c for libkaas in /home/antoine.casse/Desktop/lib
** 
** Made by Antoine Casse
** Login   <antoine.casse@epitech.net>
** 
** Started on  Tue Jan 24 16:25:46 2017 Antoine Casse
** Last update Sun Apr 23 16:11:06 2017 Matthieu BRAULT
*/

#include "lkaas.h"

int	my_puterr(char *err, int x)
{
  int	i;

  i = my_strlen(err);
  if (write(2, err, i) <= 0)
    return (1);
  return (x);
}
