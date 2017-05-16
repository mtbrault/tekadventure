/*
** main.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Wed May  3 15:00:49 2017 LAABID Zakaria
** Last update Fri May  5 10:56:47 2017 LAABID Zakaria
*/

#include "config.h"

int	main(int argc, char **argv)
{
  argc = argc;
  if ((config_fill(argv)) == -1)
    return (84);
}
