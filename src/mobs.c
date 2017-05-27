/*
** mobs.c for tekadventure in /home/antoine.casse/Desktop/tekadventure/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Fri May 26 22:25:56 2017 Capitaine CASSE
** Last update Fri May 26 23:14:49 2017 Capitaine CASSE
*/

#include "tekadv.h"

int	show_mobs(sfRenderWindow *window, t_player *player, t_game *game)
{
  int	i;

  i = 0;
  while (game->level->mob[i] != NULL)
    {
      printf("%s :\n(%s)\n", game->level->mob[i]->name
	     , game->level->mob[i]->texture);
      printf("life : %d\ndamage : %d\n", game->level->mob[i]->life,
	     game->level->mob[i]->damage);
      i += 1;
    }
  return (0);
}
