/*
** my_strncmp.c for  in /home/BlackBirdz/CPool_Day06
** 
** Made by Laabid Zakaria
** Login   <BlackBirdz@epitech.net>
** 
** Started on  Mon Oct 10 22:49:16 2016 Laabid Zakaria
** Last update Wed May 10 16:23:33 2017 LAABID Zakaria
*/

#include <stdlib.h>

void	my_putchar(char c);

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = -1;
  if (s1 == NULL || s2 == NULL)
    return (84);
  while ((++i < n) && (s1[i] || s2[i]))
    if (s1[i] != s2[i])
      return (s1[i] - s2[i]);
  if (i == n)
    return (0);
  else
    return (84);
}
