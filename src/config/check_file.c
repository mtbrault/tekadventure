/*
** check_file.c for  in /home/BlackBIrdz/tekadventure/src/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Mon May 22 17:12:48 2017 LAABID Zakaria
** Last update Mon May 22 17:31:16 2017 LAABID Zakaria
*/

#include "tekadv.h"

static int	check_dotfile(char *file)
{
  int	i;

  i = 0;
  while (file[i] != '\0')
    {
      if (file[i] == '.')
	return (i);
      i++;
    }
  return (FAIL);
}

int	check_file(char *file)
{
  int	status;

  if ((status = check_dotfile(file)) == FAIL)
    return (FAIL);
  if ((my_strcmp((file + status), FILECONF, my_strlen(FILECONF))) == 0)
    return (NORMAL);
  else
    return (FAIL);
  return (NORMAL);
}
