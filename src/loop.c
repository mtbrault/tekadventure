/*
** loop.c for Tekadventure in /home/antoine.casse/Desktop/tekadv
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 14:20:28 2017 Capitaine CASSE
** Last update Fri May  5 16:47:25 2017 Matthieu BRAULT
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

int			test(sfRenderWindow *window, t_player *player,
			     t_moove *moove, t_game *game)
{
  static sfVector2i	mouse = {-1, -1};
  static sfVector2f	vector;
  sfSprite		*sprite;

  if (sfMouse_isButtonPressed(sfMouseLeft))
    {
      moove->s = 0;
      mouse = get_mouse_pos(window);
      moove->click = ((sfVector2f) {(float)mouse.x, (float)mouse.y});
      vector = get_vector(mouse, player->pos2, player);
      my_moove(window, vector, moove, game);
    }
  else if (mouse.x == -1 && mouse.y == -1)
    {
      sprite = get_static_char(player->classe_texture, ((sfVector2i)
	{player->dir, player->class}), game, ((sfVector2i) {8, 4}));
      sfSprite_setPosition(sprite, player->pos2);
      sfRenderWindow_drawSprite(window, sprite, NULL);
    }
  else if (my_moove(window, vector, moove, game) == 0)
    mouse = ((sfVector2i) {-1, -1});
  return (0);
}

void	loop2(t_player *player, sfRenderWindow *window,
	      t_game *game, t_menu **menu)
{
  sfEvent	event;
  t_moove	*moove;
  int		i;

  player = player;
  i = 0;
  if ((moove = malloc(sizeof(t_moove))) == NULL)
    return ;
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if ((event.type == sfEvtClosed) ||
	      (sfKeyboard_isKeyPressed(sfKeyEscape)))
	    sfRenderWindow_close(window);
	}
      sfRenderWindow_clear(window, sfWhite);
      if (i == 0)
      	i = load_screen(window, menu);
      show_grid(window, game, player);
      test(window, player, moove, game);
      sfRenderWindow_display(window);
    }
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
	  index = mouse_func(window, index, player, menu);
	}
      if (index == 2)
        break;
      sfRenderWindow_clear(window, sfWhite);
      sprite_change(window, index, menu);
      sfRenderWindow_display(window);
    }
  loop2(player, window, game, menu);
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
