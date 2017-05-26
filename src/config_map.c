/*
** config_map.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Thu May 25 17:33:43 2017 Matthieu BRAULT
** Last update Fri May 26 12:40:00 2017 Capitaine CASSE
*/

#include "tekadv.h"

void		my_modif_map(int **map,
			     sfRenderWindow *window, t_game *game)
{
  sfVector2i	pos;
  int		i;

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

int		check_button(int s, int nb_map)
{
  if (sfMouse_isButtonPressed(sfKeyLeft))
    s = s - 1;
  else if (sfMouse_isButtonPressed(sfKeyRight))
    s = s + 1;
  if (s < 0)
    s = nb_map - 1;
  else if (s >= nb_map)
    s = 0;
  return (s);
}

int		config_map(sfRenderWindow *window, t_game *game, int nb_map)
{
  int		**map;
  int		i;
  int		s;

  s = 0;
  i = 0;
  while (!sfMouse_isButtonPressed(sfKeyReturn))
    {
      map = game->level->map->content;
      sfRenderWindow_clear(window, sfWhite);
      if (i == 0)
	s = check_button(s, nb_map);
      if (sfMouse_isButtonPressed(sfMouseLeft) && i == 0)
	{
	  my_modif_map(map, window, game);
	  i = 1;
	}
      if (!sfMouse_isButtonPressed(sfMouseLeft)
	  && !sfMouse_isButtonPressed(sfKeyLeft)
	  && !sfMouse_isButtonPressed(sfKeyRight))
	i = 0;
      show_grid(window, game);
      sfRenderWindow_display(window);
    }
  return (0);
}
