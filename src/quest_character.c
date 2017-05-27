/*
** quest_character.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sat May 27 03:23:28 2017 LAABID Zakaria
** Last update Sat May 27 13:56:17 2017 Capitaine CASSE
*/

#include "config.h"
#include "tekadv.h"

static int	set_quest_disp(char *picture, t_game *game)
{
  sfTexture    	*tex;
  sfSprite	*sprite;
  sfVector2u	size;

  if ((tex = sfTexture_createFromFile(picture, NULL)) == NULL)
    return (1);
  if ((sprite = sfSprite_create()) == NULL)
    return (1);
  size = sfTexture_getSize(tex);
  sfSprite_setTexture(sprite, tex, sfTrue);
  sfSprite_setPosition(sprite, (sfVector2f) {SCR_W - (size.x + 140),
	SCR_H - (size.y + 50)});
  game->level->event[0]->quest_sprite = sprite;
  //  sfTexture_destroy(tex);
  return (0);
}

static int	set_character(t_game *game, int x)
{
  sfTexture	*tex;
  sfSprite	*sprite;
  t_event	**event;
  sfVector2f	mult_size;
  sfVector2u	size;
  sfVector2i	pnj_pos;

  event = game->level->event;
  if ((tex = sfTexture_createFromFile(event[x]->texture, NULL)) == NULL)
    return (1);
  printf("tex %s\n", event[x]->texture);
  if ((sprite = sfSprite_create()) == NULL)
    return (1);
  size = sfTexture_getSize(tex);
  sfSprite_setTexture(sprite, tex, sfTrue);
  mult_size = get_mult_size(((sfVector2i)
    {(int)(size.x), (int)(size.y)}), game->tile);
  sfSprite_setScale(sprite, mult_size);
  pnj_pos = (sfVector2i) {event[x]->coords[0], event[x]->coords[1]};
  sfSprite_setPosition(sprite, convert_pos(pnj_pos, game->tile));
  //  sfTexture_destroy(tex);
  event[x]->sprite = sprite;
  printf("sprite %d\n", x);
  return (0);
}

int		quest_manager(t_game *game)
{
  t_event	**event;
  int		x;

  x = 0;
  event = game->level->event;
  while (event[x] != NULL)
    {
      event[x]->active = 0;
      if ((set_character(game, x)) == 1)
	return (FAIL);
      x++;
    }
  set_quest_disp(event[0]->quest_pic, game);
  return (0);
}
