/*
** render.c for tekafogujh in /home/carlen/bauer/gfx_tekadventure/house_scene
**
** Made by carlen
** Login   <carlen@epitech.net>
**
** Started on  Thu Apr 14 16:19:24 2016 carlen
** Last update Sun Apr 17 13:25:11 2016 thomas
*/

#include <stdlib.h>
#include "lapin.h"
#include "parallax.h"

void                    my_blit_player(t_bunny_pixelarray *dest,
				       t_bunny_pixelarray *ori,
				       t_bunny_position *pos)
{
  t_color               *array_ori;
  unsigned int		color;
  t_bunny_position      pos_ori;
  t_bunny_position	pos_dest;

  array_ori = ori->pixels;
  pos_ori.y = 0;
  while (pos_ori.y < ori->clipable.clip_height)
    {
      pos_ori.x = 0;
      while (pos_ori.x < ori->clipable.clip_width)
        {
	  pos_dest.x = pos->x + pos_ori.x;
	  pos_dest.y = pos->y + pos_ori.y;
	  color = array_ori[pos_ori.x + pos_ori.y *
			    ori->clipable.clip_width].full;
	  if (color != (unsigned int)BLACK)
	    tekpixel_alpha(dest, &pos_dest, color);
          pos_ori.x = pos_ori.x + 1;
        }
      pos_ori.y = pos_ori.y + 1;
    }
}

void	display_player(t_game *game)
{
  fill_color(game->cha.character, BLACK);
  tekchar(game->cha.character, &game->cha.step,
	  game->cha.sprite);
  stretch(game->cha.character, game->cha.character);
  my_blit_player(game->res, game->cha.character, &game->cha.pos);
}

void				calc_parallax(t_game *par)
{
  t_bunny_position		ori;
  const t_bunny_position	*pos_mouse;
  float				coeff3;
  float				coeff1;

  ori.x = 0;
  ori.y = 0;
  pos_mouse = bunny_get_mouse_position();
  coeff3 = 1 - (float)par->bgnd->clipable.clip_width /
    (float)par->mgnd3->clipable.clip_width;
  coeff1 = 1 - (float)par->bgnd->clipable.clip_width /
    (float)par->mgnd1->clipable.clip_width;
  par->pos_mgnd3.x = ((par->bgnd->clipable.clip_width -
		       par->mgnd3->clipable.clip_width) / 2
		      - (coeff3 / 4 * (pos_mouse->x -
				       par->bgnd->clipable.clip_width / 2)));
  par->pos_mgnd3.y = 0;
  par->pos_mgnd1.x = ((par->bgnd->clipable.clip_width -
		       par->mgnd1->clipable.clip_width) / 2
		      - (coeff1 / 2 * (pos_mouse->x -
				       par->bgnd->clipable.clip_width / 2)));
  par->pos_mgnd1.y = 0;
  my_blit(par->res, par->bgnd, &ori);
  my_blit(par->res, par->mgnd3, &par->pos_mgnd3);
  my_blit(par->res, par->mgnd1, &par->pos_mgnd1);
}

t_bunny_response		on_refresh(void *data)
{
  t_parallax			*par;

  par = (t_parallax *)data;
  if (par->menu_open)
    {
      bunny_blit(&(par->win->buffer), &(par->menu->clipable), NULL);
      bunny_display(par->win);
      return (GO_ON);
    }
  else if (par->is_first)
    display_game(par);
  else
    return (display_next(par));
  return (GO_ON);
}

void				display_game(t_game *par)
{
  calc_parallax(par);
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
  display_graph(par->graph, par->res, par->pic_node);
  display_player(par);
  if (par->is_open == 1)
    display_inventory(par->cha.pos, par->res, par->inv);
  bunny_blit(&(par->win->buffer), &(par->res->clipable), NULL);
  bunny_display(par->win);
  par->pos.x = bunny_get_mouse_position()->x;
}
