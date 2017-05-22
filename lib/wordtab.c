/*
** my_wordtab.c for  in /home/Blackbirdz/CPE_2016_BSQ
** 
** Made by Zakaria LAABID
** Login   <Blackbirdz@epitech.net>
** 
** Started on  Mon Dec 12 15:24:17 2016 Zakaria LAABID
** Last update Mon May 22 15:00:55 2017 LAABID Zakaria
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	count_line(char *str, char param)
{
  int   i;
  int   c;

  i = 0;
  c = 0;
  while (str[i] != '\0')
    {
      if (str[i] == param)
	c = c + 1;
      i = i + 1;
    }
  return (c);
}

int	count_char(char *str, int i, char param)
{
  int   a;

  a = 0;
  while (str[i] != '\0' && str[i] != param)
    {
      i = i + 1;
      a = a + 1;
    }
  return (a);
}

char	**wordtab(char *str, char param)
{
  char	**tab;
  int   a;
  int   b;
  int   c;

  a = 0;
  b = 0;
  c = 0;
  tab = malloc(sizeof(char *) * (count_line(str, param) + 2));
  while (str[c] != '\0')
    {
      tab[a] = malloc(sizeof(char) * (count_char(str, c, param) + 1));
      while (str[c] != '\0' && str[c] != param)
	{
	  tab[a][b] = str[c];
	  c = c + 1;
	  b = b + 1;
	}
      tab[a][b] = '\0';
      c = c + 1;
      a = a + 1;
      b = 0;
    }
  tab[a] = NULL;
  return (tab);
}
