/*
** colors.c for $ in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Fri Apr 21 04:12:09 2017 LAABID Zakaria
** Last update Fri Apr 21 04:57:01 2017 LAABID Zakaria
*/

#include <unistd.h>
#include <stdlib.h>

#include "tekadv.h"

t_menu_conf	menu_conf[MENU_PIC]=
  {
    {STMENU_MAIN, MUSIC_MAIN},
    {STMENU_CHARAC, MUSIC_CHARAC}
  };

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

t_menu		**texture_init(t_menu **menu)
{
  int		i;

  i = 0;
  while (i < MENU_PIC)
    {
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

  menu = malloc(sizeof(t_menu));
  menu = gen_texture_space(menu);
  menu = texture_init(menu);
  return (menu);
}
