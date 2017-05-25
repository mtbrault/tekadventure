/*
** loop.c for Tekadventure in /home/antoine.casse/Desktop/tekadv
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 14:20:28 2017 Capitaine CASSE
** Last update Thu May 25 20:19:05 2017 LAABID Zakaria
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

static int		test(sfRenderWindow *window, t_player *player,
			     t_game *game)
{
  sfSprite		*sprite;

  if (sfMouse_isButtonPressed(sfMouseLeft))
    {
      player->s = 0;
      player->sprt = 0;
      player->dest = raw_click(game, window);
      player->next = my_bfs(player->pos, player->dest,
			    (game->level[game->map_status])->map->content);
      if (player->next.x == -1 && player->next.y == -1)
	{
	  player->dest.x = -1;
	  player->dest.y = -1;
	  return (0);
	}
      my_move(window, game, player);
    }
  else if (player->dest.x == -1 && player->dest.y == -1)
    {
      sprite = get_static_char(player->classe_texture, ((sfVector2i) {player->dir,
	      player->class}), game, ((sfVector2i) {8, 4}));
      sfSprite_setPosition(sprite, convert_pos(player->pos, game->tile));
      sfRenderWindow_drawSprite(window, sprite, NULL);
    }
  else if (my_move(window, game, player) == 0)
    {
      player->pos = player->next;
      if (player->pos.x == player->dest.x && player->pos.y == player->dest.y)
	{
	  player->dest.x = -1;
	  player->dest.y = -1;
	  return (0);
	}
      player->s = 0;
      player->next = my_bfs(player->pos, player->dest,
			    (game->level[game->map_status])->map->content);
    }
  return (0);
}

static void		loop2(t_player *player, sfRenderWindow *window,
		      t_game *game)
{
  sfEvent		event;
  int			i;

  player->pos = (sfVector2i) {2, 2};
  player->dest = (sfVector2i) {-1, -1};
  i = 0;
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if ((event.type == sfEvtClosed) ||
	      (sfKeyboard_isKeyPressed(sfKeyEscape)))
	    sfRenderWindow_close(window);
	}
      sfRenderWindow_clear(window, sfWhite);
      /* if (i == 0) */
      /* 	i = load_screen(window, menu); */
      sfRenderWindow_drawSprite(window, game->bg, NULL);
      show_grid(window, game);
      test(window, player, game);
      check_pos(player, game);
      sfRenderWindow_display(window);
    }
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
	  index = mouse_func(window, index, player, menu);
	  if (index == -1)
	    return ;
	}
      if (index == 2)
        break ;
      sfRenderWindow_clear(window, sfWhite);
      sprite_change(window, index, menu);
      sfRenderWindow_display(window);
    }
  loop2(player, window, game);
}

int			tmpdisp(t_tp **tp, t_game *game)
{
  /* int			i; */

  /* i = 0; */
  /* while (tp[i] != NULL) */
  /*   { */
  /*     printf("%d %d %s\n", (tp[i])->coords[0], (tp[i])->coords[1], (tp[i])->next_map); */
  /*     i += 1; */
  /*   } */
  /* printf("%s\n", (game->level[0])->map->bg); */
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
  tmpdisp((game->level[0])->tp, game);
  print_bg(game);
  if ((menu = disp_startmenu()) == NULL)
    return (-1);
  display_window(window, menu, player, game);
  sfRenderWindow_close(window);
  sfRenderWindow_destroy(window);
  return (0);
}
