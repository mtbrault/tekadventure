/*
** config.h for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Wed May  3 16:53:19 2017 LAABID Zakaria
** Last update Mon May 22 17:06:00 2017 LAABID Zakaria
*/

#ifndef CONFIG_H_
#define CONFIG_H_

# define CONF_LEVEL	"CONF-LEVEL-"
# define MOBS_NB	"mobs-nb:"
# define EVENT_NB	"event-nb:"
# define TELEP_NB	"teleporter-nb:"

# define L_CONF		(11)
# define L_TPNAME	(7)
# define L_MOB		(5)
# define L_NAME		(5)
# define L_TEXT		(8)
# define L_LIFE		(5)
# define L_DMG		(7)
# define L_PM		(3)
# define L_PA		(3)
# define L_COORD	(7)
# define L_EVENT	(6)

# define MOBS		"mobs:"
# define EVENT		"event:"

# define MOBS_LIST	"8"
# define MOBS_NAME	"name:"
# define MOBS_TEXT	"texture:"
# define MOBS_LIFE	"life:"
# define MOBS_DMG	"damage:"
# define MOBS_PM	"pm:"
# define MOBS_PA	"pa:"
# define MOBS_COORD	"coords:"
# define MOBS_TYPE	"monster-"

# define TELEP_TYPE	"tp-"
# define TELEP_COORD	"coords:"
# define TELEP_NAME	"tp-name:"

# define EVENT_TYPE	"items-"
# define EVENT_NAME	"name:"
# define EVENT_COORD	"coords:"
# define EVENT_TEXT	"texture:"
  
# define MAP_START	"map:"
# define MAP_CONTENT	"map-content:"
# define MAP_NAME	"map-name:"
# define MAP_DEBUG	"map-debug:"
# define MAP_BG		"map-bg:"

typedef struct	s_map
{
  char	**content;
  char	*name;
  int	debug;
  char	*bg;
}		t_map;

typedef struct	s_tp
{
  int	coords[2];
  char	*next_map;
}		t_tp;

typedef struct	s_mob
{
  char	*name;
  char	*texture;
  int	life;
  int	damage;
  int	pm;
  int	pa;
  int	coords[2];
}		t_mob;

typedef struct s_event
{
  char	*name;
  char	*texture;
  int	coords[2];
}		t_event;

typedef struct	s_level
{
  t_map		*map;
  t_tp		**tp;
  t_mob		**mob;
  t_event	**event;
}		t_level;

/*
** ***************************************************
**                  - CONFIF FILE -
** ***************************************************
*/
int		config_event_one(t_level **, char **, int, int);
int		config_event_two(t_level **, char **, int, int);
int		config_telep_one(t_level **, char **, int, int);
int		config_telep_two(t_level **, char **, int, int);
int		config_goto(char *, char **, int);
int		config_mob_one(t_level **, char **, int, int);
int		config_mob_two(t_level **, char **, int, int);
int		config_mob_three(t_level **, char **, int, int);
int		config_mob_four(t_level **, char **, int, int);
int		nbrepur(char *);
int		map_content_index(char **, int);
int		**map_content_fill(char **, int, char *);
t_level		**config_map_fill(t_level **, char **, int);
int		config_mob_fill(t_level **, char **, int);
int		config_event_fill(t_level **, char **, int);
int		config_telep_fill(t_level **, char **, int); 
int		getconf_nbr(char **, char *);
char		*getconf(char **, char *);
char		*unquote(char *);
char		**conf_init(char **);
void		conf_disp(char **);
t_level		**config_data(char **);
t_level		**gen_config_space(t_level **, char **);
t_level		**gen_event_space(t_level **, char **, int);
t_level		**gen_telep_space(t_level **, char **, int);
t_level		**gen_mob_space(t_level **, char **, int);
int		conf_counter(char **, char *);
char		*getconf(char **, char *);
int		find_to_zero(int);
char		*my_str_nbr(int);
int		getconf_index(char **, char *, int);

/*
** ***************************************************
**                  - UTILS FUNC -
** ***************************************************
*/
char		**wordtab(char *, char);
char		*my_strdup(char *str);
int		my_strlen(char *str);
int		my_printf(char *str,...);
int		my_put_nbr(int nb);
void		my_putchar(char c);
void		my_put_error(char *str_error);
int		my_getnbr(char *str);
int		my_putstr(char *str);
int		my_strcmp(char *s1, char *s2, int n);
int		my_strncmp(char *s1, char *s2, int n);
char		*epur_str(char *str);
char		*my_strcat(char *dest, char *src);
int		my_atoi(char *);

#endif /* CONFIG_H_ */
