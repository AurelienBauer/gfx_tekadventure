/*
** mouse.c<house_scene> for qodfhq in /home/carlen/bauer/gfx_tekadventure/house_scene
**
** Made by carlen
** Login   <carlen@epitech.net>
**
** Started on  Thu Apr 14 17:28:00 2016 carlen
** Last update Sun Apr 17 13:18:51 2016 thomas
*/

#include "lapin.h"
#include "parallax.h"

t_bunny_response	make_menu(t_game *game)
{
  int			cursor_x;
  int			cursor_y;
  t_bunny_position	*pos;

  pos = (t_bunny_position *)bunny_get_mouse_position();
  cursor_x = pos->x;
  cursor_y = pos->y;
  if (cursor_x >= 55 && cursor_x < 55 + 200 &&
      cursor_y >= 141 && cursor_y < 141 + 50)
    {
      game->menu_open = 0;
      bunny_delete_clipable((t_bunny_clipable *)&game->menu);
    }
  else if (cursor_x >= 55 && cursor_x < 55 + 200 &&
	   cursor_y >= 223 && cursor_y < 223 + 50)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	mouse(t_bunny_event_state state,
			      t_bunny_mousebutton key, void *ptr_data)

{
  t_game		*game;
  t_position		*graph;
  t_bunny_position	*pos;

  game = ptr_data;
  graph = game->graph;
  pos = (t_bunny_position *)bunny_get_mouse_position();
  if (state != GO_DOWN && key != BMB_LEFT)
    return (GO_ON);
  game->mouse_pos = *pos;
  if (game->menu_open)
    return (make_menu(game));
  while (graph != NULL)
    {
      if (cursor_aabb_collision(pos->x, pos->y, graph->coordinate[0],
				graph->coordinate[1]))
	{
	  game->to_go = graph;
	  return (GO_ON);
	}
      graph = graph->next;
    }
  return (GO_ON);
}
