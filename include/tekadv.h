/*
** tekadv.h for  in /home/BlackBIrdz/tekadventure
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Fri Apr 21 03:27:45 2017 LAABID Zakaria
** Last update Fri Apr 21 04:11:38 2017 LAABID Zakaria
*/

#ifndef TEKADV_H
# define TEKADV_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>

#define EOB		-42
#define SCR_W	        1280
#define SCR_H		663
#define STMENU_S	4

#define INV_SPECS	"Error : Invalid specifications.\n"
#define INV_MAP		"Error : Invalid map.\n"

#define HELP		"USAGE:\t./tekadventure [file]\n\tfile : map config file.\n"

#define MENU_PIC	(2)
#define STMENU_MAIN	"./ressources/menus/guimainmenu.png"
#define STMENU_CHARAC	"./ressources/menus/guicharacter.png"

typedef struct		s_game
{
  int			***map;
  char			**enemies;
}			t_game;

typedef struct		s_stat
{
  int			class;
  int			strengh;
  int			speed;
  int			mana;
  int			endurance;
  int			luck;
  int			patern;
}			t_stat;

typedef struct		s_player
{
  int			pv;
  int			pm;
  int			po;
  int			level;
  int			map;
  sfVector2i		pos;
  t_stat		*stat;
}			t_player;

typedef struct		s_menu
{
  sfTexture		*tex;
  sfSprite		*sprite;
  sfUint8		*pixels;
  int			hover;
  sfVector2f		pos;
  sfVector2u		size;
}			t_menu;

int			my_puterr(char *);
int			my_atoi(char *);
char			*get_next_line(int);

void			debug(t_game *);
int			my_putstr(char *);
char			*my_strdup(char *);
int			show_help(int, char **);
t_game			*get_file(char *);
int			start_menu(t_game *);
sfRenderWindow		*create_window(void);
t_menu			**disp_startmenu(void);
int			free_map(int ***);

#endif /* TEKADV_H */
