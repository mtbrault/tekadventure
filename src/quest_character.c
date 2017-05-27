/*
** quest_character.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sat May 27 03:23:28 2017 LAABID Zakaria
** Last update Sat May 27 18:33:04 2017 Matthieu BRAULT
*/

#include "config.h"
#include "tekadv.h"

static int	set_font(t_game *game)
{
  sfFont	*font;

  if ((font = sfFont_createFromFile("ressources/misc/arial.ttf")) == NULL)
    {
      game->font = NULL;
      return (1);
    }
  game->font = font;
  return (0);
}

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
  game->quest = sprite;
  //  sfTexture_destroy(tex);
  return (0);
}

static int	set_character(t_game *game, t_event *event, const int x)
{
  sfTexture	*tex;
  sfVector2f	mult_size;
  sfVector2u	size;
  sfVector2i	pnj_pos;
  sfSprite	*sprite;

  if ((tex = sfTexture_createFromFile(event->texture, NULL)) == NULL ||
      (sprite = sfSprite_create()) == NULL)
    return (1);
  size = sfTexture_getSize(tex);
  sfSprite_setTexture(sprite, tex, sfTrue);
  mult_size = get_mult_size(((sfVector2i)
    {(int)(size.x), (int)(size.y)}), game->tile);
  sfSprite_setScale(sprite, mult_size);
  pnj_pos = (sfVector2i) {event->coords[0], event->coords[1]};
  sfSprite_setOrigin(sprite, (sfVector2f) {size.x / 2, 4 * size.y / 5});
  sfSprite_setPosition(sprite, convert_pos(pnj_pos, game->tile));
  //  sfTexture_destroy(tex);
  game->pnj[x] = sprite;
  return (0);
}

int		quest_manager(t_game *game)
{
  t_event	**event;
  int		x;

  x = 0;
  event = game->level->event;
  if (event == NULL)
    return (1);
  set_font(game);
  while (event[x] != NULL)
    x += 1;
  if ((game->pnj = malloc(sizeof(sfSprite *) * (x + 1))) == NULL)
    return (1);
  game->pnj[x] = NULL;
  x = 0;
  while (event[x] != NULL)
    {
      set_font(game);
      if ((set_character(game, event[x], x)) == 1)
	return (FAIL);
      x += 1;
    }
  set_font(game);
  set_quest_disp(event[0]->quest_pic, game);
  return (0);
}
