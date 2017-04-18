/*
** main.c for Tekadventure in /home/antoine.casse/Desktop/tekadv
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 13:30:34 2017 Capitaine CASSE
** Last update Tue Apr 18 16:03:12 2017 LAABID Zakaria
*/

#include <unistd.h>
#include <stdlib.h>
#include "tekadv.h"

int		main(int ac, char **av)
{
  t_game	*game;
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  game = NULL;
  if (show_help(ac, av))
    return (0);
  if (ac != 2)
    {
      my_puterr("Invalid use.\nTry ./tekadventure -h.\n");
      return (0);
    }
  if ((game = get_file(av[1])) == NULL)
    return (84);
  /* DEBUG */
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
  /* END OF DEBUG */
  /* MET LE MENU LA ZACK LA CON DE TES MORTS*/
  free_map(game->map);
  free(game);
  return (0);
}
