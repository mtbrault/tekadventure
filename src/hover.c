/*
** hover.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sun Apr 23 21:54:10 2017 LAABID Zakaria
** Last update Sun Apr 23 22:11:34 2017 LAABID Zakaria
*/

#include "tekadv.h"

void		hover_button(sfRenderWindow *window,
			     sfVector2i mouse, t_menu **menu)
{
  sfVector2i	x_b;

  x_b = ((sfVector2i) {573, 767});
  if (check_class_pos(x_b, ((sfVector2i) {248, 279}), mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[PLAY]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[PLAY]->sprite, NULL);
  if (check_class_pos(x_b, ((sfVector2i) {356, 390}), mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[CLOSE]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[CLOSE]->sprite, NULL);
  sfRenderWindow_drawSprite(window, menu[MULTI]->sprite, NULL);
}

void		hover_panels(sfRenderWindow *window,
			     sfVector2i mouse, t_menu **menu)
{
  sfVector2i	y_p;

  y_p = ((sfVector2i) {501, 582});
  if (check_class_pos(((sfVector2i) {451, 532}), y_p, mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[OPTION]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[OPTION]->sprite, NULL);
  if (check_class_pos(((sfVector2i) {605, 705}), y_p, mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[SHOP]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[SHOP]->sprite, NULL);
  if (check_class_pos(((sfVector2i) {785, 880}), y_p, mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[NEWS]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[NEWS]->sprite, NULL);
}

void		sprite_change(sfRenderWindow *window, int index, t_menu **menu)
{
  sfVector2i	mouse_pos;

  mouse_pos = get_mouse_pos(window);
  set_position_button(menu);
  set_position_panels(menu);
  sfRenderWindow_drawSprite(window, menu[index]->sprite, NULL);
  if (index == MENU)
    {
      hover_button(window, mouse_pos, menu);
      hover_panels(window, mouse_pos, menu);
    }
}
