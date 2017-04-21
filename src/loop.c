/*
** loop.c for Tekadventure in /home/antoine.casse/Desktop/tekadv
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 14:20:28 2017 Capitaine CASSE
** Last update Fri Apr 21 22:21:38 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "tekadv.h"

int		my_check_click(sfRenderWindow *window)
{
  sfVector2i	mouse_pos;

  mouse_pos = get_mouse_pos(window);
  if (mouse_pos.x >= 573 && mouse_pos.x <= 767 &&
      mouse_pos.y >= 248 && mouse_pos.y <= 279)
    return (1);
  else
    return (0);
}

void	display_window(sfRenderWindow *window, t_menu **menu)
{
  int		index;
  sfEvent	event;

  index = 0;
  music_change(index, menu);
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if ((event.type == sfEvtClosed) ||
	      (sfKeyboard_isKeyPressed(sfKeyEscape)))
	    sfRenderWindow_close(window);
	  if (sfMouse_isButtonPressed(sfMouseLeft))
	    if (my_check_click(window) == 1)
	      index = 1;
	}
      sfRenderWindow_clear(window, sfBlack);
      sprite_change(window, index, menu);
      sfRenderWindow_display(window);
    }
}

int			start_menu(t_game *game)
{
  t_menu		**menu;
  sfRenderWindow        *window;

  game = game;
  if ((menu = malloc(sizeof(t_menu))) == NULL)
    return (-1);
  if ((window = create_window()) == NULL)
    return (-1);
  if ((menu = disp_startmenu()) == NULL)
    return (-1);
  display_window(window, menu);
  sfRenderWindow_close(window);
  return (0);
}
