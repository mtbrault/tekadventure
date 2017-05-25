/*
** config_map.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu May 25 17:33:43 2017 Matthieu BRAULT
** Last update Thu May 25 18:38:13 2017 Matthieu BRAULT
*/

#include "tekadv.h"

void		my_modif_map(int **map,
			     sfRenderWindow *window, t_game *game)
{
  sfVector2i	pos;
  int		i;

  i = 0;
  pos = raw_click(game, window);
  printf("%d\n%d\n", pos.x, pos.y);
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

int		config_map(sfRenderWindow *window, t_game *game)
{
  int		**map;
  sfTexture	*grid;
  sfSprite	*sprite;
  int		i;
  
  map = (game->level[game->map_status])->map->content;
  i = 0;
  while (!sfMouse_isButtonPressed(sfKeyReturn))
    {
      sfRenderWindow_clear(window, sfWhite);
      if (sfMouse_isButtonPressed(sfMouseLeft) && i == 0)
	{
	  my_modif_map(map, window, game);
	  i = 1;
	}
      if (!sfMouse_isButtonPressed(sfMouseLeft))
	i = 0;
      show_grid(window, game, game->player);
      sfRenderWindow_display(window);
    }
}
