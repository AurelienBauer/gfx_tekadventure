/*
** main.c for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Fri Apr 15 15:17:39 2016 Thomas HENON
** Last update Sun Apr 17 14:31:43 2016 John Doe
*/

#include "maps.h"

void	init_wins_slots(t_windows *windows)
{
  int	i;

  i = 0;
  while (i < WIN_SLOTS)
    windows->buffer[i++] = NULL;
}

int	get_wins_slot(t_windows *windows)
{
  int	i;

  i = 0;
  while (i < WIN_SLOTS)
    {
      if (windows->buffer[i] == NULL)
	return (i);
      i++;
    }
  return (-1);
}

int		main(int argc, char **argv)
{
  t_windows	*windows;
  int		win_slot;

  bunny_set_maximum_ram(50000000);
  if (NULL == (windows = bunny_malloc(sizeof(t_windows))))
    return (1);
  init_wins_slots(windows);
  win_slot = get_wins_slot(windows);
  windows->buffer[win_slot] = bunny_start_style(TOOLBAR_WIDTH, TOOLBAR_HEIGHT,
					 TITLEBAR | CLOSE_BUTTON,
					 "Barre d'outils");
  if (NULL == (windows->buff_background[win_slot] =
	       bunny_new_pixelarray(TOOLBAR_WIDTH, TOOLBAR_HEIGHT)))
    return (1);
  fill_buffer(windows->buff_background[win_slot], BLACK);
  init_toolbar_btn(windows);
  set_toolbar_context(windows);
  while (SWITCH_CONTEXT == bunny_loop_mw(windows->buffer, WIN_SLOTS,
					 50, windows))
    {}
  return (0);
}
