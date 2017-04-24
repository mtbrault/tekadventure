/*
** mouse_check.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Mon Apr 24 04:06:54 2017 LAABID Zakaria
** Last update Mon Apr 24 04:07:10 2017 LAABID Zakaria
*/

#include "tekadv.h"

int	my_check_exit(sfVector2i mouse_pos)
{
  if (mouse_pos.x >= 573 && mouse_pos.x <= 767 &&
	   mouse_pos.y >= 356 && mouse_pos.y <= 390)
    {
      exit(0);
      return (1);
    }
  return (NORMAL);
}

int	my_check_config(sfVector2i mouse_pos)
{
  if (mouse_pos.x >= 442 && mouse_pos.x <= 536 &&
      mouse_pos.y >= 519 && mouse_pos.y <= 595)
    return (1);
  if (mouse_pos.x >= 270 && mouse_pos.x <= 475 &&
      mouse_pos.y >= 180 && mouse_pos.y <= 210)
    return (2);
  return (NORMAL);
}
