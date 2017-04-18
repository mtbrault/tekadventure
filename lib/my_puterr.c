/*
** my_puterr.c for libkaas in /home/antoine.casse/Desktop/lib
** 
** Made by Antoine Casse
** Login   <antoine.casse@epitech.net>
** 
** Started on  Tue Jan 24 16:25:46 2017 Antoine Casse
** Last update Tue Jan 24 16:26:59 2017 Antoine Casse
*/

#include "lkaas.h"

int	my_puterr(char *err)
{
  int	i;

  i = my_strlen(err);
  if (write(2, err, i) <= 0)
    return (1);
  return (0);
}
