/*
** anim.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed May  3 16:03:43 2017 Matthieu BRAULT
** Last update Wed May  3 18:22:54 2017 Matthieu BRAULT
*/

#include <math.h>
#include "tekadv.h"

void		move_perso(sfVector2f vector, t_player *p, sfRenderWindow *window)
{
  static sfVector2f	move = ((sfVector2f) {0, 0});
  static sfVector2f	axe;
  sfSprite		*sprite;

  if (vector.x == 0 && vector.y == 0)
    {
      sprite = get_static_char(p->classe, ((sfVector2i)
	{p->dir, p->class}), player->pos, ((sfVector2i) {8, 4}));
      sfRenderWindow_drawSprite(window, sprite, NULL);
      return ;
    }
  if (move == ((sfVector2f) {0, 0}) || move == vector)
    {
      p->pos = p->pos + move;
      move = ((sfVector2f) {0, 0});
      axe.x = vector.x / sqrt(pow(vector.x, 2) + pow(vector.y, 2));
      axe.y = vector.y / sqrt(pow(vector.x, 2) + pow(vector.y, 2));
    }
  move = ((sfVector2f) {move.x + axe.x, move.y + axe.y});
  sprite = get_static_char(p->spriteboard, ((sfVector2i)
    {p->dir, p->class}), p->pos + move, ((sfVector2i) {6, 8}));
  sfRenderWindow_drawSprite(window, sprite, NULL);
}
