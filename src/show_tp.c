/*
** show_tp.c for tekadventure in /home/antoine.casse/Desktop/tekadventure
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun May 28 16:52:44 2017 Capitaine CASSE
** Last update Sun May 28 16:57:59 2017 Capitaine CASSE
*/

#include "tekadv.h"

static int	draw_tp(t_game *game, t_rp **tp, sfRenderWindow *window)
{
  int		i;

  while (tp[i] != NULL)
    {
      
      i += 1;
    }
}

int		show_tp(t_game *game, sfRenderWindow *window)
{
  int		i;
  t_event	**event;

  event = game->level->event;
  stop = 0;
  while (event[i] != NULL)
    {
      if (event[i]->pnj && !event->active)
	return (0);
      i += 1;
    }
  draw_tp(game, game->level->tp, window);
  return (0);
}
