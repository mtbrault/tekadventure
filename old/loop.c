/*
** loop.c for Tekadventure in /home/antoine.casse/Desktop/tekadv
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 14:20:28 2017 Capitaine CASSE
** Last update Sat May 27 17:10:02 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tekadv.h"

int	load_screen(sfRenderWindow *window, t_menu **menu)
{
  int	s;

  s = 0;
  sfMusic_stop(menu[MENU]->music);
  music_change(LOAD_ONE, menu);
  while (s <= 9)
    {
      sfRenderWindow_clear(window, sfWhite);
      if (s == 0 || s == 3 || s == 6 || s == 9)
	sfRenderWindow_drawSprite(window, menu[LOAD_THREE]->sprite, NULL);
      else if (s == 1 || s == 4 || s == 7)
	sfRenderWindow_drawSprite(window, menu[LOAD_TWO]->sprite, NULL);
      else if (s == 2 || s == 5 || s == 8)
	sfRenderWindow_drawSprite(window, menu[LOAD_ONE]->sprite, NULL);
      sfRenderWindow_display(window);
      usleep(500000);
      s = s + 1;
    }
  sfMusic_stop(menu[LOAD_ONE]->music);
  music_change(0, menu);
  return (1);
}

static void		loop2(t_player *player, sfRenderWindow *window,
			      t_game *game, t_menu **menu)
{
  sfEvent		event;
  sfClock		*clock;
  int			i;
  int			idx;
  int			x;

  player->pos = (sfVector2i) {4, 10};
  player->dest = (sfVector2i) {-1, -1};
  i = 0;
  idx = 1;
  x = 0;
  clock = sfClock_create();
  quest_manager(game);
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if ((event.type == sfEvtClosed) ||
	      (sfKeyboard_isKeyPressed(sfKeyEscape)))
	    sfRenderWindow_close(window);
	}
      if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.013f)
	{
	  sfRenderWindow_clear(window, sfWhite);
	  sfClock_restart(clock);
	  /* if (i == 0) */
	  /* 	i = load_screen(window, menu); */
	  sfMusic_stop(menu[0]->music);
	  if (game->bg != NULL)
	    sfRenderWindow_drawSprite(window, game->bg, NULL);
	  if (idx == 1)
	    show_grid(window, game);
	  show_player(window, player, game);
	  check_pos(player, game);
	  hud_placing(window, game);
	  if (x == 0)
	    {
	      if (idx != (idx = check_hud_click(window, idx)))
		break ;
	    }
	  if (!sfMouse_isButtonPressed(sfMouseLeft))
	    x = 0;
	  show_events(window, game);
	  if (i == 0)
	    i = sound_manager(window, game);
	  sfRenderWindow_display(window);
	}
    }
  sfClock_destroy(clock);
}

void		display_window(sfRenderWindow *window, t_menu **menu,
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
	  index = mouse_func(window, index, game, menu);
	  if (index == -1)
	    return ;
	}
      if (index == 2)
        break ;
      sfRenderWindow_clear(window, sfWhite);
      sprite_change(window, index, menu);
      sfRenderWindow_display(window);
    }
  loop2(player, window, game, menu);
}

int			tmpdisp(t_tp **tp, t_game *game)
{
  int			i;

  i = 0;
  if (tp != NULL)
    {
      while (tp[i] != NULL)
	{
	  printf("%d %d %s\n", (tp[i])->coords[0], (tp[i])->coords[1], (tp[i])->next_map);
	  i += 1;
	}
      printf("%s\n", game->level->map->bg);
    }
  return (0);
}

int			start_menu(t_game *game, t_player *player)
{
  t_menu		**menu;
  sfRenderWindow        *window;

  if ((menu = malloc(sizeof(t_menu))) == NULL)
    return (-1);
  if ((window = create_window()) == NULL)
    return (-1);
  tmpdisp(game->level->tp, game);
  print_bg(game);
  if ((menu = disp_startmenu()) == NULL)
    return (-1);
  display_window(window, menu, player, game);
  sfRenderWindow_close(window);
  sfRenderWindow_destroy(window);
  return (0);
}