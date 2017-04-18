/*
** tools2.c for minishell1 in /home/antoine.casse/Desktop/PSU_2016_minishell1
** 
** Made by Antoine Casse
** Login   <antoine.casse@epitech.net>
** 
** Started on  Mon Jan 16 10:35:40 2017 Antoine Casse
** Last update Mon Feb 20 13:43:09 2017 Capitaine Casse
*/

#include "lkaas.h"

int	get_word(char *str, char *tab)
{
  int	j;
  int	l;

  j = 0;
  l = 0;
  while ((str[j] != ' ') && (str[j]) && (str[j] != '\t'))
    {
      tab[l] = str[j];
      l += 1;
      j += 1;
    }
  tab[l] = 0;
  return (j);
}

char	**get_tab(int j, char *str)
{
  int   i;
  int   k;
  int	l;
  char  **tab;

  if (!(tab = malloc(sizeof(char *) * (j + 2))))
    return (NULL);
  i = 0;
  k = 0;
  while (str[i])
    {
      j = i;
      while ((str[j] != ' ') && (str[j]) && (str[j] != '\t'))
	j += 1;
      if (!(tab[k] = malloc(j)))
	return (NULL);
      j = i;
      l = 0;
      i += get_word(str + i, tab[k]);
      while ((str[i] == ' ') || (str[i] == '\t'))
	i += 1;
      k += 1;
    }
  tab[k] = NULL;
  return (tab);
}

char	**str_to_wordtab(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i++])
    {
      if ((str[i] == ' ') || (str[i] == '\t'))
	{
	  j += 1;
	  while ((str[i] == ' ') || (str[i] == '\t'))
	    i += 1;
	  if (!str[i])
	    return (get_tab(j, str));
	}
    }
  return (get_tab(j + 1, str));
}
