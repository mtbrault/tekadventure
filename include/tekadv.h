/*
** tekadv.h for  in /home/BlackBIrdz/tekadventure
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Fri Apr 21 03:27:45 2017 LAABID Zakaria
** Last update Fri Apr 21 23:59:54 2017 Matthieu BRAULT
*/

#ifndef TEKADV_H
# define TEKADV_H

/*
** ***************************************************
**                     - INCLUDE -
** ***************************************************
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

/*
** ***************************************************
**                     - MACRO -
** ***************************************************
*/
# define NORMAL		(0)
# define FAIL		(-1)
# define ERROR		(84)
# define EOB		(-42)
# define S_TILE         (32)
# define SCR_W	        (1280)
# define SCR_H		(663)
# define STMENU_S	(4)

# define INV_SPECS	"Error : Invalid specifications.\n"
# define INV_MAP		"Error : Invalid map.\n"

# define HELP		"USAGE:\t./tekadventure [file]\n\tfile : map config file.\n"

# define MENU_PIC	(13)
# define STMENU_MAIN	"./ressources/menus/guimainmenu.png"
# define STMENU_CHARAC	"./ressources/menus/guicharacter.png"

# define MENU_NEWS	"./ressources/elements/nouveaute.png"
# define MENU_NEWS_H	"./ressources/elements/nouveaute_hover.png"
# define MENU_OPTION	"./ressources/elements/configuration.png"
# define MENU_OPTION_H	"./ressources/elements/configuration_hover.png"
# define MENU_SHOP	"./ressources/elements/sprite.png"
# define MENU_SHOP_H	"./ressources/elements/sprite_hover.png"
# define CHARAC_FECA	"./ressources/elements/feca.png"
# define CHARAC_FECA_H	"./ressources/elements/feca_hover.png"
# define CHARAC_IOP	"./ressources/elements/iop.png"
# define CHARAC_IOP_H	"./ressources/elements/iop_hover.png"
# define CHARAC_ECA	"./ressources/elements/eca.png"
# define CHARAC_ECA_H	"./ressources/elements/eca_hover.png"
# define CHARAC_OSA	"./ressources/elements/osamoda.png"
# define CHARAC_OSA_H	"./ressources/elements/osamoda_hover.png"

# define STMENU_PLAY	"./ressources/elements/jouer.png"
# define STMENU_PLAY_H	"./ressources/elements/jouer_hover.png"
# define STMENU_MULTI	"./ressources/elements/multijoueurs.png"
# define STMENU_CLOSE	"./ressources/elements/close.png"
# define STMENU_CLOSE_H	"./ressources/elements/close_hover.png"
# define STMENU_START	"./ressources/elements/start.png"
# define STMENU_START_H	"./ressources/elements/start_hover.png"

# define MUSIC_MAIN	"./ressources/music/dofas_menu.ogg"
# define MUSIC_CHARAC	"./ressources/music/dofas_character.ogg"

# define GRID_PATH      "./ressources/misc/tile.png"

/*
** ***************************************************
**                     - STRUCTURE -
** ***************************************************
*/
typedef struct		s_menu_conf
{
  char	*tex_path;
  char	*music_path;
  char	*hover_path;
}			t_menu_conf;

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
  sfTexture		*tex_h;
  sfSprite		*sprite;
  sfSprite		*sprite_h;
  int			hover;
  sfVector2f		pos;
  sfVector2f		pos_h;
  sfVector2u		size;
  sfVector2u		size_h;
  sfMusic		*music;
}			t_menu;

/*
** ***************************************************
**             - ARGS GESTURE / HELP / MAP -
** ***************************************************
*/
int			show_help(int, char **);
t_game			*get_file(char *);
int			free_map(int ***);

/*
** ***************************************************
**                   - MENU MANAGER -
** ***************************************************
*/
void			music_change(int, t_menu **);
void			sprite_change(sfRenderWindow *, int, t_menu **);
int			start_menu(t_game *, t_player *);
sfRenderWindow		*create_window(void);
t_menu			**disp_startmenu(void);

/*
** ***************************************************
**                    - SOME FUNC.. -
** ***************************************************
*/
void			debug(t_game *);
sfVector2i		get_mouse_pos(sfRenderWindow *);

/*
** ***************************************************
**                   - LIB FUNC UTILS -
** ***************************************************
*/
int			my_puterr(char *);
int			my_atoi(char *);
char			*get_next_line(int);
int			my_putstr(char *);
char			*my_strdup(char *);

#endif /* !TEKADV_H */
