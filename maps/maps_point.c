/*
** maps_point.c for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Sun Apr 17 13:20:57 2016 Thomas HENON
** Last update Sun Apr 17 13:20:58 2016 thomas
*/

#include "maps.h"

void				win_map_remove_point(t_windows *windows)
{
  t_linkedlist			*positions;
  t_bunny_position		*position;
  const t_bunny_position	*mouse_pos;
  int				pos[2];
  char				flag;

  flag = 0;
  mouse_pos = bunny_get_mouse_position();
  positions = windows->positions;
  while (positions)
    {
      position = (t_bunny_position*)positions->data;
      pos[0] = ABS((position->x - mouse_pos->x));
      pos[1] = ABS((position->y - mouse_pos->y));
      if (pos[0] <= POINT_RAY && pos[1] <= POINT_RAY)
	{
	  delete_elem(&windows->positions, position);
	  flag = 1;
	}
      positions = positions->next;
    }
  if (flag)
    win_map_redraw_btns(windows);
}

char				win_map_draw_point(t_windows *windows,
					t_bunny_position *pos,
					char point_action)
{
  t_bunny_position		*dest_pos;

  if (NULL == (dest_pos = bunny_malloc(sizeof(t_point))))
    return (0);
  dest_pos->x = pos->x + POINT_RAY;
  dest_pos->y = pos->y + POINT_RAY;
  if (point_action == PUT_POINT_ACTON)
    my_set_circle(windows->buff_background[1], pos, dest_pos, BLUE);
  else if (point_action == PUT_MOVE_POINT_ACTON)
    my_set_circle(windows->buff_background[1], pos, dest_pos, YELLOW);
  else if (point_action == PUT_START_POINT_ACTION)
    my_set_circle(windows->buff_background[1], pos, dest_pos, GREEN);
  return (1);
}

char				win_map_put_point(t_windows *windows)
{
  t_point			*point;
  const t_bunny_position	*mouse_pos;

  if (windows->maps->point_action == PUT_MOVE_POINT_ACTON &&
      has_point_type(windows->positions, PUT_MOVE_POINT_ACTON))
    return (1);
  if (windows->maps->point_action == PUT_START_POINT_ACTION &&
      has_point_type(windows->positions, PUT_START_POINT_ACTION))
    return (1);
  if (windows->maps->point_action == NONE_POINT_ACTION)
    return (0);
  mouse_pos = bunny_get_mouse_position();
  if (NULL == (point = bunny_malloc(sizeof(t_point))))
    return (0);
  point->pos_origin = *mouse_pos;
  point->type = windows->maps->point_action;
  if (win_map_draw_point(windows, (t_bunny_position*)mouse_pos,
		     windows->maps->point_action))
    push_back(&windows->positions, (void*)point);
  return (1);
}
