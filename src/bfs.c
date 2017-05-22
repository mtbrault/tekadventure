/*
1;4402;0c** bfs.c for tekadventure in /home/antoine.casse/Desktop/tmp/astar
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sat May  6 21:18:46 2017 Capitaine CASSE
** Last update Mon May 22 11:52:03 2017 Capitaine CASSE
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>
#include "tekadv.h"

t_list	tablist[4] = {
  {0, 1, NULL, NULL},
  {0, -1,  NULL, NULL},
  {1, 0, NULL, NULL},
  {-1, 0, NULL, NULL},
};

static int	remove_list(t_list **list, t_list *rm)
{
  t_list	*past;

  if (*list == rm)
    {
      *list = rm->next;
      //      printf("Stop %p\n", *list);
      return (0);
    }
  past = *list;
  while (past->next != rm && past->next != NULL)
    past = past->next;
  past->next = past->next->next;
  return (0);
}

static t_list	*add2list(int x, int y, t_list *old, t_list *past)
{
  t_list        *list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  list->x = x;
  list->y = y;
  list->next = old;
  if (old == NULL)
    list->links = NULL;
  else
    {
      if ((list->links = malloc(sizeof(t_list))) == NULL)
	return (NULL);
      list->links->links = past;
      list->links->x = past->x;
      list->links->y = past->y;
      list->links->next = past->links;
    }
  return (list);
}

static char	find_next(t_list **list, int **map, sfVector2i dest, t_list *pos)
{
  int		i;

  i = 0;
  //  printf("POS x%d y%d\n", pos->x - 1, pos->y - 1, dest.x - 1, pos->y - 1);
  while (i < 4)
    {
      if (map[pos->y + tablist[i].y][pos->x + tablist[i].x] > 0 &&
	  map[pos->y + tablist[i].y][pos->x + tablist[i].x] > map[pos->y][pos->x] + 1)
	{
	  *list = add2list(pos->x + tablist[i].x, pos->y + tablist[i].y, *list, pos);
	  map[pos->y + tablist[i].y][pos->x + tablist[i].x] =
	    map[pos->y][pos->x] + 1;
	  //	  printf("Added x%d y%d\n", pos->x + tablist[i].x - 1, pos->y + tablist[i].y - 1);
	  //	  printf("list x%d y%d (dest %d %d)\n", (*list)->x - 1, (*list)->y - 1, dest.x - 1, dest.y - 1);
	  if ((*list)->x == dest.x && (*list)->y == dest.y)
	    {
	      //  printf("Stop\n");
	      return (1);
	    }
	}
      i += 1;
    }
  //  printf("Removed x%d y%d\n", pos->x - 1, pos->y - 1);
  remove_list(list, pos);
  return (0);
}

sfVector2i	bfs_find(int **map, sfVector2i pos, sfVector2i dest)
{
  t_list	*list;
  t_list	*pars;
  int		i;

  list = add2list(pos.x, pos.y, NULL, NULL);
  map[list->y][list->x] = 0;
  while (list != NULL && (list->x != dest.x || list->y != dest.y))
    {
      pars = list;
      while (pars != NULL)
	{
	  if (find_next(&list, map, dest, pars))
	    break ;
	  pars = pars->next;
	}
    }
  if (list == NULL)
    return ((sfVector2i) {-1, -1});
  pars = list->links;
  i = 1;
  /* if (list->links->links->x - 1 == pos.x - 1 && list->links->links->y - 1 == pos.y - 1) */
  /*   { */
  /*     printf("way %d %d\n", dest.x - 1, dest.y -1); */
  /*     return ((sfVector2i) {dest.x - 1, dest.y - 1}); */
  /*   } */
  while (pars != NULL)
    {
      printf("Way %d-> x%d, y%d\n", i, pars->links->x - 1, pars->links->y - 1);
      i += 1;
      pars = pars->next;
    }
  return ((sfVector2i) {list->links->links->x - 1, list->links->links->y - 1});
}
