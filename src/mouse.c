/*
** get_mouse.c for  in /home/b00bix/tekadventure/src
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Fri Apr 21 20:55:12 2017 Matthieu BRAULT
** Last update Sat Apr 22 19:49:54 2017 Capitaine CASSE
*/

#include "tekadv.h"

sfVector2i	get_mouse_pos(sfRenderWindow *window)
{
  sfVector2i	mouse_pos;

  mouse_pos = sfMouse_getPositionRenderWindow(window);
  return (mouse_pos);
}

void		set_mouse_pos(sfRenderWindow *window, int x, int y)
{
  sfVector2i	mouse_pos;

  mouse_pos = ((sfVector2i) {x, y});
  sfMouse_setPositionRenderWindow(mouse_pos, window);
}
