/*
** fill_player.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Fri Apr 21 23:32:41 2017 Matthieu BRAULT
** Last update Sun Apr 23 16:04:16 2017 Matthieu BRAULT
*/

#include "tekadv.h"

void	get_iop(sfRenderWindow *window, t_player *player, t_game *game)
{
  player->pv = 500;
  player->pa = 6;
  player->pm = 3;
  player->level = 1;
  player->stat->class = my_strdup("Iop");
  player->stat->strengh = 150;
  player->stat->luck = 0.1;
  show_grid(window, game);
}

void	get_feca(sfRenderWindow *window, t_player *player, t_game *game)
{
  player->pv = 500;
  player->pa = 6;
  player->pm = 3;
  player->level = 1;
  player->stat->class = my_strdup("Feca");
  player->stat->strengh = 150;
  player->stat->luck = 0.1;
  show_grid(window, game);
}

void	get_ecaflip(sfRenderWindow *window, t_player *player, t_game *game)
{
  player->pv = 500;
  player->pa = 6;
  player->pm = 3;
  player->level = 1;
  player->stat->class = my_strdup("Ecaflip");
  player->stat->strengh = 150;
  player->stat->luck = 0.1;
  show_grid(window, game);
}

void	get_osa(sfRenderWindow *window, t_player *player, t_game *game)
{
  player->pv = 500;
  player->pa = 6;
  player->pm = 3;
  player->level = 1;
  player->stat->class = my_strdup("Osa");
  player->stat->strengh = 150;
  player->stat->luck = 0.1;
  show_grid(window, game);
}
