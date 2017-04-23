/*
** actions.c for Tekadventure in /home/antoine.casse/Desktop/tekadventure/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sat Apr 22 19:50:07 2017 Capitaine CASSE
** Last update Sun Apr 23 19:13:16 2017 Capitaine CASSE
*/

#include "tekadv.h"

int		raw_click(t_game *game, sfRenderWindow *window)
{
  sfVector2i	pos;
  sfVector2i	grid;
  sfVector2i	tile;

  tile = game->tile;
  pos = sfMouse_getPositionRenderWindow(window);
  pos.x -= SCR_W / 2;
  grid.x = (pos.x / (tile.x / 2) + pos.y / (tile.y / 2)) / 2;
  grid.y = (pos.y / (tile.y / 2) - pos.x / (tile.x / 2)) / 2;
  printf("ROH CLIK %d %d\n", grid.x, grid.y);
  return (0);
}
