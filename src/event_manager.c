/*
1;4402;0c** event_manager.c for tekadventure in /home/antoine.casse/Desktop/tekadventure
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sat May 27 12:39:42 2017 Capitaine CASSE
** Last update Sat May 27 14:00:03 2017 Capitaine CASSE
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
  *status += 1;
  while ((str = get_next_line(fd)) != NULL && i-- > 0)
    free(str);
  if (str != NULL)
    {
      while ((tmp = get_next_line(fd)) != NULL)
	free(tmp);
    }
  return (str);
}

static int      show_dialog(sfRenderWindow *window, char *dialogfile,
			     int *status, sfSprite *sprite)
{
  sfText        *text;
  sfFont        *font;
  char		*dialog;

  if ((dialog = get_dialog(dialogfile, status)) == NULL)
    {
      sfText_destroy(text);
      *status = 0;
      printf("hello\n");
      return (0);
    }
  printf("Yes %s\n", dialog);
  text = sfText_create();
  font = sfFont_createFromFile("ressources/misc/arial.ttf");
  sfText_setString(text, dialog);
  sfText_setFont(text, font);
  sfText_setCharacterSize(text, 20);
  sfText_setPosition(text, (sfVector2f) {SCR_W - ((SCR_W/3) * 2) - 90, SCR_H -
	(SCR_H / 5) - SCR_H / 14});
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfRenderWindow_drawText(window, text, NULL);
  sfText_destroy(text);
  free(dialog);
  return (0);
}

int		show_events(sfRenderWindow *window, t_game *game)
{
  int		i;
  t_event	**event;
  sfVector2i	pos;

  i = 0;
  //  printf("evetn\nt");
  event = game->level->event;
  while (event[i] != NULL)
    {
      if (event[i]->sprite != NULL)
	{
  //  sfTexture_destroy(tex);
	  sfRenderWindow_drawSprite(window, event[i]->sprite, NULL);
	  printf("affd %d %p %s\n", i, event[i]->sprite, event[i]->texture);
	}
      if (sfMouse_isButtonPressed(sfMouseLeft))
	{
	  pos = raw_click(game, window);
	  if (pos.x == event[i]->coords[0] && pos.y == event[i]->coords[1])
	    event[i]->active += 1;
	}
      if (event[i]->active)
	{
	  if ((sfKeyboard_isKeyPressed(sfKeySpace)))
	    event[i]->active += 1;
	  show_dialog(window, event[i]->dialog,
		      &(event[i]->active), event[i]->quest_sprite);
	}
      i += 1;
    }
  return (0);
}
