/*
** config_map.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu May 25 17:33:43 2017 Matthieu BRAULT
** Last update Sun May 28 21:43:02 2017 Matthieu BRAULT
*/

#include "tekadv.h"

static int		my_modif_map(int **map,
			     sfRenderWindow *window, t_game *game)
{
  sfVector2i		pos;
  int			i;

  i = 0;
  pos = raw_click(game, window);
  while (map[0][i] != EOB)
    i = i + 1;
  if (i <= pos.x || pos.x < 0)
    return (1);
  i = 0;
  while (map[i] != NULL)
    i = i + 1;
  if (i <= pos.y || pos.y < 0)
    return (1);
  if (map[pos.y][pos.x] == 0)
    map[pos.y][pos.x] = 1;
  else
    map[pos.y][pos.x] = 0;
  return (1);
}

int	config_map(sfRenderWindow *window, t_game *game, int **map)
{
  int	i;
  int	j;

  i = 0;
  while (!sfKeyboard_isKeyPressed(sfKeyReturn))
    {
      map = game->level->map->content;
      sfRenderWindow_clear(window, sfWhite);
      if (sfMouse_isButtonPressed(sfMouseLeft) && i == 0)
	i = my_modif_map(map, window, game);
      if (!(sfMouse_isButtonPressed(sfMouseLeft)))
	i = 0;
      if (game->bg != NULL)
	sfRenderWindow_drawSprite(window, game->bg, NULL);
      show_grid(window, game, map);
      sfRenderWindow_display(window);
    }
  i = 0;
  while (map[i] != NULL)
    {
      j = 0;
      while (map[i][j] != EOB)
	{
	  printf("%d", map[i][j]);
	  j = j + 1;
	}
      printf("\n");
      i = i + 1;
    }
  return (0);
}
