/*
** loop.c for Tekadventure in /home/antoine.casse/Desktop/tekadv
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 14:20:28 2017 Capitaine CASSE
** Last update Fri Apr 21 20:13:37 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "tekadv.h"

void	display_window(sfRenderWindow *window, t_menu **menu)
{
  int		index;
  sfEvent	event;

  index = 1;
  music_change(index, menu);
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if ((event.type == sfEvtClosed) ||
	      (sfKeyboard_isKeyPressed(sfKeyEscape)))
	    sfRenderWindow_close(window);
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
