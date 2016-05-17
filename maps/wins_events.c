/*
** wins_events.c for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Fri Apr 15 15:18:10 2016 Thomas HENON
** Last update Fri Apr 15 15:18:11 2016 thomas
*/

#include "maps.h"

t_bunny_response	display_wins(void *data)
{
  t_windows		*wins;
  t_bunny_position	pos;
  int			i;

  wins = (t_windows*)data;
  pos.x = 0;
  pos.y = 0;
  i = 0;
  while (i < WIN_SLOTS)
    {
      if (wins->buffer[i])
	{
	  bunny_blit(&wins->buffer[i]->buffer,
		     &wins->buff_background[i]->clipable,
		     &pos);
	  bunny_display(wins->buffer[i]);
	}
      i++;
    }
  return (GO_ON);
}

t_bunny_response	on_wins_mouse_move(const t_bunny_position *relative,
					  void *data)
{
  const t_bunny_window	*cur_win;
  t_windows	*windows;

  windows = (t_windows*)data;
  cur_win = bunny_get_window();
  if (cur_win == windows->buffer[0])
    windows->contexts[0]();
  if (cur_win == windows->buffer[1])
    windows->contexts[1]();
  return (GO_ON);
}

t_bunny_response	on_win_default_close(const t_bunny_window *win,
					     void *data)
{
  t_windows		*wins;
  int			i;

  i = 0;
  wins = (t_windows*)data;
  while (i < WIN_SLOTS)
    {
      if (wins->buffer[i] == win)
	{
	  bunny_delete_clipable(&wins->buff_background[i]->clipable);
	  wins->buffer[i] = NULL;
	  return (EXIT_ON_SUCCESS);
	}
      i++;
    }
  return (SWITCH_CONTEXT);
}

/*
t_bunny_response	on_wins_close(const t_bunny_window *win,
				     void *data)
{
  t_windows		*wins;

  wins = (t_windows*)data;
  if (wins->buffer[0] == bunny_get_window())
    {
      bunny_delete_clipable(&wins->buff_background[0]->clipable);
      wins->buffer[0] = NULL;
      return (EXIT_ON_SUCCESS);
    }
  bunny_stop((t_bunny_window*)bunny_get_window());
  if (wins->buffer[1] == bunny_get_window())
    {
      bunny_delete_clipable(&wins->buff_background[1]->clipable);
      wins->buffer[1] = NULL;
    }
  return (SWITCH_CONTEXT);
}
*/
