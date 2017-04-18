/*
** tekadv.h for Tekadventure in /home/antoine.casse/Desktop/tekadv
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 13:34:05 2017 Capitaine CASSE
** Last update Sun Apr 16 18:04:27 2017 Capitaine CASSE
*/

#ifndef TEKADV_H
# define TEKADV_H

#include <SFML/Graphics.h>

#define EOB		-42
#define SCR_W		1080
#define SCR_H		760
#define STMENU_S	4

#define INV_SPECS	"Error : Invalid specifications.\n"
#define INV_MAP		"Error : Invalid map.\n"

#define HELP		"USAGE:\t./tekadventure [file]\n\tfile : map config file.\n"

#define STMENU_TITLE	"./ressources/menus/start/title.png"
#define STMENU_PLAY	"./ressources/menus/start/play.png"
#define STMENU_OPT	"./ressources/menus/start/options.png"
#define STMENU_QUIT	"./ressources/menus/start/quit.png"

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
  char			*filepath;
  sfTexture		*tex;
  sfSprite		*sprite;
  int			hover;
  sfVector2i		pos;
  sfVector2i		size;
}			t_menu;

int			my_puterr(char *);
int			my_atoi(char *);
char			*get_next_line(int);

t_game			*get_file(char *);
int			start_menu(t_game *);
sfRenderWindow		*create_window();
int			disp_startmenu(sfRenderWindow *);
int			free_map(int ***);

#endif /* TEKADV_H */
