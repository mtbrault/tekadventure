/*
** anim.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed May  3 16:03:43 2017 Matthieu BRAULT
** Last update Tue May 23 13:47:01 2017 Matthieu BRAULT
*/

#include <math.h>
#include <stdlib.h>
#include "tekadv.h"

float	thales(float norme, int prop, float axe)
{
  return (((norme / prop) * axe) / norme);
}

int	my_moove(sfRenderWindow *window, sfVector2f vector,
		 t_moove *m, t_game *game)
{
  printf("case = %f,%f", m->click.x, m->click.y);
  if (m->s == 0)
    {
      m->norme = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
      m->axe.x = thales(m->norme, 1000, m->click.x - game->player->pos2.x);
      m->axe.y = thales(m->norme, 1000, m->click.y - game->player->pos2.y);
      m->tmp = 0;
      m->i = 0;
      m->loop = (m->click.x - game->player->pos2.x) / m->axe.x;
    }
  if (m->tmp == 6)
    m->tmp = 0;
  if (m->s % 40 == 0)
    m->tmp = m->tmp + 1;
  if (m->s > m->axe.x * (m->i + 1))
    m->i = m->i + 1;
  m->sprite = get_static_char(game->player->spriteboard, ((sfVector2i)
    {m->tmp, game->player->dir}), game, ((sfVector2i) {6, 8}));
  sfSprite_setPosition(m->sprite, game->player->pos2);
  sfRenderWindow_drawSprite(window, m->sprite, NULL);
  game->player->pos2 = ((sfVector2f)
    {game->player->pos2.x + m->axe.x, game->player->pos2.y + m->axe.y});
  m->s = m->s + 1;
  if (m->i > m->loop)
    return (m->s = 0);
  return (1);
}

sfVector2f	get_vector(sfVector2f mouse,
			   sfVector2f player_moove, t_player *player)
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
