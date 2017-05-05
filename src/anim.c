/*
** anim.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed May  3 16:03:43 2017 Matthieu BRAULT
** Last update Fri May  5 16:21:23 2017 Matthieu BRAULT
*/

#include <math.h>
#include <stdlib.h>
#include "tekadv.h"

float	thales(float norme, int prop, float axe)
{
  return (((norme / prop) * axe) / norme);
}

int	my_moove(sfRenderWindow *window, sfVector2f vector, t_moove *move, t_game *game)
{
  if (move->s == 0)
    {
      move->norme = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
      move->axe.x = thales(move->norme, 1000, move->click.x - game->player->pos2.x);
      move->axe.y = thales(move->norme, 1000, move->click.y - game->player->pos2.y);
      move->tmp = 0;
      move->i = 0;
      move->loop = (move->click.x - game->player->pos2.x) / move->axe.x;
    }
  if (move->tmp == 6)
    move->tmp = 0;
  if (move->s % 40 == 0)
    move->tmp = move->tmp + 1;
  if (move->s > move->axe.x * (move->i + 1))
    move->i = move->i + 1;
  move->sprite = get_static_char(game->player->spriteboard, ((sfVector2i)
    {move->tmp, game->player->dir}), game, ((sfVector2i) {6, 8}));
  sfSprite_setPosition(move->sprite, game->player->pos2);
  sfRenderWindow_drawSprite(window, move->sprite, NULL);
  game->player->pos2 = ((sfVector2f) {game->player->pos2.x + move->axe.x, game->player->pos2.y + move->axe.y});
  move->s = move->s + 1;
  if (move->i > move->loop)
    return (move->s = 0);
  return (1);
}

sfVector2f	get_vector(sfVector2i mouse, sfVector2f player_moove, t_player *player)
{
  sfVector2f	vector;

  vector.x = (float)mouse.x - player_moove.x;
  vector.y = (float)mouse.y - player_moove.y;
  if (vector.x > -45 && (vector.y >= -45 && vector.y <= 45))
    player->dir = 0;
  else if (vector.x > 45 && vector.y > 0)
    player->dir = 1;
  else if ((vector.x >= -45 && vector.x <= 45) && vector.y > 45)
    player->dir = 2;
  else if (vector.x < -45 && vector.y > 0)
    player->dir = 3;
  else if (vector.x < -45 && (vector.y >= -45 && vector.y <= 45))
    player->dir = 4;
  else if (vector.x < -45 && vector.y < 0)
    player->dir = 5;
  else if ((vector.x >= -45 && vector.x <= 45) && vector.y < 0)
    player->dir = 6;
  else if (vector.x > 45 && vector.y < 0)
    player->dir = 7;
  return (vector);
}
