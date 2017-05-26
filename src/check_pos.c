/*
1;4402;0c** check_pos.c for Tekadventure in /home/antoine.casse/Desktop/tekadventure/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Thu May 25 15:43:49 2017 Capitaine CASSE
** Last update Fri May 26 18:58:56 2017 Capitaine CASSE
*/

#include "tekadv.h"

static int	check_tp(sfVector2i pos, t_tp **tp, t_player *player, t_game *game)
{
  int		i;

  i = 0;
  while (tp[i] != NULL)
    {
      if (pos.x == (tp[i])->coords[0] && pos.y == (tp[i])->coords[1])
	{
	  player->pos = (sfVector2i) {0, 0};
	  if ((tp[i])->room != NULL)
	    {
	      game->level = (tp[i])->room;
	      print_bg(game);
	      printf("Changed to %s\n", (tp[i])->room->map->name);
	    }
	  return (0);
	}
      i += 1;
    }
  return (0);
}

int	check_pos(t_player *player, t_game *game)
{
  check_tp(player->pos, game->level->tp, player, game);
  return (0);
}
