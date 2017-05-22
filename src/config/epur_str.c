/*
** epur_str.c for  in /home/Blackbirdz/PSU_2016_minishell1
1;4402;0c** 
** Made by Zakaria LAABID
** Login   <Blackbirdz@epitech.net>
** 
** Started on  Thu Jan 26 02:39:54 2017 Zakaria LAABID
** Last update Mon May 22 16:44:30 2017 LAABID Zakaria
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*epur_str(char *str)
{
  char	*new_str;
  int	i;
  int	k;

  i = 0;
  k = 0;
  new_str = malloc(sizeof(char *) * my_strlen(str));
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] != '\0')
    {
      if ((str[i] != ' ' || str[i + 1] != ' ') &&
	  (str[i] != '\t' || str[i + 1] != '\t'))
	new_str[k++] = str[i];
      i++;
    }
  new_str[k] = '\0';
  if (new_str[k - 1] == ' ' || new_str[k - 1] == '\t')
    new_str[k - 1] = '\0';
  return (new_str);
}
