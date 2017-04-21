/*
** loop.c for Tekadventure in /home/antoine.casse/Desktop/tekadv
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 14:20:28 2017 Capitaine CASSE
** Last update Fri Apr 21 04:57:17 2017 LAABID Zakaria
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "tekadv.h"

int			start_menu(t_game *game)
{
  t_menu		**menu;
  sfRenderWindow        *window;
  sfEvent               event;

  game = game;
  menu = malloc(sizeof(t_menu));
  if ((window = create_window()) == NULL)
    return (-1);
  menu = disp_startmenu();
  sfMusic_play(menu[0]->music);
  sfMusic_setLoop(menu[0]->music, sfTrue);
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if ((event.type == sfEvtClosed) ||
	      (sfKeyboard_isKeyPressed(sfKeyEscape)))
	    sfRenderWindow_close(window);
	}
      sfRenderWindow_clear(window, sfBlack);
      sfRenderWindow_drawSprite(window, menu[0]->sprite, NULL);
      sfRenderWindow_display(window);
    }
  sfRenderWindow_close(window);
  return (0);
}
