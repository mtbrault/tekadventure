/*
** colors.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sat Apr 22 21:50:42 2017 LAABID Zakaria
** Last update Sun Apr 23 19:01:59 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include <stdlib.h>

#include "tekadv.h"

t_menu_conf	menu_conf[MENU_PIC]=
  {
    {STMENU_MAIN, MUSIC_MAIN, NULL},
    {STMENU_CHARAC, MUSIC_CHARAC, NULL},
    {STMENU_PLAY, MUSIC_CHARAC, STMENU_PLAY_H},
    {STMENU_MULTI, MUSIC_CHARAC, NULL},
    {STMENU_CLOSE, MUSIC_CHARAC, STMENU_CLOSE_H},
    {STMENU_START, MUSIC_CHARAC, STMENU_START_H},
    {MENU_NEWS, MUSIC_CHARAC, MENU_NEWS_H},
    {MENU_OPTION, MUSIC_CHARAC, MENU_OPTION_H},
    {MENU_SHOP, MUSIC_CHARAC, MENU_SHOP_H},
    {CHARAC_FECA, MUSIC_CHARAC, CHARAC_FECA_H},
    {CHARAC_IOP, MUSIC_CHARAC, CHARAC_IOP_H},
    {CHARAC_ECA, MUSIC_CHARAC, CHARAC_ECA_H},
    {CHARAC_OSA, MUSIC_CHARAC, CHARAC_OSA_H},
  };

void		music_change(int index, t_menu **menu)
{
  sfMusic_play(menu[index]->music);
  sfMusic_setLoop(menu[index]->music, sfTrue);
}

void		sprite_change(sfRenderWindow *window, int index, t_menu **menu)
{
  sfVector2i	mouse_pos;
  sfVector2i	x_b;
  sfVector2i	y_p;

  x_b = ((sfVector2i) {573, 767});
  y_p = ((sfVector2i) {501, 582});
  mouse_pos = get_mouse_pos(window);
  set_position_button(menu);
  set_position_panels(menu);
  sfRenderWindow_drawSprite(window, menu[index]->sprite, NULL);
  if (index == MENU)
    {
      if (check_class_pos(x_b, ((sfVector2i) {248, 279}), mouse_pos) == 1)
	  sfRenderWindow_drawSprite(window, menu[PLAY]->sprite_h, NULL);
      else
	sfRenderWindow_drawSprite(window, menu[PLAY]->sprite, NULL);
      if (check_class_pos(x_b, ((sfVector2i) {356, 390}), mouse_pos) == 1)
	sfRenderWindow_drawSprite(window, menu[CLOSE]->sprite_h, NULL);
      else
	sfRenderWindow_drawSprite(window, menu[CLOSE]->sprite, NULL);
      sfRenderWindow_drawSprite(window, menu[MULTI]->sprite, NULL);
      if (check_class_pos(((sfVector2i) {451, 532}), y_p, mouse_pos) == 1)
	sfRenderWindow_drawSprite(window, menu[OPTION]->sprite_h, NULL);
      else
	sfRenderWindow_drawSprite(window, menu[OPTION]->sprite, NULL);
      if (check_class_pos(((sfVector2i) {605, 705}), y_p, mouse_pos) == 1)
	sfRenderWindow_drawSprite(window, menu[SHOP]->sprite_h, NULL);
      else
	sfRenderWindow_drawSprite(window, menu[SHOP]->sprite, NULL);
      if (check_class_pos(((sfVector2i) {785, 880}), y_p, mouse_pos) == 1)
	sfRenderWindow_drawSprite(window, menu[NEWS]->sprite_h, NULL);
      else
	sfRenderWindow_drawSprite(window, menu[NEWS]->sprite, NULL);
    }
}

t_menu		**gen_texture_space(t_menu **menu)
{
  int		i;

  i = 0;
  if ((menu = malloc(sizeof(t_menu) * MENU_PIC)) == NULL)
    return (NULL);
  while (i < MENU_PIC)
    if ((menu[i++] = malloc(sizeof(t_menu))) == NULL)
      return (NULL);
  return (menu);
}

t_menu		**texture_init_hover(t_menu **menu, int i)
{
  menu[i]->tex_h = sfTexture_createFromFile(menu_conf[i].hover_path, NULL);
  menu[i]->sprite_h = sfSprite_create();
  menu[i]->pos_h = ((sfVector2f) {0.0, 0.0});
  menu[i]->size_h = sfTexture_getSize(menu[i]->tex_h);
  sfSprite_setPosition(menu[i]->sprite_h, menu[i]->pos_h);
  sfSprite_setTexture(menu[i]->sprite_h, menu[i]->tex_h, sfTrue);
  return (menu);
}

t_menu		**texture_init(t_menu **menu)
{
  int		i;

  i = 0;
  while (i < MENU_PIC)
    {
      if (menu_conf[i].hover_path != NULL)
	menu = texture_init_hover(menu, i);
      menu[i]->tex = sfTexture_createFromFile(menu_conf[i].tex_path, NULL);
      menu[i]->sprite = sfSprite_create();
      menu[i]->pos = ((sfVector2f) {0.0, 0.0});
      menu[i]->size = sfTexture_getSize(menu[i]->tex);
      sfSprite_setPosition(menu[i]->sprite, menu[i]->pos);
      sfSprite_setTexture(menu[i]->sprite, menu[i]->tex, sfTrue);
      menu[i]->music = sfMusic_createFromFile(menu_conf[i].music_path);
      i++;
    }
  return (menu);
}

t_menu		**disp_startmenu(void)
{
  t_menu	**menu;

  if ((menu = malloc(sizeof(t_menu))) == NULL)
    return (NULL);
  if ((menu = gen_texture_space(menu)) == NULL)
    return (NULL);
  menu = texture_init(menu);
  return (menu);
}
