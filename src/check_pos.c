/*
** check_pos.c for Tekadventure in /home/antoine.casse/Desktop/tekadventure/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Thu May 25 15:43:49 2017 Capitaine CASSE
** Last update Thu May 25 15:50:56 2017 Capitaine CASSE
*/

#include "tekadv.h"

int	check_tp(sfVector2i pos, t_tp **tp, t_player *player, t_game *game)
{
  int	i;

  i = 0;
  while (tp[i] != NULL)
    {
      if (pos.x == (tp[i])->coords[0] && pos.y == (tp[i])->coords[1])
	{
	  player->pos = (sfVector2i) {0, 0};
	  game->map_status += 1;
	  return (0);
	}
      i += 1;
    }
  return (0);
}

int	check_pos(sfRenderWindow *window, t_player *player, t_game *game)
{
  check_tp(player->pos, (game->level[game->map_status])->tp, player, game);
  return (0);
}
