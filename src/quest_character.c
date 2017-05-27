/*
** quest_character.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sat May 27 03:23:28 2017 LAABID Zakaria
** Last update Sat May 27 05:34:46 2017 LAABID Zakaria
*/

#include "config.h"
#include "tekadv.h"

static int	quest_dialog(sfRenderWindow *window, char *dialog)
{
  sfText	*text;
  sfFont	*font;

  text = sfText_create();
  font = sfFont_createFromFile("ressources/misc/arial.ttf");
  sfText_setString(text, dialog);
  sfText_setFont(text, font);
  sfText_setCharacterSize(text, 20);
  sfText_setPosition(text, (sfVector2f) {SCR_W - ((SCR_W/3) * 2) - 90, SCR_H - (SCR_H / 5) - SCR_H / 14});
  sfRenderWindow_drawText(window, text, NULL);
  sfText_destroy(text);
  return (0);
}

static int	quest_disp(sfRenderWindow *window, char *picture)
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
  sfSprite_setPosition(sprite, (sfVector2f) {SCR_W - (size.x + 140), SCR_H - (size.y + 50)});
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfSprite_destroy(sprite);
  sfTexture_destroy(tex);
  return (0);
}

static int	quest_character(sfRenderWindow *window, t_game *game, int x)
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
  if ((sprite = sfSprite_create()) == NULL)
    return (1);
  size = sfTexture_getSize(tex);
  sfSprite_setTexture(sprite, tex, sfTrue);
  mult_size = get_mult_size(((sfVector2i)
    {(int)(size.x), (int)(size.y)}), game->tile);
  sfSprite_setScale(sprite, mult_size);
  pnj_pos = (sfVector2i) {event[x]->coords[0], event[0]->coords[1]};
  sfSprite_setPosition(sprite, convert_pos(pnj_pos, game->tile));
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfSprite_destroy(sprite);
  sfTexture_destroy(tex);
  return (0);
}

int		quest_manager(sfRenderWindow *window, t_game *game)
{
  t_event	**event;
  int		x;

  x = 0;
  event = game->level->event;
  while (x < 3)
    {
      if ((quest_character(window, game, x)) == 1)
	return (FAIL);
      x++;
    }
  quest_disp(window, event[0]->quest_pic);
  quest_dialog(window, event[0]->dialog);
  return (0);
}
