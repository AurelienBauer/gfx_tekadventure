/*
** paralax.h for parallax in /home/antoine/Desktop/parallax
**
** Made by Antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Mar  6 05:16:45 2016 Antoine
** Last update Sun Apr 17 15:11:28 2016 
*/

#ifndef PARALLAX_H_
# define PARALLAX_H_
# include "lapin.h"
# define t_parallax t_game
# define s_parallax s_game
# define FPS 60
# define WIDTH 1600
# define HEIGHT 800
# define TITLE "Game"
# define LOADING "loading.png"
# define MAX_RAM 50000000
# define MUSIC "music.wav"
# define DEFAULT_INI_POS "test1.ini"
# define NB_ELEM_INI 6
# define PIC_POS "pos.jpg"
# define INT 0
# define PRT_CHAR 1
# define DEFAULT_NO_VALUE -42
# define DEFAULT_INT_TAB_LEN 255
# define DEFAULT_CHAR_TAB_LEN 513
# define PLAYER_SPEED_AUTO 20
# define END_STR '\0'
# define INVE_WIDTH 540
# define INVE_HEIGHT 280
# define WIN_WIDTH 1000
# define WIN_HEIGHT 700
#include <stdlib.h>
#include <math.h>

typedef struct		s_position
{
  int			index;
  int			is_first;
  int			tmp_path[255];
  void			*graph;
  int			is_next;
  int			coordinate[255];
  char			*msg;
  struct s_position	*next;
}			t_position;

typedef struct		s_scope
{
  void			*scope;
  struct s_scope	*next;
}			t_scope;

typedef struct		s_player
{
  t_bunny_pixelarray	*sprite;
  t_bunny_pixelarray	*character;
  t_bunny_position	step;
  t_bunny_position	pos;
}			t_player;

typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
}			t_list;

typedef	struct		s_srcs_pix
{
  t_bunny_pixelarray	*pix_right;
  t_bunny_pixelarray	*pix_left;
}			t_srcs_pix;

typedef struct          s_bunny_square
{
  t_bunny_position      pos;
  int                   width;
  int                   height;
}                       t_bunny_square;

typedef struct          s_line
{
  unsigned int          color;
  double                coef;
  double                temp;
  t_bunny_square        square;
}                       t_line;

typedef struct		s_items
{
  t_bunny_pixelarray	*sword_img;
  t_bunny_pixelarray	*shield_img;
}			t_items;

typedef struct		s_inventaire
{
  t_bunny_pixelarray	**case_ivt;
  t_bunny_pixelarray	*texture;
  t_bunny_pixelarray	*move;
}			t_inventaire;

typedef struct		s_mv_item
{
  t_bunny_pixelarray	**item;
  t_bunny_pixelarray	*save;
  int			clik;
  int			i;
}			t_mv_item;

typedef struct          s_dialog_box
{
  t_bunny_pixelarray    *font;
  t_bunny_pixelarray    *texture;
  char                  *str;
}                       t_dialog_box;

typedef struct			s_game
{
  unsigned int			menu_open;
  unsigned int			is_first;
  unsigned int			is_open;
  t_bunny_pixelarray		*bgnd;
  t_bunny_pixelarray		*fgnd;
  t_bunny_pixelarray		*mgnd1;
  t_bunny_pixelarray		*mgnd3;
  t_bunny_pixelarray		*menu;
  t_bunny_pixelarray		*res;
  t_bunny_window		*win;
  t_bunny_position		pos_fgnd;
  t_bunny_position		pos_mgnd1;
  t_bunny_position		pos_mgnd3;
  t_bunny_position		pos;
  t_bunny_position		mouse_pos;
  t_position			*graph;
  t_position			*current_node;
  t_position			*to_go;
  t_position			*graph_to_go;
  t_bunny_pixelarray		*pic_node;
  t_inventaire			inv;
  t_player			cha;
  t_dialog_box			box;
}				t_game;

int			my_strcmp(char *s, char *s1);
void			my_strcpy(char *s, char *s1);
int			str_to_int(char *str);
t_bunny_ini		*get_ini(const char *file_name);
t_scope			*init_scope(void *scope);
t_scope			*append_scope(t_scope *head, void *scope);
t_scope			*get_scope(t_bunny_ini *ini);
short			init_node_graph(t_position *list, t_position *entity,
					const int pos);
short			append_node_graph(t_position *list, t_position *entity,
					  const int pos);
int			check_proper_graph(t_position *list);
int			produce_graph(t_position *list);
void			my_mensetab_int(int *tab, int len, int value);
void			my_mensetab_char(char *tab, int len, char value);
int			set_entity(void *entity, void *scope, const char *field,
				   const int *infos);
int			get_info(t_position *entity, void *scope);
t_position		*init_graph(void *scope);
t_position		*append_graph(t_position *head, void *scope);
void			free_graph(t_position *list);
int			check_index(t_position *list, unsigned int i,
				    unsigned int len);
t_position		*fill_graph(t_scope *scopes);
t_position		*get_graph(const char *file_name);
void			*make_graph_copy(void *graph);
void			append_two_graph(t_position *to_had_entity, void *graph);
void			complete_graph_path(t_position *graph);
short			is_in_already_in_graph(int *tab, int item);
void			delete_node(t_scope *node, t_scope **head);
void			clean_graph_remove_same(t_position *graph);
void			clean_graph(t_position *graph, int i);
int			can_reach(t_position *entity, const int index);
void			*get_path(t_position *entity, const int index, unsigned int i);
void			*get_path_next(t_position *entity, const int index, int curnt);
int			cursor_aabb_collision(int cursor_x, int cursor_y, int pos_x,
					      int pos_y);
void			display_graph(t_position *graph,
				      t_bunny_pixelarray *bg,
				      t_bunny_pixelarray *pic);
void			my_blit(t_bunny_pixelarray *,
				t_bunny_pixelarray *,
				t_bunny_position *);
void			tekpixel_alpha(t_bunny_pixelarray*,
				       t_bunny_position *,
				       unsigned int);
void			stretch(t_bunny_pixelarray *,
				t_bunny_pixelarray *);
void			calc_parallax(t_game *game);
int			load_game(t_game *par);
t_bunny_response	on_refresh(void *data);
void			display_player(t_game *game);
void			tekchar(t_bunny_pixelarray *out,
				t_bunny_position *step,
				t_bunny_pixelarray *sprite);
void			fill_color(t_bunny_pixelarray *ar,
				   unsigned int color);
t_bunny_response	mouse(t_bunny_event_state state,
			      t_bunny_mousebutton key, void *ptr_data);
void			set_position_player(t_player *player, const int x,
					    const int y);
void			move_player_cursor_position(t_player *ply, int x, int y);
void			adjuste_player_position(t_player *player, int x, int y,
						int *buff_xy);
t_color			get_res_col(t_color *col,
				    t_color *prec_col,
				    float ratio_alpha);
void			display_game(t_game *par);
void			free_one(t_game *game);
t_bunny_response	display_next(t_game *game);

/*
** square.c
*/
void                    square(t_bunny_pixelarray *pix,
                               t_bunny_square *squ,
                               unsigned int color);

void                    square_xn_yn(t_bunny_pixelarray *pix,
                                     t_bunny_square *squ,
                                     unsigned int color);

void                    square_xn_yp(t_bunny_pixelarray *pix,
                                     t_bunny_square *squ,
                                     unsigned int color);

void                    square_xp_yn(t_bunny_pixelarray *pix,
                                     t_bunny_square *squ,
                                     unsigned int color);

void                    square_xp_yp(t_bunny_pixelarray *pix,
                                     t_bunny_square *squ,
                                     unsigned int color);

/*
** blit_pix.c
*/
void                    blit_pix(t_bunny_pixelarray *background,
                                 t_bunny_pixelarray *buffer,
                                 t_bunny_position *pos);
/*
** inventory.c
*/
void			init_inventory(t_bunny_pixelarray *pix,
				       t_bunny_position pos,
				       t_inventaire ivt);
/*
** mouse.c
*/
void			inventory_mouse(t_bunny_position *inve_pos,
					int inventory_is_open);
int			outside_win_height(const t_bunny_position *mouse_pos);
int                     outside_win_width(const t_bunny_position *mouse_pos);

/*
** line
*/

void                    line(t_bunny_pixelarray *pix,
                             t_bunny_square squar,
                             t_bunny_position pos2,
                             unsigned int color);
/*
** empty_square
*/
void			empty_square(t_bunny_pixelarray *pix,
				     t_bunny_square squar,
				     unsigned int color,
				     int size);

/*
** addnew_elem_inlist
*/
t_list                  *addnew_elem_inlist(t_list *list, void *data);

/*
** square_alpha
*/
void                    square_alpha(t_bunny_pixelarray *pix,
                                     t_bunny_square *squ,
                                     unsigned int color);

/*
** invent_mouve_item
*/
t_bunny_pixelarray      **mouve_item(t_bunny_pixelarray *pix,
				     t_bunny_pixelarray **item,
				     t_list *list,
				     t_bunny_position *pos);
void			display_inventory(t_bunny_position pos,
					  t_bunny_pixelarray *pix,
					  t_inventaire ivt);

/*
** text_box
*/
void			dialog_box(t_bunny_pixelarray *, t_dialog_box,
				   t_bunny_square *);

void			tektext(t_bunny_pixelarray *,
				t_bunny_pixelarray *,
				t_bunny_position *,
				char *);

#endif
