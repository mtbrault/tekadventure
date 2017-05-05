/*
** anim.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed May  3 16:03:43 2017 Matthieu BRAULT
** Last update Fri May  5 11:34:15 2017 Matthieu BRAULT
*/

#include <math.h>
#include <stdlib.h>
#include "tekadv.h"

int	my_moove(sfRenderWindow *window, t_player *player, sfVector2f vector, t_moove *moove)
{
  if (moove->s == 0)
    {
      moove->norme = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
      moove->axe.x = thales(moove->norme, 1000, moove->click.x - player->pos2.x);
      moove->axe.y = thales(moove->norme, 1000, moove->click.y - player->pos2.y);
      moove->tmp = 0;
      moove->i = 0;
      moove->loop = (moove->click.x - player->pos2.x) / moove->axe.x;
    }
  if (moove->tmp == 6)
    moove->tmp = 0;
  if (moove->s % 80 == 0)
    moove->tmp = moove->tmp + 1;
  if (moove->s > moove->axe.x * (moove->i + 1))
    moove->i = moove->i + 1;
  moove->sprite = get_static_char(player->spriteboard, ((sfVector2i)
    {moove->tmp, player->dir}), player->pos2, ((sfVector2i) {6, 8}));
  sfRenderWindow_drawSprite(window, moove->sprite, NULL);
  player->pos2 = ((sfVector2f) {player->pos2.x + moove->axe.x, player->pos2.y + moove->axe.y});
  moove->s = moove->s + 1;
  if (moove->i > moove->loop)
    return (moove->s = 0);
  return (1);
}

sfVector2f	get_vector(sfVector2i mouse, sfVector2f player_moove, t_player *player)
{
  sfVector2f	vector;

  vector.x = (float)mouse.x - player_moove.x;
  vector.y = (float)mouse.y - player_moove.y;
  if (vector.x > -45 && (vector.y >= -45 && vector.y <= 45))
    player->dir = 0;
  else if (vector.x > 45 && vector.y > 45)
    player->dir = 1;
  else if ((vector.x >= -45 && vector.x <= 45) && vector.y > 45)
    player->dir = 2;
  else if (vector.x < -45 && vector.y > 45)
    player->dir = 3;
  else if (vector.x < -45 && (vector.y >= -45 && vector.y <= 45))
    player->dir = 4;
  else if (vector.x < -45 && vector.y < -45)
    player->dir = 5;
  else if ((vector.x >= -45 && vector.x <= 45) && vector.y < -45)
    player->dir = 6;
  else if (vector.x > 45 && vector.y < -45)
    player->dir = 7;
  return (vector);
}
