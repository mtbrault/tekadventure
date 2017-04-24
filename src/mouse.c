/*
** get_mouse.c for  in /home/b00bix/tekadventure/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Fri Apr 21 20:55:12 2017 Matthieu BRAULT
** Last update Mon Apr 24 04:07:11 2017 LAABID Zakaria
*/

#include "tekadv.h"

int	        mouse_func(sfRenderWindow *window, int index, t_player *player)
{
  if (index == MENU)
    if (sfMouse_isButtonPressed(sfMouseLeft))
      {
	if (my_check_click(window, CLOSE) == 1)
	  index = CHARAC;
	if (my_check_config(get_mouse_pos(window)) == 1)
	  index = CONFIG;
      }
  if (index == CONFIG)
    if (sfMouse_isButtonPressed(sfMouseLeft))
      if (my_check_config(get_mouse_pos(window)) == 2)
	index = MENU;
  if (index == CHARAC)
    if (sfMouse_isButtonPressed(sfMouseLeft))
      {
	if (my_check_class(window, player) == 1)
	  index = 2;
	if (my_check_config(get_mouse_pos(window)) == 2)
	  index = MENU;
      }
  return (index);
}

int		my_check_click(sfRenderWindow *window, int x)
{
  sfVector2i	mouse_pos;

  mouse_pos = get_mouse_pos(window);
  if (mouse_pos.x >= 573 && mouse_pos.x <= 767 &&
      mouse_pos.y >= 248 && mouse_pos.y <= 279)
    return (1);
  if (x == CLOSE)
    if (my_check_exit(mouse_pos) == 1)
      return (1);
  return (NORMAL);
}

sfVector2i	get_mouse_pos(sfRenderWindow *window)
{
  sfVector2i	mouse_pos;

  mouse_pos = sfMouse_getPositionRenderWindow(window);
  return (mouse_pos);
}

void		set_mouse_pos(sfRenderWindow *window, int x, int y)
{
  sfVector2i	mouse_pos;

  mouse_pos = ((sfVector2i) {x, y});
  sfMouse_setPositionRenderWindow(mouse_pos, window);
}
