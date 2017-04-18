/*
** get_next_line.c for get_next_line in /home/antoine.casse/Desktop/CPE_2016_getnextline
** 
** Made by Antoine Casse
** Login   <antoine.casse@epitech.net>
** 
** Started on  Tue Jan 10 09:48:12 2017 Antoine Casse
** Last update Tue Apr  4 14:02:27 2017 Capitaine CASSE
*/

#include "get_next_line.h"

int	read_buff(char *str, int b, int rs, int p)
{
  int	i;

  if (!str)
    return (0);
  if (!b)
    {
      i = 0;
      while (str[i])
	{
	  str[i] = 0;
	  i += 1;
	}
      return (0);
    }
  i = p;
  while ((i < rs) && (str[i]))
    {
      if (!str[i])
	return (1);
      if (str[i] == '\n')
	return (1);
      i += 1;
    }
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i])
    i += 1;
  return (i);
}

char	*my_strcat(char *str, char *new, int size)
{
  int	i;
  int	j;
  char	*cat;

  i = 0;
  if (!(cat = malloc(my_strlen(str) + size + 1)))
    return (NULL);
  if (str)
    {
      while (str[i])
	{
	  cat[i] = str[i];
	  i += 1;
	}
    }
  j = 0;
  while (j < size)
    {
      cat[i] = new[j];
      i += 1;
      j += 1;
    }
  cat[i] = 0;
  return (cat);
}

char	*fin(char *str, int *p)
{
  int		i;
  int		j;
  static char	*res;

  i = 0;
  while ((str[i]) && (str[i] != '\n'))
    i += 1;
  j = 0;
  if (!(res = malloc(i + 1)))
    return (NULL);
  while (j < i)
    {
      res[j] = str[j];
      j += 1;
    }
  res[j] = 0;
  *(p) += i + 1;
  return (res);
}

char		*get_next_line(const int fd)
{
  static int	i;
  static char	*str;
  int		size;
  char		buff[READ_SIZE + 1];
  static int	rs;

  if ((fd < 0) || (READ_SIZE < 1) || (i < 0))
    return (NULL);
  buff[READ_SIZE] = 0;
  if (read_buff(str, 1, rs, i))
    return (fin(str + i, &i));
  while ((size = read(fd, buff, READ_SIZE)) > 0)
    {
      str = my_strcat(str, buff, size);
      rs += size;
      if (read_buff(str, 1, rs, i))
	return (fin(str + i, &i));
      read_buff(buff, 0, rs, i);
    }
  if (i < my_strlen(str))
    return (fin(str + i, &i));
  return (NULL);
}
