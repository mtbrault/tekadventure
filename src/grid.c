/*
** grid.c for tekadventure in /home/antoine.casse/Desktop/tekadventure/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Fri Apr 21 19:45:30 2017 Capitaine CASSE
** Last update Sun May 28 11:42:01 2017 Capitaine CASSE
*/

#include "tekadv.h"

sfVector2i	resize_tile(sfVector2i dim, sfSprite *sprite)
{
  sfVector2i	size;
  sfVector2f	scale;

  if (dim.x < dim.y)
    {
      size.y = SCR_H / dim.y;
      size.x = size.y * 2;
    }
  else
    {
      size.x = SCR_W / dim.x;
      size.y = size.x / 2;
    }
  scale.x = (size.x / (float)(2 * S_TILE));
  scale.y = (size.y / (float)S_TILE);
  sfSprite_setScale(sprite, scale);
  return (size);
}

sfVector2i	get_dim(int **map)
{
  sfVector2i	dim;

  dim.y = 0;
  while (map[dim.y] != NULL)
    {
      dim.x = 0;
      while (map[dim.y][dim.x] != EOB)
	dim.x += 1;
      dim.y += 1;
    }
  return (dim);
}

int		draw_grid(int **map, sfVector2i *dim,
			  sfRenderWindow *window, sfSprite **sprite)
{
  sfVector2i	cur;
  sfVector2f	pos;

  cur.y = 0;
  pos = ((sfVector2f) {0.0, (float)SCR_W / 2 - dim[1].x / 2});
  while (map[cur.y] != NULL)
    {
      cur.x = 0;
      while (map[cur.y][cur.x] != EOB)
	{
	  if (map[cur.y][cur.x])
	    {
	      sfSprite_setPosition(sprite[map[cur.y][cur.x] - 1], pos);
	      sfRenderWindow_drawSprite(window, sprite[map[cur.y][cur.x] - 1]
					, NULL);
	    }
	  pos.x += (float)(dim[1].x / 2);
	  pos.y += (float)(dim[1].y / 2);
	  cur.x += 1;
	}
      pos.y = (float)((cur.y + 1) * dim[1].y / 2);
      pos.x = (float)(SCR_W / 2 - dim[1].x / 2) - ((cur.y + 1) * dim[1].x / 2);
      cur.y += 1;
    }
  return (0);
}

int		show_grid(sfRenderWindow *window, t_game *game, int **map)
{
  sfTexture	**tex;
  sfSprite	**sprite;
  sfVector2i	dims[2];

  if ((tex = malloc(sizeof(sfTexture *) * 2)) == NULL ||
      (sprite = malloc(sizeof(sfSprite *) * 2)) == NULL)
    return (1);
  if ((tex[0] = sfTexture_createFromFile(GRID_PATH, NULL)) == NULL ||
      (tex[1] = sfTexture_createFromFile(GRID_PATH_TP, NULL)) == NULL)
    return (1);
  if ((sprite[0] = sfSprite_create()) == NULL ||
      (sprite[1] = sfSprite_create()) == NULL)
    return (1);
  sfSprite_setTexture(sprite[0], tex[0], sfTrue);
  sfSprite_setTexture(sprite[1], tex[1], sfTrue);
  dims[0] = get_dim(map);
  dims[1] = resize_tile(dims[0], sprite[0]);
  resize_tile(dims[0], sprite[1]);
  game->tile = dims[1];
  draw_grid(map, dims, window, sprite);
  sfSprite_destroy(sprite[0]);
  sfSprite_destroy(sprite[1]);
  sfTexture_destroy(tex[0]);
  sfTexture_destroy(tex[1]);
  return (0);
}
