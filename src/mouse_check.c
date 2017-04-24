/*
** mouse_check.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Mon Apr 24 04:06:54 2017 LAABID Zakaria
** Last update Mon Apr 24 21:09:09 2017 Matthieu BRAULT
*/

#include "tekadv.h"

int	my_check_exit(sfVector2i mouse_pos)
{
  if (mouse_pos.x >= 573 && mouse_pos.x <= 767 &&
	   mouse_pos.y >= 356 && mouse_pos.y <= 390)
    {
      exit(0);
      return (1);
    }
  return (NORMAL);
}

int	my_config(sfRenderWindow *window, int index, t_menu **menu)
{
  sfVector2i	x_b;
  sfVector2i	mouse_pos;

  mouse_pos = get_mouse_pos(window);
  x_b = ((sfVector2i) {730, 848});
  if (my_check_config(mouse_pos) == 2)
    index = MENU;
  else if (check_class_pos(x_b, ((sfVector2i) {289, 313}), mouse_pos))
    {
      if (menu[BT_ON_V]->hover == 0)
	menu[BT_ON_V]->hover = 1;
      else
	menu[BT_ON_V]->hover = 0;
    }
  else if (check_class_pos(x_b, ((sfVector2i) {353, 372}), mouse_pos))
    {
      if (menu[BT_ON_B]->hover == 0)
	menu[BT_ON_B]->hover = 1;
      else
	menu[BT_ON_B]->hover = 0;
    }
  else if (check_class_pos(((sfVector2i) {655, 745})
			   , ((sfVector2i) {411, 438}), mouse_pos))
    {
      if (menu[BT_ON_D]->hover == 0)
	menu[BT_ON_D]->hover = 1;
      else
	menu[BT_ON_D]->hover = 0;
    }
  return (index);
}

int	my_check_config(sfVector2i mouse_pos)
{
  if (mouse_pos.x >= 442 && mouse_pos.x <= 536 &&
      mouse_pos.y >= 519 && mouse_pos.y <= 595)
    return (1);
  if (mouse_pos.x >= 270 && mouse_pos.x <= 475 &&
      mouse_pos.y >= 180 && mouse_pos.y <= 210)
    return (2);
  return (NORMAL);
}
