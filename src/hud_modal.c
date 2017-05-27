/*
** hud_modal.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sat May 27 02:12:23 2017 LAABID Zakaria
** Last update Sat May 27 03:30:17 2017 LAABID Zakaria
*/

#include "tekadv.h"

static sfSprite	*get_static_head(sfTexture *class, sfVector2i coord,
				 t_game *game, sfVector2i div)
{
  sfIntRect	rect;
  sfVector2u	size;
  sfSprite	*sprite;

  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, class, sfTrue);
  size = sfTexture_getSize(class);
  rect = (sfIntRect) {(size.x / div.x) * coord.x, (size.y / div.y) * coord.y,
		      size.x / div.x, size.y / div.y};
  sfSprite_setTextureRect(sprite, rect);
  sfSprite_setOrigin(sprite, ((sfVector2f)
    {(size.x / div.x) / 2, (size.y / div.y) / 6 * 5}));
  game = game;
  return (sprite);
}

int	        hud_placing(sfRenderWindow *window, t_game *game)
{
  sfTexture	*tex;
  sfSprite	*sprite;
  sfSprite	*head;
  sfTexture	*head_tex;

  if ((head_tex = sfTexture_createFromFile(HEAD_BOARD, NULL)) == NULL)
    return (1);
  if ((tex = sfTexture_createFromFile(HUD_PLAYER, NULL)) == NULL)
    return (1);
  if ((sprite = sfSprite_create()) == NULL)
    return (1);
  sfSprite_setTexture(sprite, tex, sfTrue);
  sfSprite_setPosition(sprite, (sfVector2f) {SCR_W - 490, SCR_H - 89});
  sfRenderWindow_drawSprite(window, sprite, NULL);
  head = get_static_head(head_tex, (sfVector2i)
			 {0, 1}, game, (sfVector2i) {1, 4});
  sfRenderWindow_drawSprite(window, head, NULL);
  sfSprite_destroy(sprite);
  sfTexture_destroy(tex);
  return (0);
}
