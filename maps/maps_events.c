/*
** maps_events.c for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Sun Apr 17 13:20:51 2016 Thomas HENON
** Last update Sun Apr 17 14:36:41 2016 John Doe
*/

#include "maps.h"

t_bunny_response		win_map_on_click(t_bunny_event_state state,
						 t_bunny_mouse_button key,
						 void *data)
{
  t_windows			*windows;

  windows = (t_windows*)data;
  if (!state)
    return (GO_ON);
  if (windows->maps->point_action == REMOVE_POINT_ACTION)
    win_map_remove_point(windows);
  else
    win_map_put_point(windows);
  return (GO_ON);
}

t_bunny_response	win_map_on_close(const t_bunny_window *win,
					 void *data)
{
  t_windows		*wins;

  wins = (t_windows*)data;
  if (wins->buffer[1] == NULL)
    return (SWITCH_CONTEXT);
  bunny_stop((t_bunny_window*)wins->buffer[1]);
  bunny_delete_clipable(&wins->buff_background[1]->clipable);
  bunny_delete_clipable(&wins->maps->original_background->clipable);
  bunny_free(wins->maps);
  free_positions(wins);
  wins->buffer[1] = NULL;
  wins->maps = NULL;
  return (SWITCH_CONTEXT);
}

char			set_win_map_context(t_windows *windows)
{
  t_bunny_context	*context;

  if (NULL == (context = bunny_malloc(sizeof(t_bunny_context))))
    return (0);
  context->close = win_map_on_close;
  context->click = win_map_on_click;
  context->move = on_wins_mouse_move;
  context->display = display_wins;
  windows->contexts[1] = set_win_map_context;
  bunny_set_context(context);
  bunny_free(context);
  return (1);
}
