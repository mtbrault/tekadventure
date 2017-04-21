/*
** main.c for Tekadventure in /home/antoine.casse/Desktop/tekadv
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 13:30:34 2017 Capitaine CASSE
** Last update Fri Apr 21 04:13:59 2017 LAABID Zakaria
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "tekadv.h"

int		main(int ac, char **av)
{
  t_game	*game;

  game = NULL;
  if (show_help(ac, av))
    return (0);
  if (ac != 2)
    {
      my_puterr("Invalid use.\nTry ./tekadventure -h.\n");
      return (84);
    }
  if ((game = get_file(av[1])) == NULL)
    return (84);
  //  debug(game);
  start_menu(game);
  free(game);
  return (0);
}
