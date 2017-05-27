/*
** game_sound.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sat May 27 05:38:32 2017 LAABID Zakaria
** Last update Sat May 27 18:24:12 2017 Matthieu BRAULT
*/

#include "tekadv.h"

int		sound_manager(t_game *game)
{
  sfMusic	*music;

  if ((music = sfMusic_createFromFile(game->level->map->music)) == NULL)
    return (FAIL);
  sfMusic_play(music);
  sfMusic_setLoop(music, sfTrue);
  return (3);
}
