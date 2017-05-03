/*
** pathfind.c for Tekadventure in /home/antoine.casse/Desktop/tekadventure/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Tue May  2 22:22:39 2017 Capitaine CASSE
** Last update Wed May  3 13:10:48 2017 Capitaine CASSE
*/

#include "tekadv.h"

sfVector2i		dirtab[4] = {
  (sfVector2i){0, 1},
  (sfVector2i){0, -1},
  (sfVector2i){1, 0},
  (sfVector2i){-1, 0},
};

static int	find_star(sfVector2i *next, sfVector2i pos,
				  sfVector2i dest, int **map)
{
  if (dest.x <= pos.x)
    dest.x = 1;
  else
    dest.x = 1;
  if (dest.x <= pos.x)
     dest.x = 1;
   else
     dest.x = 1;
  return (0);
}

static sfVector2i	find_path(int **map, sfVector2i pos, sfVector2i dest)
{
  sfVector2i		next;
  sfVector2i		tmp;

  while (!find_star(&next, pos, dest, map))
    {
      tmp = find_path(map, next, dest);
      if (tmp.y != -1 && tmp.x != -1)
	return (tmp);
    }
  next.x = -1;
  next.y = -1;
  return (next);
}

static int	check_click(int *state, sfVector2i *dir,
			    sfRenderWindow *window, t_game *game)
{
  static int	x = -1;
  static int	y = -1;

  if (x == game->player->pos.x && y == game->player->pos.y)
    {
      x = -1;
      y = -1;
    }
  if (sfMouse_isButtonPressed(sfMouseRight))
    {
      *dir = raw_click(game, window);
      x = (*dir).x;
      y = (*dir).y;
      return (1);
    }
  else if (x != -1 && y != -1)
    return (1);
  return (0);
}

sfVector2f	find_pos(t_player *ply, t_game *game, sfRenderWindow *window)
{
  sfVector2i	dir;
  sfVector2f	res;
  static int	state = 0;

  res.x = 0.0;
  res.y = 0.0;
  if (state || check_click(&state, &dir, window, game))
    return (res);
  dir = find_path(game->map[0], ply->pos, dir);
  if (dir.x == -1 && dir.y == 1)
    return (res);
  dir.x -= ply->pos.x;
  dir.y -= ply->pos.y;
  
  return (res);
}