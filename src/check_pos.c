/*
** check_pos.c for Tekadventure in /home/antoine.casse/Desktop/tekadventure/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Thu May 25 15:43:49 2017 Capitaine CASSE
** Last update Sat May 27 17:55:12 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include "tekadv.h"

static int	free_room(t_game *game)
{
  int		i;

  i = 0;
  /* if (game->pnj != NULL) */
  /*   { */
  /*     while (game->pnj[i] != NULL) */
  /* 	{ */
  /* 	  sfSprite_destroy(game->pnj[i]); */
  /* 	  i += 1; */
  /* 	} */
  /*     free(game->pnj); */
  /*     game->pnj = NULL; */
  /*   } */
  game->pnj = NULL;
  /* if (game->quest != NULL) */
  /*   sfSprite_destroy(game->quest); */
  game->quest = NULL;
  return (0);
}

int	check_hud_click(sfRenderWindow *window, int i)
{
  sfVector2i	mouse;
  sfVector2i	y;

  if (sfMouse_isButtonPressed(sfMouseLeft))
    {
      mouse = get_mouse_pos(window);
      y = ((sfVector2i) {590, 654});
      if (check_class_pos(((sfVector2i) {1184, 1260}), y, mouse) == 1)
	exit(0);
      else if (check_class_pos(((sfVector2i) {1092, 1162}), y, mouse) == 1)
	return (-i);
      else if (check_class_pos(((sfVector2i) {997, 1070}), y, mouse) == 1)
	return (2);
    }
  return (i);
}

static int	check_tp(sfVector2i pos, t_tp **tp, t_player *player, t_game *game)
{
  int		i;

  i = 0;
  while (tp[i] != NULL)
    {
      if (pos.x == (tp[i])->coords[0] && pos.y == (tp[i])->coords[1])
	{
	  player->pos = (sfVector2i) {0, 0};
	  if ((tp[i])->room != NULL)
	    {
	      free_room(game);
	      game->level = (tp[i])->room;
	      player->pos = (sfVector2i) {(tp[i])->room->map->map_player[0],
		(tp[i])->room->map->map_player[1] };
	      print_bg(game);
	      quest_manager(game);
	      printf("Changed to %s\n", (tp[i])->room->map->name);
	    }
	  return (0);
	}
      i += 1;
    }
  return (0);
}

int	check_pos(t_player *player, t_game *game)
{
  check_tp(player->pos, game->level->tp, player, game);
  return (0);
}
