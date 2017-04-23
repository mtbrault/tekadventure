/*
** actions.c for Tekadventure in /home/antoine.casse/Desktop/tekadventure/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sat Apr 22 19:50:07 2017 Capitaine CASSE
** Last update Sun Apr 23 16:16:50 2017 Capitaine CASSE
*/

#include "tekadv.h"

int		raw_click(t_game *game, sfRenderWindow *window)
{
  sfVector2i	pos;
  sfVector2i	grid;

  pos = sfMouse_getPositionRenderWindow(window);
  grid.x = (pos.x * 2 / game->tile.x + pos.y * 2 / game->tile.y) / 2;
  grid.y = (pos.y * 2 / game->tile.y - pos.x * 2 / game->tile.x)  / 2;
  printf("ROH CLIK %d %d\n", grid.x, grid.y);
  return (0);
}