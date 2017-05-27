/*
** show_player.c for tekadventure in /home/antoine.casse/Desktop/tekadventure
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Fri May 26 22:51:43 2017 Capitaine CASSE
** Last update Sat May 27 13:31:47 2017 Capitaine CASSE
*/

#include "tekadv.h"

static int	new_dest(sfRenderWindow *window, t_player *player, t_game *game)
{
  player->s = 0;
  player->sprt = 0;
  player->dest = raw_click(game, window);
  player->next = my_bfs(player->pos, player->dest,
			game->level->map->content);
  if (player->next.x == -1 && player->next.y == -1)
    {
      player->dest.x = -1;
      player->dest.y = -1;
      return (1);
    }
  my_move(window, game, player);
  return (0);
}

static int	player_static(sfRenderWindow *window,
			      t_player *player, t_game *game)
{
  sfSprite	*sprite;

  //printf("Hello\n");
  sprite = get_static_char(player->classe_texture, ((sfVector2i) {player->dir,
	  player->class}), game, ((sfVector2i) {8, 4}));
  sfSprite_setPosition(sprite, convert_pos(player->pos, game->tile));
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfSprite_destroy(sprite);
  return (0);
}

static int	new_next(t_game *game, t_player *player)
{
  player->pos = player->next;
  if (player->pos.x == player->dest.x && player->pos.y == player->dest.y)
    {
      check_pos(player, game);
      player->dest.x = -1;
      player->dest.y = -1;
      return (1);
    }
  player->s = 0;
  player->next = my_bfs(player->pos, player->dest,
			game->level->map->content);
  return (0);
}

int		show_player(sfRenderWindow *window,
			    t_player *player, t_game *game)
{
  if (sfMouse_isButtonPressed(sfMouseLeft))
    new_dest(window, player, game);
  else if (player->dest.x == -1 && player->dest.y == -1)
    player_static(window, player, game);
  else if (!my_move(window, game, player))
    new_next(game, player);
  return (0);
}
