/*
** colors.c for $ in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Fri Apr 21 04:12:09 2017 LAABID Zakaria
** Last update Sat Apr 22 00:09:22 2017 LAABID Zakaria
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
void	        set_position_button(t_menu **menu)
{
  sfVector2f	play;
  sfVector2f	play_hover;
  sfVector2f	multi;
  sfVector2f	close;
  sfVector2f    close_hover;

  play = ((sfVector2f) {515.0, 250.0});
  play_hover = ((sfVector2f) {515 - (53 / 2), 250.0 - (57 / 2)});
  multi = ((sfVector2f) {515.0, 305.0});
  close = ((sfVector2f) {515.0, 360.0});
  close_hover = ((sfVector2f) {515 - (53 / 2), 360.0 - (57 / 2)});
  sfSprite_setPosition(menu[2]->sprite, play);
  sfSprite_setPosition(menu[3]->sprite, multi);
  sfSprite_setPosition(menu[4]->sprite, close);
  sfSprite_setPosition(menu[2]->sprite_h, play_hover);
  sfSprite_setPosition(menu[4]->sprite_h, close_hover);
}

/* void	        set_position_panles(t_menu **menu) */
/* { */
/*   sfVector2f    option; */
/*   sfVector2f	option_hover; */
/*   sfVector2f    shop; */
/*   sfVector2f    shop_hover; */
/*   sfVector2f    news; */
/*   sfVector2f    news_hover; */

/*    = ((sfVector2f) {515.0, 250.0}); */
/*   play_hover = ((sfVector2f) {515 - (53 / 2), 250.0 - (57 / 2)}); */
/*   sfSprite_setPosition(menu[PLAY]->sprite, play); */
/*   sfSprite_setPosition(menu[MULTI]->sprite, multi); */
/* } */

void		sprite_change(sfRenderWindow *window, int index, t_menu **menu)
{
  set_position_button(menu);
  //  set_position_panels(menu);
  sfRenderWindow_drawSprite(window, menu[index]->sprite, NULL);
  sfRenderWindow_drawSprite(window, menu[PLAY]->sprite, NULL);
  sfRenderWindow_drawSprite(window, menu[MULTI]->sprite, NULL);
  sfRenderWindow_drawSprite(window, menu[CLOSE]->sprite, NULL);
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
