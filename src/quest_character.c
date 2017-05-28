/*
** quest_character.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sat May 27 03:23:28 2017 LAABID Zakaria
** Last update Sun May 28 12:10:01 2017 Matthieu BRAULT
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

int	set_quest_disp(sfRenderWindow *window, t_event *event)
{
  sfTexture    	*tex;
  sfSprite	*sprite;
  sfVector2u	size;

  event->quest_sprite = NULL;
  if ((tex = sfTexture_createFromFile(event->quest_pic, NULL)) == NULL)
    return (1);
  if ((sprite = sfSprite_create()) == NULL)
    return (1);
  size = sfTexture_getSize(tex);
  sfSprite_setTexture(sprite, tex, sfTrue);
  sfSprite_setPosition(sprite, (sfVector2f) {SCR_W - (size.x + 140),
	SCR_H - (size.y + 50)});
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfTexture_destroy(tex);
  sfSprite_destroy(sprite);
  return (0);
}

int		quest_manager(t_game *game)
{
  t_event	**event;

  event = game->level->event;
  if (event == NULL)
    return (1);
  set_font(game);
  return (0);
}
