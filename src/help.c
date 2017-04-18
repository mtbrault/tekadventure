/*
** help.c for Tekacventure in /home/antoine.casse/Desktop/tekadv
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 17:15:10 2017 Capitaine CASSE
** Last update Sun Apr 16 18:03:54 2017 Capitaine CASSE
*/

#include "tekadv.h"

int	show_help(int ac, char **av)
{
  int	i;

  i = 0;
  while (i < ac)
    {
      if (av[i][0] == '-' && av[i][1] == 'h' && !av[i][2])
	{
	  my_putstr(HELP);
	  return (1);
	}
      i += 1;
    }
  return (0);
}
