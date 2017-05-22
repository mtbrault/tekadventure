/*
** epur_str.c for tekadventure in /home/antoine.casse/Desktop/tekadventure
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Mon May 22 15:14:02 2017 Capitaine CASSE
** Last update Mon May 22 15:59:54 2017 Capitaine CASSE
*/

#include <unistd.h>

static void	get_len(const char *str, const char *rm, int *nb, int i)
{
  int		j;
  char		stop;

  stop = 0;
  while (str[i])
    {
      j = 0;
      while (rm[j])
	{
	  if (str[i] == rm[j])
	    break ;
	  j += 1;
	}
      if (j < strlen(rm))
	stop = 1;
      else
	{
	  if (stop == 1)
	    *nb += 1;
	  stop = 0;
	  *nb += 1;
	}
      i += 1;
    }
}

static void	fill_new(const char *str, const char *rm, char *new, int j)
{
  char		stop;
  int		i[2];

  i[0] = 0;
  while (str[i[0]])
    {
      i[1] = 0;
      while (rm[i[1]])
	{
	  if (str[i[0]] == rm[i[1]])
	    break ;
	  i[1] += 1;
	}
      if (i[1] < strlen(rm))
	stop = 1;
      else
	{
	  if (stop)
	    new[j++] = ' ';
	  stop = 0;
	  new[j++] = str[i[0]];
	}
      i[0] += 1;
    }
}

char	*my_epurstr(const char *str, const char *rm)
{
  int	len;
  char	*new;

  if (str == NULL || rm == NULL)
    return (NULL);
  len = 0;
  get_len(str, rm, &len, 0);
  if ((new = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  new[len] = 0;
  fill_new(str, rm, new, 0);
  return (new);
}
