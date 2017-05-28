/*
** loop.c for Tekadventure in /home/antoine.casse/Desktop/tekadventure
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 14:20:28 2017 Capitaine CASSE
** Last update Sun May 28 11:43:14 2017 Capitaine CASSE
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

static int		draw_game(t_player *player, sfRenderWindow *window,
				  t_game *game, sfClock *clock)
{
  sfRenderWindow_clear(window, sfWhite);
  sfClock_restart(clock);
  if (game->m == 0)
     game->m = load_screen(window, game->menu);
  sfMusic_stop(game->menu[0]->music);
  if (game->bg != NULL)
    sfRenderWindow_drawSprite(window, game->bg, NULL);
  if (game->idx == 1)
    show_grid(window, game, game->level->map->content);
  show_player(window, player, game);
  hud_placing(window, game);
  game->idx = check_hud_click(window, game->idx);
  if (game->idx == 2 || game->idx == 0)
    return (1);
  decor_manager(window, game);
  show_events(window, game, game->level->event, 0);
  if (game->m == 0)
    game->m = sound_manager(game);
  sfRenderWindow_display(window);
  return (0);
}

static void		loop(t_player *player, sfRenderWindow *window,
			      t_game *game)
{
  sfEvent		event;
  sfClock		*clock;

  quest_manager(game);
  player->pos = (sfVector2i) {game->level->map->map_player[0],
			      game->level->map->map_player[1]};
  player->dest = (sfVector2i) {-1, -1};
  clock = sfClock_create();
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if ((event.type == sfEvtClosed) ||
	      (sfKeyboard_isKeyPressed(sfKeyEscape)))
	    sfRenderWindow_close(window);
	}
      if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.013f)
	if (draw_game(player, window, game, clock))
	  break ;
      if (game->idx == 2)
	break ;
    }
  //  sfMusic_stop()
  sfClock_destroy(clock);
}

static char	display_window(sfRenderWindow *window, t_menu **menu,
		       t_player *player, t_game *game)
{
  int		index;
  sfEvent	event;

  index = 0;
  music_change(index, menu);
  game->menu = menu;
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if ((event.type == sfEvtClosed) ||
	      (sfKeyboard_isKeyPressed(sfKeyEscape)))
	    sfRenderWindow_close(window);
	  index = mouse_func(window, index, game, menu);
	  if (index == -1)
	    return (1);
	}
      if (index == 2)
	{
	  loop(player, window, game);
	  index = 0;
	  if ((game->menu = disp_startmenu()) == NULL)
	    return (1);
	}
      sfRenderWindow_clear(window, sfWhite);
      sprite_change(window, index, menu);
      sfRenderWindow_display(window);
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
  game->stop[0] = 0;
  game->stop[1] = 0;
  game->actions = 0;
  game->idx = 1;
  game->m = 0;
  print_bg(game);
  quest_manager(game);
  if ((menu = disp_startmenu()) == NULL)
    return (-1);
  display_window(window, menu, player, game);
  sfRenderWindow_close(window);
  sfRenderWindow_destroy(window);
  return (0);
}
