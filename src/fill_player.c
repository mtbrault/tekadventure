/*
** fill_player.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Fri Apr 21 23:32:41 2017 Matthieu BRAULT
** Last update Sun Apr 23 16:28:17 2017 Matthieu BRAULT
*/

#include "tekadv.h"

void	get_iop(t_player *player)
{
  player->pv = 500;
  player->pa = 6;
  player->pm = 3;
  player->level = 1;
  player->stat->class = 1;
  player->stat->strengh = 150;
  player->stat->luck = 0.1;
}

void	get_feca(t_player *player)
{
  player->pv = 500;
  player->pa = 6;
  player->pm = 3;
  player->level = 1;
  player->stat->class = 2;
  player->stat->strengh = 150;
  player->stat->luck = 0.1;
}

void	get_ecaflip(t_player *player)
{
  player->pv = 500;
  player->pa = 6;
  player->pm = 3;
  player->level = 1;
  player->stat->class = 3;
  player->stat->strengh = 150;
  player->stat->luck = 0.1;
}

void	get_osa(t_player *player)
{
  player->pv = 500;
  player->pa = 6;
  player->pm = 3;
  player->level = 1;
  player->stat->class = 4;
  player->stat->strengh = 150;
  player->stat->luck = 0.1;
}
