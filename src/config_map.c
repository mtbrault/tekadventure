/*
** config_map.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu May 25 17:33:43 2017 Matthieu BRAULT
** Last update Fri May 26 17:30:47 2017 Matthieu BRAULT
*/

#include "tekadv.h"

static void		my_modif_map(int **map,
			     sfRenderWindow *window, t_game *game)
{
  sfVector2i		pos;
  int			i;

  i = 0;
  pos = raw_click(game, window);
  while (map[0][i] != EOB)
    i = i + 1;
  if (i <= pos.x || pos.x < 0)
    return ;
  i = 0;
  while (map[i] != NULL)
    i = i + 1;
  if (i <= pos.y || pos.y < 0)
    return ;
  if (map[pos.y][pos.x] == 0)
    map[pos.y][pos.x] = 1;
  else
    map[pos.y][pos.x] = 0;
}

static int		check_button(int s, int nb_map)
{
  if (sfKeyboard_isKeyPressed(sfKeyLeft))
    s = s - 1;
  else if (sfKeyboard_isKeyPressed(sfKeyRight))
    s = s + 1;
  if (s < 0)
    s = nb_map - 1;
  else if (s >= nb_map)
    s = 0;
  return (s);
}

int		grid_config(sfRenderWindow *window, t_game *game)
{
  int		**map;
  sfTexture	*tex;
  sfSprite	*sprite;
  sfVector2i	dims[2];

  map = game->level->map->content;
  if ((tex = sfTexture_createFromFile(GRID_CONFIG, NULL)) == NULL)
    return (1);
  if ((sprite = sfSprite_create()) == NULL)
    return (1);
  sfSprite_setTexture(sprite, tex, sfTrue);
  dims[0] = get_dim(map);
  dims[1] = resize_tile(dims[0], sprite);
  game->tile = dims[1];
  raw_click(game, window);
  draw_grid(map, dims, window, sprite);
  sfSprite_destroy(sprite);
  sfTexture_destroy(tex);
  return (0);
}

int		config_map(sfRenderWindow *window, t_game *game, int nb_map)
{
  int		**map;
  int		i;
  int		s;
  int		x;

  s = 0;
  i = 0;
  x = 0;
  while (!sfKeyboard_isKeyPressed(sfKeyReturn))
    {
      map = game->level->map->content;
      sfRenderWindow_clear(window, sfWhite);
      if (x == 0)
	{
	  s = check_button(s, nb_map);
	  x = 1;
	}
      if (sfMouse_isButtonPressed(sfMouseLeft) && i == 0)
	{
	  my_modif_map(map, window, game);
	  i = 1;
	}
      if (!sfMouse_isButtonPressed(sfMouseLeft)
	  && !sfKeyboard_isKeyPressed(sfKeyLeft)
	  && !sfKeyboard_isKeyPressed(sfKeyRight))
	{
	  i = 0;
	  x = 0;
	}
      grid_config(window, game);
      sfRenderWindow_display(window);
    }
  return (0);
}
