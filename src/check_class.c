/*
** check_class.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Fri Apr 21 23:25:04 2017 Matthieu BRAULT
** Last update Sun Apr 23 16:00:01 2017 Matthieu BRAULT
*/

#include "tekadv.h"

int	check_class_pos(int x, int y, sfVector2i mouse)
{
  if (mouse.x >= x && mouse.x <= y && mouse.y >= 535 && mouse.y <= 561)
    return (1);
  else
    return (0);
}

int		my_check_class(sfRenderWindow *window,
			       t_player *player, t_game *game)
{
  sfVector2i	mouse_pos;

  mouse_pos = get_mouse_pos(window);
  if (check_class_pos(306, 448, mouse_pos) == 1)
    get_iop(window, player, game);
  else if (check_class_pos(495, 637, mouse_pos) == 1)
    get_feca(window, player, game);
  else if (check_class_pos(680, 826, mouse_pos) == 1)
    get_ecaflip(window, player, game);
  else if (check_class_pos(859, 1006, mouse_pos) == 1)
    get_osa(window, player, game);
  else
    return (0);
  return (1);
}
