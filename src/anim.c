/*
** anim.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed May  3 16:03:43 2017 Matthieu BRAULT
** Last update Thu May 25 15:31:36 2017 Capitaine CASSE
*/

#include <math.h>
#include <stdlib.h>
#include "tekadv.h"

static t_list	dirtab[8] = {
  {},
  {},
  {},
  {},
  {},
  {},
  {},
  {},
};

int	my_move(sfRenderWindow *window, t_game *game, t_player *player)
{
  sfSprite	*sprite;
  sfVector2f	vector;
  sfVector2f	pos;

  vector = get_vector(game, player);
  vector.x /= 100;
  vector.y /= 100;
  pos = convert_pos(player->pos, game->tile);
  pos.x += (float) (player->s * vector.x);
  pos.y += (float) (player->s * vector.y);
  player->s += 1;
  if (!(player->s % 50))
    player->sprt += 1;
  if (player->sprt > 5)
    player->sprt = 0;
  sprite = get_static_char(game->player->spriteboard, (sfVector2i) {player->dir,
	player->sprt}, game, ((sfVector2i) {6, 8}));
  sfSprite_setPosition(sprite, pos);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  if (player->s == 100)
    return (0);
  return (1);
}

sfVector2f	get_vector(t_game *game, t_player *player)
{
  sfVector2f	vector;
  sfVector2f	sides[2];

  sides[0] = convert_pos(player->pos, game->tile);
  sides[1] = convert_pos(player->next, game->tile);
  vector = (sfVector2f) {sides[1].x - sides[0].x, sides[1].y - sides[0].y};
  
  /*  */
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
  /*  */
}
