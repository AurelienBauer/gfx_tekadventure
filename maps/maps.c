/*
** maps.c for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Fri Apr 15 15:17:44 2016 Thomas HENON
** Last update Sun Apr 17 13:12:06 2016 John Doe
*/

#include "maps.h"

char			win_map_redraw_btns(t_windows *windows)
{
  t_linkedlist		*positions;
  t_point		*point;
  t_bunny_position	dest_pos;

  positions = windows->positions;
  bunny_delete_clipable(&windows->buff_background[1]->clipable);
  if (NULL == (windows->buff_background[1] =
	       cpy_pixelarray(windows->maps->original_background)))
    return (0);
  while (positions)
    {
      point = (t_point*)positions->data;
      win_map_draw_point(windows, &point->pos_origin, point->type);
      positions = positions->next;
    }
  return (1);
}

char		has_point_type(t_linkedlist *positions, char type)
{
  t_point	*point;

  while (positions)
    {
      point = (t_point*)positions->data;
      if (point->type == type)
	return (1);
      positions = positions->next;
    }
  return (0);
}

void		free_positions(t_windows *windows)
{
  t_linkedlist	*positions;
  t_point	*point;

  positions = windows->positions;
  while (positions)
    {
      point = (t_point*)positions->data;
      bunny_free(point);
      positions = positions->next;
    }
  free_list(windows->positions);
  windows->positions = NULL;
}

char		win_map(int scene_nbr,
			t_windows *windows,
			char *background_path)
{
  if (NULL == (windows->maps = bunny_malloc(sizeof(t_maps))))
    return (0);
  windows->maps->scene_nbr = scene_nbr;
  windows->maps->original_background = bunny_load_pixelarray(background_path);
  if (NULL == windows->maps->original_background)
    return (my_putstr("Failed to load background\n"));
  windows->buff_background[1] =
  cpy_pixelarray(windows->maps->original_background);
  if (NULL == windows->buff_background[1])
    return (my_putstr("Failed to load background\n"));
  windows->buffer[1] = bunny_start(
	windows->buff_background[1]->clipable.clip_width,
	windows->buff_background[1]->clipable.clip_height,
				   false, "Plan de travail");
  if (NULL == windows->buffer[1])
    return (my_putstr("Failed to load window\n"));
  windows->positions = NULL;
  windows->maps->point_action = NONE_POINT_ACTION;
  set_win_map_context(windows);
  return (1);
}
