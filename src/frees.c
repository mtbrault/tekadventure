/*
** frees.c for Tekadventure in /home/antoine.casse/Desktop/tekadv/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 14:51:59 2017 Capitaine CASSE
** Last update Sun Apr 16 16:33:15 2017 Capitaine CASSE
*/

#include <unistd.h>
#include <stdlib.h>
#include "tekadv.h"

int	free_map(int ***tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i] != NULL)
    {
      j = 0;
      while (tab[i][j] != NULL)
	{
	  free(tab[i][j]);
	  j += 1;
	}
      free(tab[i]);
      i += 1;
    }
  free(tab);
  return (0);
}
