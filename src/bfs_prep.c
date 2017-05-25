/*
** astar.c for Dante in /home/antoine.casse/Desktop/dante/astar
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Mon Apr 17 12:00:11 2017 Capitaine CASSE
** Last update Thu May 25 15:01:53 2017 Capitaine CASSE
*/

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <tekadv.h>

static int	*fill_line(int c, int max)
{
  int		i;
  int		*line;

  i = 0;
  if ((line = malloc(sizeof(int) * (max))) == NULL)
    return (NULL);
  while (i < max)
    {
      line[i] = c;
      i += 1;
    }
  return (line);
}

static int	**build_path(int **map, const sfVector2i origin,
			     const sfVector2i size)
{
  int		**path;
  int		i;
  int		j;

  i = 1;
  if ((path = malloc(sizeof(int *) * (size.y + 2))) == NULL)
    return (NULL);
  path[0] = fill_line(-1, size.x + 2);
  path[size.y + 1] = fill_line(-1, size.x + 2);
  while (i < size.y + 1)
    {
      if ((path[i] = malloc(sizeof(int) * (size.x + 2))) == NULL)
	return (NULL);
      path[i][0] = -1;
      j = 1;
      while (j < size.x + 1)
	{
	  if (map[i - 1][j - 1])
	    path[i][j] = 1000;
	  else
	    path[i][j] = -1;
	  j += 1;
	}
      path[i][j] = -1;
      i += 1;
    }
  return (path);
}

sfVector2i 	my_bfs(sfVector2i origin, sfVector2i dest,
				 int **map, sfVector2i tile)
{
  int		**path;
  t_list	*list;
  sfVector2i	final;
  sfVector2f	res;
  sfVector2i	size;
  int		i;
  int		j;

  size.x = 0;
  size.y = 0;
  while (map[0][size.x] != EOB)
    size.x += 1;
  while (map[size.y] != NULL)
    size.y += 1;
  if (dest.x >= size.x || dest.y >= size.y || dest.x < 0 || dest.y < 0)
    return ((sfVector2i) {-1, -1});
  else if (!map[dest.y][dest.x])
    return ((sfVector2i) {-1, -1});
  if ((path = build_path(map, origin, size)) == NULL)
    return ((sfVector2i) {-1, -1});
  origin = (sfVector2i) {origin.x + 1, origin.y + 1};
  dest = (sfVector2i) {dest.x + 1, dest.y + 1};
  final = bfs_find(path, dest, origin);
  return (final);
}
