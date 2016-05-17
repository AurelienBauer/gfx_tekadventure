/*
** render_next.c for dfjdnf in /home/carlen/bauer/gfx_tekadventure/house_scene
**
** Made by carlen
** Login   <carlen@epitech.net>
**
** Started on  Fri Apr 15 13:43:23 2016 carlen
** Last update Sun Apr 17 15:35:33 2016 
*/

#include "lapin.h"
#include "parallax.h"

void	display_graph_next(t_game *par)
{
  if (par->to_go->index == 4)
    {
      if (par->cha.pos.x == 1490 && par->cha.pos.y == 439)
	par->is_first = 0;
      move_player_cursor_position(&par->cha, par->to_go->coordinate[0],
				  par->to_go->coordinate[1] - 110 / 2);
    }
  else if (par->to_go == par->graph)
    move_player_cursor_position(&par->cha, par->to_go->coordinate[0],
				par->to_go->coordinate[1] - 110 / 2);
  else if (par->current_node != par->to_go)
    move_player_cursor_position(&par->cha, par->to_go->coordinate[0],
				par->to_go->coordinate[1] - 110 / 2);
  else if (par->cha.pos.x == par->to_go->coordinate[0] &&
	   par->cha.pos.y - 110 / 2 == par->to_go->coordinate[1])
    par->current_node = par->to_go;
}

void				display_lion(t_game *par)
{
  const t_bunny_position	*pos_mouse;
  t_bunny_square		sqr;

  sqr.pos.x = 100;
  sqr.pos.y = 400;
  sqr.width = 350;
  sqr.height = 100;
  pos_mouse = bunny_get_mouse_position();
  calc_parallax(par);
  display_graph_next(par);
  display_graph(par->graph, par->res, par->pic_node);
  display_player(par);
  dialog_box(par->res, par->box, &sqr);
  if (par->is_open == 1)
    display_inventory(par->cha.pos, par->res, par->inv);
  bunny_blit(&(par->win->buffer), &(par->res->clipable), NULL);
  bunny_display(par->win);
  par->pos.x = pos_mouse->x;
}

t_bunny_response		display_next(t_game *game)
{
  static int			i = 0;

  if (!i)
    {
      free_one(game);
      i++;
      if ((game->mgnd1 = bunny_load_pixelarray("mountain_l.png")) == NULL)
	return (EXIT_ON_SUCCESS);
      if ((game->graph = get_graph("test2.ini")) == NULL)
	return (1);
      if (produce_graph(game->graph))
	return (1);
      complete_graph_path(game->graph);
      clean_graph(game->graph, 0);
      game->current_node = game->graph;
      game->to_go = game->current_node;
    }
  display_lion(game);
  return (GO_ON);
}
