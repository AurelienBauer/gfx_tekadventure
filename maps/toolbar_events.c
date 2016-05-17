/*
** toolbar_events.c for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Fri Apr 15 15:18:03 2016 Thomas HENON
** Last update Sun Apr 17 14:37:13 2016 John Doe
*/

#include "maps.h"

char				on_toolbar_click_handler(t_windows *windows)
{
  t_linkedlist			*btns;
  t_button			*btn;
  const t_bunny_position	*mouse_pos;

  mouse_pos = bunny_get_mouse_position();
  btns = windows->buttons;
  while (btns)
    {
      btn = (t_button*)btns->data;
      if (mouse_pos->x >= btn->pos.x &&
	  mouse_pos->x <= (btn->width + btn->pos.x) &&
          mouse_pos->y >= btn->pos.y &&
    	  mouse_pos->y <= (btn->height + btn->pos.y))
	  btn->on_click(windows);
      btns = btns->next;
    }
}

t_bunny_response		on_toolbar_click(t_bunny_event_state state,
						 t_bunny_mouse_button but,
						 void *data)
{
  t_windows			*windows;
  const t_bunny_window		*cur_win;

  windows = (t_windows*)data;
  cur_win = bunny_get_window();
  if (cur_win == windows->buffer[0] && state == 0)
    on_toolbar_click_handler(windows);
  return (GO_ON);
}

t_bunny_response	on_toolbar_close(const t_bunny_window *win,
				      void *data)
{
  t_windows		*wins;

  wins = (t_windows*)data;
  wins->buffer[0] = NULL;
  bunny_stop((t_bunny_window*)bunny_get_window());
  bunny_delete_clipable(&wins->buff_background[0]->clipable);
  free_btns(wins);
  return (EXIT_ON_SUCCESS);
}

char			set_toolbar_context(t_windows *windows)
{
  t_bunny_context	*context;

  if (NULL == (context = bunny_malloc(sizeof(t_bunny_context))))
    return (0);
  context->close = on_toolbar_close;
  context->click = on_toolbar_click;
  context->move = on_wins_mouse_move;
  context->display = display_wins;
  windows->contexts[0] = set_toolbar_context;
  bunny_set_context(context);
  bunny_free(context);
  return (1);
}
