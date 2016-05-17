/*
** ini_serializer.c for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Fri Apr 15 15:17:34 2016 Thomas HENON
** Last update Sun Apr 17 13:08:03 2016 John Doe
*/

#include "maps.h"

char		serialize_position(t_point *point,
				   t_bunny_ini *ini_file,
				   int position)
{
  char		*scope_name;

  scope_name = my_strcat("POSITION", my_int_to_str(position));
  bunny_ini_set_field(ini_file, scope_name, "type", 0, "position");
  bunny_ini_set_field(ini_file, scope_name, "index", 0,
		      my_int_to_str(position));
  bunny_ini_set_field(ini_file, scope_name, "is_first", 0,
		      (point->type == PUT_START_POINT_ACTION) ?
		      my_int_to_str(1) : my_int_to_str(0));
  bunny_ini_set_field(ini_file, scope_name, "path", 0, "0");
  bunny_ini_set_field(ini_file, scope_name, "next", 0,
		      (point->type == PUT_MOVE_POINT_ACTON) ?
		      my_int_to_str(1) : my_int_to_str(0));
  bunny_ini_set_field(ini_file, scope_name, "coordinates", 0,
		      my_int_to_str(point->pos_origin.x));
  bunny_ini_set_field(ini_file, scope_name, "coordinates", 1,
		      my_int_to_str(point->pos_origin.y));
  bunny_ini_set_field(ini_file, scope_name, "coordinates", 2, "0");
  return (1);
}

char	carlen_wtf_fix(t_point *point)
{
  if (point->type == PUT_MOVE_POINT_ACTON)
    {
      point->pos_origin.x = 1550;
      point->pos_origin.y = 500;
    }
  else if (point->type == PUT_START_POINT_ACTION)
    {
      point->pos_origin.x = 1550;
      point->pos_origin.y = 650;
    }
}

char		serialize_ini_buttons(t_windows *windows)
{
  t_bunny_ini	*ini_file;
  t_linkedlist	*positions;
  t_point	*point;
  char		*ini_name;
  int		i;

  if (NULL == (ini_file = bunny_new_ini()))
    return (0);
  positions = windows->positions;
  i = 0;
  while (positions)
    {
      point = (t_point*)positions->data;
      carlen_wtf_fix(point);
      serialize_position(point, ini_file, i);
      i++;
      positions = positions->next;
    }
  ini_name = my_strcat(my_strcat("test",
	my_int_to_str(windows->maps->scene_nbr)), ".ini");
  if (!bunny_save_ini(ini_file, ini_name))
    return (my_putstr("Failed to save ini file\n"));
  bunny_delete_ini(ini_file);
  return (1);
}
