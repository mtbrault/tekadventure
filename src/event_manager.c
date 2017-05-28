/*
1;4402;0c** event_manager.c for tekadventure in /home/antoine.casse/Desktop/tekadventure
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sat May 27 12:39:42 2017 Capitaine CASSE
** Last update Sun May 28 11:09:22 2017 Capitaine CASSE
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "tekadv.h"

static char	*get_dialog(char *file, int *status)
{
  int		i;
  int		fd;
  char		*tmp;
  char		*str;

  if ((fd = open(file, O_RDONLY)) < 0)
    return (NULL);
  i = *status;
  while ((str = get_next_line(fd)) != NULL && --i > 0)
    free(str);
  if (str != NULL)
    {
      while ((tmp = get_next_line(fd)) != NULL)
	free(tmp);
    }
  close(fd);
  return (str);
}

static int      show_dialog(sfRenderWindow *window, char *dialogfile, t_game *game)
{
  sfText        *text;
  sfFont        *font;
  char		*dialog;

  if ((dialog = get_dialog(dialogfile, &(game->actions))) == NULL)
    {
      game->actions = 0;
      return (0);
    }
  if ((text = sfText_create()) == NULL)
    return (1);
  sfText_setString(text, dialog);
  sfText_setFont(text, game->font);
  sfText_setCharacterSize(text, 20);
  sfText_setPosition(text, (sfVector2f) {SCR_W - ((SCR_W/3) * 2) - 90, SCR_H -
	(SCR_H / 5) - SCR_H / 14});
  sfRenderWindow_drawText(window, text, NULL);
  sfText_destroy(text);
  free(dialog);
  return (0);
}

static int      set_character(t_game *game, t_event *event, sfRenderWindow *window)
{
  sfTexture     *tex;
  sfVector2f    mult_size;
  sfVector2u    size;
  sfVector2i    pnj_pos;
  sfSprite      *sprite;

  if (event == NULL || event->texture == NULL)
    return (1);
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
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfTexture_destroy(tex);
  sfSprite_destroy(sprite);
  return (0);
 }

static int	show_sprite(sfRenderWindow *window, t_game *game)
{
  int		i;
  t_event	**event;

  i = 0;
  event = game->level->event;
  while (event[i] != NULL)
    {
      set_character(game, event[i], window);
      i += 1;
    }
  return (0);
}

int		show_events(sfRenderWindow *window, t_game *game)
{
  int		i;
  t_event	**event;
  sfVector2i	pos;

  i = 0;
  event = game->level->event;
  show_sprite(window, game);
  if (!(game->stop[0]) && sfMouse_isButtonPressed(sfMouseRight))
    {
      pos = raw_click(game, window);
      game->stop[0] = 1;
      if (pos.x == (event[0])->coords[0] && pos.y == (event[0])->coords[1])
	game->actions += 1;
    }
  else if (!sfMouse_isButtonPressed(sfMouseRight))
    game->stop[0] = 0;
  if (game->actions && sfKeyboard_isKeyPressed(sfKeySpace) && !(game->stop[1]))
    {
      game->stop[1] = 1;
      game->actions += 1;
    }
  else if (!sfKeyboard_isKeyPressed(sfKeySpace))
    game->stop[1] = 0;
  if (game->actions)
    {
      set_quest_disp(window, event[0]);
      show_dialog(window, event[0]->dialog, game);
    }
  return (0);
}
