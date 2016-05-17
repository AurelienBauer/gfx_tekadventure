/*
** maps.h for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps/includes
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Fri Apr 15 15:22:01 2016 Thomas HENON
** Last update Sun Apr 17 11:42:06 2016 John Doe
*/

#ifndef __MAPS_H__
# define __MAPS_H__

# include <lapin.h>
# include <math.h>
# include "my.h"
# include "tektext.h"
# include "button.h"
# include "linkedlists.h"
# include "explorer.h"

# define DEGREES_TO_RADIANS(angleDegrees) (angleDegrees * M_PI / 180.0)
# define ABS(x) (x < 0) ? -x : x
# define SUCCESS_ALERT_TYPE 0
# define INFO_ALERT_TYPE 1
# define ERROR_ALERT_TYPE 2

# define WIN_SLOTS 10

typedef struct		s_dim
{
  unsigned int		width;
  unsigned int		height;
}			t_dim;

# define PUT_START_POINT_ACTION 0
# define PUT_MOVE_POINT_ACTON 1
# define PUT_POINT_ACTON 2
# define REMOVE_POINT_ACTION 3
# define NONE_POINT_ACTION 4

# define POINT_RAY 10

# define TOOLBAR_WIDTH 250
# define TOOLBAR_HEIGHT 700

typedef struct		s_maps
{
  t_bunny_pixelarray	*original_background;
  char			point_action;
  int			scene_nbr;
}			t_maps;

typedef struct		s_windows
{
  t_bunny_window	*buffer[WIN_SLOTS];
  t_bunny_pixelarray	*buff_background[WIN_SLOTS];
  char			(*contexts[WIN_SLOTS])();
  t_linkedlist		*buttons;
  t_explorer		*explorer;
  t_linkedlist		*positions;
  t_maps		*maps;
}			t_windows;

typedef struct		s_point
{
  t_bunny_position	pos_origin;
  char			type;
}			t_point;

char			on_new_maps_click(void *data);
char			on_save_maps_click(void *data);
char			on_load_maps_click(void *data);
char			on_place_point_click(void *data);
char			on_delete_point_click(void *data);

void			resize_buffer_loops(t_bunny_pixelarray *buffer, t_resizer *rsz);
t_bunny_pixelarray	*resize_buffer(t_bunny_pixelarray *buffer);

char		    	*my_strcat(char *str1, char *str2);
char			*concat_path(char *str1, char *str2);

t_bunny_response	display_wins(void *data);
char			new_toolbar_btn(t_windows *windows,
					char *text,
					char (*callback)(void*));
char			init_toolbar_btn(t_windows *windows);
char			on_toolbar_click_handler(t_windows *windows);
t_bunny_response	on_toolbar_click(t_bunny_event_state state,
					 t_bunny_mouse_button but,
					 void *data);
t_bunny_response	on_wins_mouse_move(const t_bunny_position *relative,
					  void *data);
t_bunny_response	on_wins_close(const t_bunny_window *win,
				     void *data);
char			set_toolbar_context(t_windows *windows);

void			my_set_empty_circle(t_bunny_pixelarray *pix,
					    t_bunny_position *origin,
					    t_bunny_position *dist,
					    unsigned int color);
void			my_set_circle(t_bunny_pixelarray *pix,
				      t_bunny_position *origin,
				      t_bunny_position *dist,
				      unsigned int color);
void			empty_circle(t_bunny_pixelarray *pix,
				     t_bunny_position *pos_mouse,
				     unsigned int color);
void			circle(t_bunny_pixelarray *pix,
			       t_bunny_position *pos_mouse,
			       unsigned int color);
t_bunny_pixelarray	*cpy_pixelarray(t_bunny_pixelarray *src);
char			win_map_draw_point(t_windows *windows,
					   t_bunny_position *pos,
					   char point_action);

char		on_load_maps1_click(void *data);
char		on_load_maps2_click(void *data);
char		on_save_maps_click(void *data);
char		on_place_start_point_click(void *data);
char		on_place_point_click(void *data);
char		on_next_maps_point_click(void *data);

char			has_point_type(t_linkedlist *positions, char type);
void			init_wins_slots(t_windows *windows);
int			get_wins_slot(t_windows *windows);

#endif
