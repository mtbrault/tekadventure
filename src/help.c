/*
** help.c for Tekacventure in /home/antoine.casse/Desktop/tekadv
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 17:15:10 2017 Capitaine CASSE
** Last update Fri Apr 21 04:05:22 2017 LAABID Zakaria
*/

#include "tekadv.h"

int	show_help(int ac, char **av)
{
  int	i;

  i = 0;
  while (i < ac)
    {
      if (av[i][0] == '-' && av[i][1] == 'h' && !av[i][2])
	{
	  my_putstr(HELP);
	  return (1);
	}
      i += 1;
    }
  return (0);
}

void	debug(t_game *game)
{
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  while (game->map[i] != NULL)
    {
      j = 0;
      printf("map number %d\n", i);
      while (game->map[i][j] != NULL)
	{
	  k = 0;
	  while (game->map[i][j][k] != EOB)
	    {
	      printf("%d,", game->map[i][j][k]);
	      k += 1;
	    }
	  printf("\n");
	  j += 1;
	}
      i += 1;
    }
}
