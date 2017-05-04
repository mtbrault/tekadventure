/*
** get_texture.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Tue May  2 14:34:25 2017 Matthieu BRAULT
** Last update Thu May  4 12:06:16 2017 Matthieu BRAULT
*/

#include "tekadv.h"

sfSprite	*get_static_char(sfTexture *class, sfVector2i coord,
				 sfVector2f pos, sfVector2i div)
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
  sfSprite_setOrigin(sprite, ((sfVector2f) {(size.x / div.x) / 2, (size.y / div.y) / 6 * 5}));
  sfSprite_setPosition(sprite, pos);
  return (sprite);
}
