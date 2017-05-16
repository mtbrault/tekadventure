/*
** epur_str.c for  in /home/Blackbirdz/PSU_2016_minishell1
** 
** Made by Zakaria LAABID
** Login   <Blackbirdz@epitech.net>
** 
** Started on  Thu Jan 26 02:39:54 2017 Zakaria LAABID
** Last update Mon May 15 14:35:47 2017 LAABID Zakaria
*/

#include <stdlib.h>
#include "config.h"

static int	verif_endline(char *str, int nb)
{
  int		count;
  int		get;

  get = nb;
  count = 0;
  if (str == NULL || str[get] == '\0')
    return (0);
  while (str[get] != '\0' && (str[get] == ' ' ||
			      str[get] == '\t'))
    {
      get = get + 1;
      count = count + 1;
    }
  if (str[get] != '\0')
    return (0);
  return (count);
}

static char	*epur_spaces(char *str, int *nb, char *new, int *get)
{
  int		count;

  if ((count = verif_endline(str, *nb)) == 0)
    new[*get] = ' ';
  else
    {
      *nb = *nb + count;
      return (new);
    }
  while (str[*nb] != '\0' && (str[*nb] == '\t' ||
			      str[*nb] == ' '))
    *nb = *nb + 1;
  *get = *get + 1;
  return (new);
}

char	*epur_str(char *str)
{
  char	*new;
  int	get;
  int	nb;

  get = 0;
  nb = 1;
  if (str == NULL || nb != 0 ||
      (new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[nb] != '\0' && (str[nb] == ' ' || str[nb] == '\t'))
    nb = nb + 1;
  if (str[nb] == '\0')
    return ("\0");
  while (str[nb] != '\0')
    {
      if (str[nb] == ' ' || str[nb] == '\t')
	new = epur_spaces(str, &nb, new, &get);
      else
	{
	  new[get] = str[nb];
	  nb = nb + 1;
	  get = get + 1;
	}
    }
  new[get] = '\0';
  free(str);
  return (new);
}
