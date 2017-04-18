/*
** loop.c for Tekadventure in /home/antoine.casse/Desktop/tekadv
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 14:20:28 2017 Capitaine CASSE
** Last update Tue Apr 18 16:14:58 2017 LAABID Zakaria
*/

#include "tekadv.h"

int			gametrack(t_game *game, sfRenderWindow *window)
{
  game = game;
  window = window;
  return (0);
}

int			loop(t_game *game, sfRenderWindow *window)
{
  sfEvent		event;

  while (sfRenderWindow_isOpen(window))
    {
      sfRenderWindow_clear(window, sfBlack);
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if ((event.type == sfEvtClosed) ||
	      (sfKeyboard_isKeyPressed(sfKeyEscape)))
	    sfRenderWindow_close(window);
	}
      if (gametrack(game, window))
	return (1);
    }
  return (0);
}

int			start_menu(t_game *game)
{
  sfRenderWindow        *window;
  sfEvent               event;
  int			a;

  if ((window = create_window()) == NULL)
    return (-1);
  while (sfRenderWindow_isOpen(window))
    {
      sfRenderWindow_clear(window, sfBlack);
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if ((event.type == sfEvtClosed) ||
	      (sfKeyboard_isKeyPressed(sfKeyEscape)))
	    sfRenderWindow_close(window);
	}
      if ((a = disp_startmenu(window)) == 1)
	loop(game, window);
      if (a == -1)
	break ;
      sfRenderWindow_clear(window, sfBlack);
      sfRenderWindow_display(window);
    }
  sfRenderWindow_close(window);
  return (0);
}
