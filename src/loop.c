/*
** loop.c for Tekadventure in /home/antoine.casse/Desktop/tekadv
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 14:20:28 2017 Capitaine CASSE
** Last update Thu May  4 16:30:13 2017 Matthieu BRAULT
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

float	thales(float norme, int prop, float axe)
{
  return (((norme / prop) * axe) / norme);
}

void	my_moove(sfRenderWindow *window, t_player *player, sfVector2f vector, sfVector2f click)
{
  sfVector2f	axe;
  int		norme;
  int		loop;
  int		i;
  int		tmp;
  int		s;
  sfSprite	*sprite;
  sfVector2i	mouse;

  norme = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
  axe.x = thales(sqrt(pow(vector.x, 2) + pow(vector.y, 2)), 2000, click.x - player->pos2.x);
  axe.y = thales(sqrt(pow(vector.x, 2) + pow(vector.y, 2)), 2000, click.y - player->pos2.y);
  axe = ((sfVector2f) {axe.x, axe.y});
  i = 0;
  tmp = 0;
  s = 0;
  loop = (click.x - player->pos2.x) / axe.x;
  while (i <= loop)
    {
      if (sfMouse_isButtonPressed(sfMouseLeft))
	{
	  mouse = get_mouse_pos(window);
	  my_moove(window, player, get_vector(mouse, player->pos2, player), ((sfVector2f) {(float)mouse.x, (float)mouse.y}));
	  return ;
	}
      sfRenderWindow_clear(window, sfWhite);
      if (tmp == 6)
	tmp = 0;
      if (s % 100 == 0)
	tmp = tmp + 1;
      if (s % 2000)
	i = i + 1;
      sprite = get_static_char(player->spriteboard, ((sfVector2i)
	{tmp, player->dir}), player->pos2, ((sfVector2i) {6, 8}));
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
      player->pos2 = ((sfVector2f) {player->pos2.x + axe.x, player->pos2.y + axe.y});
      s = s + 1;
    }
}

sfVector2f	get_vector(sfVector2i mouse, sfVector2f player_moove, t_player *player)
{
  sfVector2f	vector;

  vector.x = (float)mouse.x - player_moove.x;
  vector.y = (float)mouse.y - player_moove.y;
  if (vector.x > 0 && (vector.y >= 0 && vector.y <= 60))
    player->dir = 0;
  else if (vector.x > 60 && vector.y > 60)
    player->dir = 1;
  else if ((vector.x >= 0 && vector.x <= 60) && vector.y > 60)
    player->dir = 2;
  else if (vector.x < 0 && vector.y > 60)
    player->dir = 3;
  else if (vector.x < 0 && (vector.y >= 0 && vector.y <= 60))
    player->dir = 4;
  else if (vector.x < 0 && vector.y < 0)
    player->dir = 5;
  else if ((vector.x >= 0 && vector.x <= 60) && vector.y < 0)
    player->dir = 6;
  else if (vector.x > 60 && vector.y < 0)
    player->dir = 7;
  return (vector);
}

void	test(sfRenderWindow *window, t_player *player)
{
  sfVector2i	mouse;
  sfSprite	*static_pos;
  
  if (sfMouse_isButtonPressed(sfMouseLeft))
    {
      mouse = get_mouse_pos(window);
      my_moove(window, player, get_vector(mouse, player->pos2, player), ((sfVector2f) {(float)mouse.x, (float)mouse.y}));
    }
  else
    {
      static_pos = get_static_char(player->classe_texture, ((sfVector2i)
	{player->dir, player->class}), player->pos2, ((sfVector2i) {8, 4}));
      sfRenderWindow_drawSprite(window, static_pos, NULL);
    }
}

void	loop2(t_player *player, sfRenderWindow *window, t_game *game, t_menu **menu)
{
  sfEvent	event;
  int		i;

  player = player;
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
      //show_grid(window, game, player);
      test(window, player);
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
