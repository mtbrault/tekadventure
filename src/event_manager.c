/*
** event_manager.c for tekadventure in /home/antoine.casse/Desktop/tekadventure
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sat May 27 12:39:42 2017 Capitaine CASSE
** Last update Sat May 27 18:28:24 2017 Matthieu BRAULT
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
  sfRenderWindow_drawSprite(window, game->quest, NULL);
  sfRenderWindow_drawText(window, text, NULL);
  sfText_destroy(text);
  sfSprite_destroy(game->quest);
  free(dialog);
  return (0);
}

int		show_events(sfRenderWindow *window, t_game *game)
{
  int		i;
  t_event	**event;
  sfVector2i	pos;

  i = 0;
  event = game->level->event;
  if (game->pnj == NULL)
    return (1);
  while (game->pnj[i] != NULL)
    {
      sfRenderWindow_drawSprite(window, game->pnj[i], NULL);
      sfSprite_destroy(game->pnj[i++]);
    }
  if (!(game->stop[0]) && sfMouse_isButtonPressed(sfMouseRight))
    {
      pos = raw_click(game, window);
      game->stop[0] = 1;
      //      printf("%d %d/ %d %d\n", pos.x, pos.y, event[0]->coords[0], event[0]->coords[1]);
      if (pos.x == (event[0])->coords[0] && pos.y == (event[0])->coords[1])
	{
	  printf("+1\n");
	  game->actions += 1;
	}
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
    show_dialog(window, event[0]->dialog, game);
  return (0);
}
