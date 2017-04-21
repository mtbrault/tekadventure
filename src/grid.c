/*
** grid.c for tekadventure in /home/antoine.casse/Desktop/tekadventure/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Fri Apr 21 19:45:30 2017 Capitaine CASSE
** Last update Fri Apr 21 22:13:42 2017 Capitaine CASSE
*/

#include "tekadv.h"

sfVector2i	resize_tile(sfVector2i dim, sfSprite *sprite)
{
  sfVector2i	size;
  sfVector2f	scale;

  size.y = SCR_H / dim.y;
  size.x = size.y * 2;
  printf("PUTE %d %d %d\n", dim.x, dim.y, S_TILE);
  scale.x = (dim.x / (float)(2 * S_TILE));
  scale.y = (dim.y / (float)S_TILE);
  printf("SCALE %f %f\n", scale.x, scale.y);
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
			  sfRenderWindow *window, sfSprite *sprite)
{
  sfVector2i    cur;
  sfVector2f	pos;

  cur.y = 0;
  pos.y = 0;
  while (map[cur.y] != NULL)
    {
      pos.x = dim[1].x / 2;
      cur.x = 0;
      while (map[cur.y][cur.x] != EOB)
	{
	  if (map[cur.y][cur.x])
	    {
	      sfSprite_setPosition(sprite, pos);
	      printf("drzwn %.2f %.2f\n", pos.x, pos.y);
	      sfRenderWindow_drawSprite(window, sprite, NULL);
	    }
	  pos.x += dim[1].x;
	  cur.x += 1;
	}
      pos.y += dim[1].y;
      cur.y += 1;
    }
  printf("STOP\n");
  return (0);
}

int		show_grid(int **map, sfRenderWindow *window)
{
  sfTexture	*tex;
  sfSprite	*sprite;
  sfVector2i	dims[2];

  if ((tex = sfTexture_createFromFile(GRID_PATH, NULL)) == NULL)
    return (1);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, tex, sfTrue);
  dims[0] = get_dim(map);
  dims[1] = resize_tile(dims[0], sprite);
  draw_grid(map, dims, window, sprite);
  //  sfRenderWindow_drawSprite(window, sprite, NULL);
  return (0);
}
