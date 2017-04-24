/*
** tekadv.h for  in /home/BlackBIrdz/tekadventure
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sat Apr 22 00:10:23 2017 LAABID Zakaria
** Last update Mon Apr 24 23:24:54 2017 LAABID Zakaria
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
# define SCR_H	        (663)
# define SCR_W		(1280)
# define STMENU_S	(4)

# define MENU		(0)
# define CHARAC		(1)
# define PLAY		(2)
# define MULTI		(3)
# define CLOSE		(4)
# define START		(5)
# define NEWS		(6)
# define OPTION		(7)
# define SHOP		(8)
# define FECA		(9)
# define IOP		(10)
# define ECA		(11)
# define OSA		(12)
# define S_FECA		(13)
# define S_ECA		(14)
# define S_OSA		(15)
# define CONFIG		(16)
# define BT_OFF		(17)
# define BT_SAVE	(18)
# define BT_BACK	(19)
# define BT_ON_V       	(20)
# define BT_ON_B       	(21)
# define BT_ON_D       	(22)
# define BT_OF_V       	(23)
# define BT_OF_B       	(24)
# define BT_OF_D       	(25)
# define LOADING	(26)

# define INV_SPECS	"Error : Invalid specifications.\n"
# define INV_MAP		"Error : Invalid map.\n"

# define HELP		"USAGE:\t./tekadventure [file]\n\tfile : map config file.\n"

# define MENU_PIC	(27)
# define STMENU_MAIN	"./ressources/menus/guimainmenu.png"
# define STMENU_CHARAC	"./ressources/menus/guicharacter.png"
# define STMENU_OPTION	"./ressources/menus/guiconfiguration.png"
# define STMENU_LOADING	"./ressources/menus/chargement.png"

# define MENU_NEWS	"./ressources/elements/nouveaute.png"
# define MENU_NEWS_H	"./ressources/elements/nouveaute_hover.png"
# define MENU_OPTION	"./ressources/elements/configuration.png"
# define MENU_OPTION_H	"./ressources/elements/configuration_hover.png"
# define BUTTON_BACK	"./ressources/elements/button_back.png"
# define BUTTON_BACK_H	"./ressources/elements/button_back_hover.png"
# define BUTTON_ON	"./ressources/elements/button_on.png"
# define BUTTON_ONH	"./ressources/elements/button_on_hover.png"
# define BUTTON_OFF	"./ressources/elements/button_off.png"
# define BUTTON_SAVE	"./ressources/elements/button_save.png"
# define BUTTON_SAVE_H	"./ressources/elements/button_save_hover.png"
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
# define MUSIC_LOADING	"./ressources/music/dofas_loading.ogg"

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

typedef struct		s_game_conf
{
  int	vol;
  int	border;
  int	debug;
}			t_game_conf;

typedef struct		s_game
{
  int			***map;
  char			**enemies;
  sfVector2i		tile;
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
  int			pa;
  int			pm;
  int			level;
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
**                   - MOUSE EVENT -
** ***************************************************
*/
int			my_check_class(sfRenderWindow *, t_player *);
int			check_class_pos(sfVector2i, sfVector2i, sfVector2i);
int			my_check_click(sfRenderWindow *, int);
int			my_check_config(sfVector2i);
int			mouse_func(sfRenderWindow *, int, t_player *, t_menu **);
int			my_check_exit(sfVector2i);

/*
** ***************************************************
**                   - GAME MANAGER -
** ***************************************************
*/
void			get_osa(t_player *);
void			get_ecaflip(t_player *);
void			get_iop(t_player *);
void			get_feca(t_player *);

/*
** ***************************************************
**                   - MAP MANAGER -
** ***************************************************
*/
int			raw_click(t_game *, sfRenderWindow *);

/*
** ***************************************************
**                   - MENU MANAGER -
** ***************************************************
*/
void			hover_button(sfRenderWindow *, sfVector2i, t_menu **);
void			hover_panels(sfRenderWindow *, sfVector2i, t_menu **);
void			hover_character(sfRenderWindow *, sfVector2i, t_menu **);
void			hover_play(sfRenderWindow *, sfVector2i, t_menu **);
void			hover_config(sfRenderWindow *, sfVector2i, t_menu **);
void			music_change(int, t_menu **);
void			sprite_change(sfRenderWindow *, int, t_menu **);
int			start_menu(t_game *, t_player *);
sfRenderWindow		*create_window(void);
t_menu			**disp_startmenu(void);
void			set_position_panels(t_menu **);
void			set_position_button(t_menu **);
void			set_position_start(t_menu **);
void			set_position_character(t_menu **);
void			set_position_config(t_menu **);
void			set_position_config_s(t_menu **);

/*
** ***************************************************
**                    - SOME FUNC.. -
** ***************************************************
*/
void			debug(t_game *);
sfVector2i		get_mouse_pos(sfRenderWindow *);
int			show_grid(sfRenderWindow *, t_game *);

/*
** ***************************************************
**                   - LIB FUNC UTILS -
** ***************************************************
*/
int			my_puterr(char *, int);
int			my_atoi(char *);
char			*get_next_line(int);
int			my_putstr(char *);
char			*my_strdup(char *);

#endif /* !TEKADV_H */
