/*
** hover_gesture.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sun Apr 23 22:28:32 2017 LAABID Zakaria
** Last update Sun Apr 23 22:28:32 2017 LAABID Zakaria
*/

#include "tekadv.h"

void		sprite_change(sfRenderWindow *window, int index, t_menu **menu)
{
  sfVector2i	mouse_pos;

  mouse_pos = get_mouse_pos(window);
  set_position_button(menu);
  set_position_panels(menu);
  set_position_start(menu);
  set_position_character(menu);
  sfRenderWindow_drawSprite(window, menu[index]->sprite, NULL);
  if (index == MENU)
    {
      hover_button(window, mouse_pos, menu);
      hover_panels(window, mouse_pos, menu);
    }
  if (index == CHARAC)
    {
      hover_character(window, mouse_pos, menu);
      hover_play(window, mouse_pos, menu);
    }
}
