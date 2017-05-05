/*
** actions.c for Tekadventure in /home/antoine.casse/Desktop/tekadventure/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sat Apr 22 19:50:07 2017 Capitaine CASSE
** Last update Fri May  5 14:18:19 2017 Matthieu BRAULT
*/

#include "tekadv.h"

sfVector2f	get_mult_size(sfVector2i size, sfVector2i tile)
{
  sfVector2f	res;

  res.y = (float)((float)tile.y * 3 / (float)size.y);
  res.x = (float)res.y;
  return (res);
}

sfVector2f	convert_pos(sfVector2i pos, sfVector2i tile)
{
  sfVector2f	res;

  res.x = (float)SCR_W / 2;
  res.y = 0.0;
  res.x += (float)(pos.x * tile.x / 2 - pos.y * tile.y / 2);
  res.y += (float)(pos.x * tile.x / 2 + (pos.y + 1) * tile.y / 2);
  return (res);
}

sfVector2i	raw_click(t_game *game, sfRenderWindow *window)
{
  sfVector2i	pos;
  sfVector2i	grid;
  sfVector2i	tile;

  tile = game->tile;
  pos = sfMouse_getPositionRenderWindow(window);
  pos.x -= SCR_W / 2;
  grid.x = (int)(pos.x / ((float)tile.x / 2) + pos.y / ((float)tile.y / 2)) / 2;
  grid.y = (int)(pos.y / ((float)tile.y / 2) - pos.x / ((float)tile.x / 2)) / 2;
  return (grid);
}
