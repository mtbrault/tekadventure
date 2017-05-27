/*
** decor_manager.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sat May 27 19:48:43 2017 LAABID Zakaria
** Last update Sun May 28 01:25:29 2017 LAABID Zakaria
*/


#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "tekadv.h"

int		decor_manager(sfRenderWindow *window, t_game *game)
{
  sfTexture    	*tex;
  sfSprite	*sprite;

  if ((tex = sfTexture_createFromFile(game->level->map->decor, NULL)) == NULL)
    return (1);
  if ((sprite = sfSprite_create()) == NULL)
    return (1);
  sfSprite_setTexture(sprite, tex, sfTrue);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  return (0);
}
