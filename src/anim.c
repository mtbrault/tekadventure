/*
** anim.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed May  3 16:03:43 2017 Matthieu BRAULT
** Last update Wed May  3 19:18:31 2017 Matthieu BRAULT
*/

#include <math.h>
#include "tekadv.h"

/* void		move_perso(sfVector2f vector, t_player *p, sfRenderWindow *window) */
/* { */
/*   sfVector2f	move; */
/*   sfVector2f	axe; */
/*   sfSprite	*sprite; */
/*   int		len; */
/*   int		i; */

/*   if (vector.x == 0 && vector.y == 0) */
/*     { */
/*       sprite = get_static_char(p->classe, ((sfVector2i) */
/* 	{p->dir, p->class}), p->pos, ((sfVector2i) {8, 4})); */
/*       sfRenderWindow_drawSprite(window, sprite, NULL); */
/*       return ; */
/*     } */
/*   axe.x = vector.x / sqrt(pow(vector.x, 2) + pow(vector.y, 2)); */
/*   axe.y = vector.y / sqrt(pow(vector.x, 2) + pow(vector.y, 2)); */
/*   len = sqrt(pow(vector.x, 2) + pow(vector.y, 2)) / axe.x; */
/*   i = 0; */
/*   move = ((sfVector2f) {0, 0}); */
/*   while (i <= len) */
/*     { */
/*       sprite = get_static_char(p->spriteboard, ((sfVector2i) */
/* 	{p->dir, p->class}), ((sfVector2f) {(float)p->pos.x + move.x, */
/* 	      p->pos.y + move.y}), ((sfVector2i) {6, 8})); */
/*       sfRenderWindow_drawSprite */
/*       move = ((sfVector2f) {move.x + axe.x, move.y + axe.y}); */
/*       i = i + 1; */
/*     } */
/* } */

void		move_perso(sfVector2f vector, t_player *p, sfRenderWindow *window)
{
  static sfVector2f	move = ((sfVector2f) {0, 0});
  static sfVector2f	axe;
  static sfVector2i	i = ((sfVector2i) {0, 0});
  static sfVector2i	loop == ((sfVector2i) {0, 0});
  sfSprite		*sprite;

  if (vector.x == 0 && vector.y == 0)
    {
      sprite = get_static_char(p->classe, ((sfVector2i)
	{p->dir, p->class}), p->pos, ((sfVector2i) {8, 4}));
      sfRenderWindow_drawSprite(window, sprite, NULL);
      return ;
    }
  else if (i.x == 0)
    {
      axe.x = vector.x / sqrt(pow(vector.x, 2) + pow(vector.y, 2));
      axe.y = vector.y / sqrt(pow(vector.x, 2) + pow(vector.y, 2));
      i.x = sqrt(pow(vector.x, 2) + pow(vector.y, 2)) / vector.x;
    }
  move = ((sfVector2f) {move.x + axe.x, move.y + axe.y});
  sprite = get_static_char(p->spriteboard, ((sfVector2i)
    {loop.y, p->dir}), p->pos + move, ((sfVector2i) {6, 8}));
  sfRenderWindow_drawSprite(window, sprite, NULL);
  loop.x = loop.x + 1;
  if (loop.y % 100 == 0)
    loop.y = loop.y + 1;
  if (i.y > i.x)
    {
      i = ((sfVector2i) {0, 0});
      loop = ((sfVector2i) {0, 0});
      move = ((sfVector2f) {0, 0});
    }
}
