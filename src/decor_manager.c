/*
** decor_manager.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sat May 27 19:48:43 2017 LAABID Zakaria
** Last update Sat May 27 20:30:51 2017 LAABID Zakaria
*/


#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "tekadv.h"

static char	**decor_parsing(char *file)
{
  int		fd;
  char		buff[4096];
  char		**tab;

  if ((fd = open(file, O_RDONLY)) < 0)
    return (NULL);
  if ((read(fd, buff, 4096)) == -1)
    return (NULL);
  if ((tab =wordtab(buff, '\n')) == NULL)
    return (NULL);
  close(fd);
  return (tab);
}

static char	*get_decor(char **tab, int pos)
{
  char		*str;
  
  if ((str = my_strdup(tab[0])) == NULL)
    return (NULL);
  return (str);
}

int		decor_manager(sfRenderWindow *window, t_game *game)
{
  char		*decor_path;
  char		**tab;
  sfTexture    	*tex;
  sfSprite	*sprite;

  if ((tab = decor_parsing(game->level->map->decor)) == NULL)
    return (1);
  if ((decor_path = get_decor(tab, 0)) == NULL)
    return (1);
  if ((tex = sfTexture_createFromFile(decor_path, NULL)) == NULL)
    return (1);
  if ((sprite = sfSprite_create()) == NULL)
    return (1);
  sfSprite_setTexture(sprite, tex, sfTrue);
  sfSprite_setPosition(sprite, (sfVector2f) {500, 500});
  sfRenderWindow_drawSprite(window, sprite, NULL);
  return (0);
}
