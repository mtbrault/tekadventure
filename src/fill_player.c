/*
** fill_player.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Fri Apr 21 23:32:41 2017 Matthieu BRAULT
** Last update Tue May  2 14:55:40 2017 Matthieu BRAULT
*/

#include <SFML/Graphics/Rect.h>
#include "tekadv.h"

int	get_iop(t_player *player)
{
  player->class = 0;
  player->pv = 500;
  player->pa = 6;
  player->pm = 3;
  player->level = 1;
  player->stat->class = 1;
  player->stat->strengh = 150;
  player->stat->luck = 0.1;
  return (0);
}

int	get_feca(t_player *player)
{
  player->class = 1;
  player->pv = 500;
  player->pa = 6;
  player->pm = 3;
  player->level = 1;
  player->stat->class = 2;
  player->stat->strengh = 150;
  player->stat->luck = 0.1;
  return (0);
}

int	get_ecaflip(t_player *player)
{
  player->class = 2;
  player->pv = 500;
  player->pa = 6;
  player->pm = 3;
  player->level = 1;
  player->stat->class = 3;
  player->stat->strengh = 150;
  player->stat->luck = 0.1;
  return (0);
}

int	get_osa(t_player *player)
{
  player->class = 3;
  player->pv = 500;
  player->pa = 6;
  player->pm = 3;
  player->level = 1;
  player->stat->class = 4;
  player->stat->strengh = 150;
  player->stat->luck = 0.1;
  player->spriteboard = sfSprite_create();
  if ((player->texture = sfTexture_createFromFile(OSA_BOARD, NULL)) == NULL)
    return (1);
  sfSprite_setTexture(player->spriteboard, player->texture, sfTrue);
  return (0);
}
