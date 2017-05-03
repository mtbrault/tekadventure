/*
** main.c for Tekadventure in /home/antoine.casse/Desktop/tekadv
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 13:30:34 2017 Capitaine CASSE
** Last update Wed May  3 22:17:10 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "tekadv.h"

int		main(int ac, char **av)
{
  t_game	*game;
  t_player	*player;

  game = NULL;
  if (show_help(ac, av))
    return (0);
  if (ac != 2)
    return (my_puterr("Invalid use.\nTry ./tekadventure -h.\n", 84));
  if ((player = malloc(sizeof(t_player))) == NULL)
    return (84);
  if ((player->stat = malloc(sizeof(t_stat))) == NULL)
    return (84);
  if ((game = get_file(av[1])) == NULL)
    return (84);
  game->player = player;
  player->pos2 = ((sfVector2f) {200, 300});
  debug(game);
  if (start_menu(game, player) == -1)
    return (84);
  free(game);
  return (0);
}
