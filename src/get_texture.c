/*
** get_texture.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Tue May  2 14:34:25 2017 Matthieu BRAULT
** Last update Tue May  2 15:04:42 2017 Matthieu BRAULT
*/

#include "tekadv.h"

sfSprite	*get_static_char(sfTexture *class, sfVector2i coord, sfVector2f pos)
{
  sfIntRect	rect;
  sfVector2u	size;
  sfSprite	*sprite;

  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, class, sfTrue);
  size = sfTexture_getSize(class);
  rect = (sfIntRect) {(size.x / 8) * coord.x, (size.y / 4) * coord.y,
		      size.x / 8, size.y / 4};
  sfSprite_setTextureRect(sprite, rect);
  sfSprite_setPosition(sprite, pos);
  return (sprite);
}
