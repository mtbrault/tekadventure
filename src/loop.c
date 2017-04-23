/*
** loop.c for Tekadventure in /home/antoine.casse/Desktop/tekadv
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 14:20:28 2017 Capitaine CASSE
** Last update Sun Apr 23 16:20:38 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "tekadv.h"

int	my_check_exit(sfRenderWindow *window, sfVector2i mouse_pos)
{
  if (mouse_pos.x >= 573 && mouse_pos.x <= 767 &&
	   mouse_pos.y >= 356 && mouse_pos.y <= 390)
    {
      exit(0);
      return (1);
    }
}

int		my_check_click(sfRenderWindow *window, int x)
{
  sfVector2i	mouse_pos;

  mouse_pos = get_mouse_pos(window);
  if (mouse_pos.x >= 573 && mouse_pos.x <= 767 &&
      mouse_pos.y >= 248 && mouse_pos.y <= 279)
    return (1);
  if (x == 0)
    {
      if (my_check_exit(window, mouse_pos) == 1)
	return (1);
    }
  else
    return (0);
}

void	display_window(sfRenderWindow *window, t_menu **menu,
		       t_player *player, t_game *game)
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
	  if (index == 0)
	    {
	      if (sfMouse_isButtonPressed(sfMouseLeft))
	  	if (my_check_click(window, 0) == 1)
	  	  index = 1;
	    }
	  if (index == 1)
	    {
	      if (sfMouse_isButtonPressed(sfMouseLeft))
	  	if (my_check_class(window, player, game) == 1)
	  	  index = 2;
	    }
	}
      if (index == 0 || index == 1)
	{
	  sfRenderWindow_clear(window, sfWhite);
	  sprite_change(window, index, menu);
	}
      sfRenderWindow_display(window);
    }
}

int			start_menu(t_game *game, t_player *player)
{
  t_menu		**menu;
  sfRenderWindow        *window;

  if ((menu = malloc(sizeof(t_menu))) == NULL)
    return (-1);
  if ((window = create_window()) == NULL)
    return (-1);
  if ((menu = disp_startmenu()) == NULL)
    return (-1);
  display_window(window, menu, player, game);
  sfRenderWindow_close(window);
  sfRenderWindow_destroy(window);
  return (0);
}
