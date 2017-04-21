/*
** check_class.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Fri Apr 21 23:25:04 2017 Matthieu BRAULT
** Last update Fri Apr 21 23:34:56 2017 Matthieu BRAULT
*/

#include "tekadv.h"

int	check_class_pos(int x, int y, sfVector2i mouse)
{
  if (mouse.x >= x && mouse.x <= y && mouse.y >= 535 && mouse.y <= 561)
    return (1);
  else
    return (0);
}

int		my_check_class(sfRenderWindow *window)
{
  sfVector2i	mouse_pos;

  mouse_pos = get_mouse_pos(window);
  if (check_class_pos(306, 448, mouse_pos) == 1)
    get_iop();
  else if (check_class_pos(495, 637, mouse_pos) == 1)
    get_feca();
  else if (check_class_pos(680, 826, mouse_pos) == 1)
    get_ecaflip();
  else if (check_class_pos(859, 1006, mouse_pos) == 1)
    get_osa();
  else
    return (0);
  return (1);
}
