/*
** toolbar_buttons_events.c for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Fri Apr 15 15:17:54 2016 Thomas HENON
** Last update Sun Apr 17 13:10:14 2016 John Doe
*/

#include "maps.h"

char		on_load_maps1_click(void *data)
{
  t_windows	*windows;

  windows = (t_windows*)data;
  if (windows->buffer[1] == NULL)
    win_map(1, windows, "mountain_l.png");
  return (1);
}

char		on_load_maps2_click(void *data)
{
  t_windows	*windows;

  windows = (t_windows*)data;
  if (windows->buffer[1] == NULL)
    win_map(2, windows, "mountains3.png");
  return (1);
}

char		on_save_maps_click(void *data)
{
  t_windows	*windows;

  windows = (t_windows*)data;
  if (windows->buffer[1] != NULL)
    serialize_ini_buttons(windows);
}

char		on_place_start_point_click(void *data)
{
  t_windows	*windows;

  windows = (t_windows*)data;
  if (windows->buffer[1] != NULL && windows->maps)
    windows->maps->point_action = PUT_START_POINT_ACTION;
  return (1);
}

char		on_place_point_click(void *data)
{
  t_windows	*windows;

  windows = (t_windows*)data;
  if (windows->buffer[1] != NULL && windows->maps)
    windows->maps->point_action = PUT_POINT_ACTON;
  return (1);
}
