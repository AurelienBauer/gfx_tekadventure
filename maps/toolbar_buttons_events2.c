/*
** toolbar_buttons_events2.c for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Fri Apr 15 15:24:05 2016 Thomas HENON
** Last update Sun Apr 17 13:10:17 2016 John Doe
*/

#include "maps.h"

char		on_next_maps_point_click(void *data)
{
  t_windows	*windows;

  windows = (t_windows*)data;
  if (windows->buffer[1] != NULL && windows->maps)
    windows->maps->point_action = PUT_MOVE_POINT_ACTON;
  return (1);
}

char		on_delete_point_click(void *data)
{
  t_windows	*windows;

  windows = (t_windows*)data;
  if (windows->buffer[1] != NULL && windows->maps)
    windows->maps->point_action = REMOVE_POINT_ACTION;
  return (1);
}
