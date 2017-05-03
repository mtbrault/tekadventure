/*
** pathfind.c for Tekadventure in /home/antoine.casse/Desktop/tekadventure/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Tue May  2 22:22:39 2017 Capitaine CASSE
** Last update Wed May  3 19:59:57 2017 Capitaine CASSE
*/

#include "tekadv.h"

static int	check_click(int *state, sfVector2i *dir,
			    sfRenderWindow *window, t_game *game)
{
  static sfVector2i	vec = {-1, -1};

  if (vec.x == game->player->pos.x && vec.y == game->player->pos.y)
    {
      vec.x = -1;
      vec.y = -1;
    }
  else if (vec.x != -1 && vec.y != -1)
    {
      *dir = vec;
      return (1);
    }
  if (sfMouse_isButtonPressed(sfMouseRight))
    {
      *dir = raw_click(game, window);
      vec = (*dir);
      return (1);
    }
  else if (vec.x != -1 && vec.y != -1)
    return (1);
  return (0);
}

int	check_obstacles(sfVector2i pos, sfVector2i *dir)
{
  return (0);
}

int	find_pos(t_player *ply, t_game *game, sfRenderWindow *window)
{
  sfVector2i	dir;
  sfVector2f	res;
  sfVector2f	dest;
  static int	state = 0;

  res.x = 0.0;
  res.y = 0.0;
  if (state || check_click(&state, &dir, window, game))
    return (0);
  dest = convert_pos(dir, game->tile);
  res.x = dest.x - (float)ply->pos.x;
  res.y = dest.y - (float)ply->pos.y;
  if (move_perso(res, ply, window))
    state = 0;
  return (0);
}
