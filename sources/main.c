/*
** parallax.c for parallax in /home/antoine/Desktop/parallax
**
** Made by Antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Mar  6 04:58:50 2016 Antoine
** Last update Sun Apr 17 17:42:02 2016 carlen
*/

#include <stdlib.h>
#include "lapin.h"
#include "parallax.h"

t_bunny_response	keyboard(t_bunny_event_state state,
				 t_bunny_keysym key, void *ptr_data)
{
  t_game		*game;

  game = (t_game *)ptr_data;
  game->mouse_pos.x++;
  game->mouse_pos.x--;
  if (state == GO_DOWN)
    {
      if (key == BKS_ESCAPE)
	return (EXIT_ON_SUCCESS);
      if (key == BKS_I && !game->is_open)
	game->is_open = 1;
      else if (key == BKS_I && game->is_open == 1)
	game->is_open = 0;
    }
  return (GO_ON);
}

int	game(t_game *par)
{
  t_bunny_pixelarray	*pic;

  bunny_set_maximum_ram(52428800);
  par->pos.x = 0;
  par->pos.y = 0;
  par->pos_fgnd.x = 0;
  par->pos_fgnd.y = 0;
  if ((par->graph = get_graph(DEFAULT_INI_POS)) == NULL)
    return (1);
  if (produce_graph(par->graph))
    return (1);
  complete_graph_path(par->graph);
  clean_graph(par->graph, 0);
  if ((pic = bunny_load_pixelarray(PIC_POS)) == NULL)
    return (1);
  if ((par->pic_node = bunny_new_pixelarray(40, 40)) == NULL)
    return (1);
  par->current_node = par->graph;
  par->to_go = par->current_node;
  stretch(par->pic_node, pic);
  bunny_delete_clipable((t_bunny_clipable *)&pic->clipable);
  par->menu_open = 1;
  par->is_open = 0;
  par->is_first = 1;
  return (0);
}

int	load_game(t_game *par)
{
  if ((par->mgnd1 = bunny_load_pixelarray("mountains3.png")) == NULL)
    return (1);
  if ((par->mgnd3 = bunny_load_pixelarray("mountains1.png")) == NULL)
    return (1);
  if ((par->bgnd = bunny_load_pixelarray("universe1.png")) == NULL)
    return (1);
  if ((par->res = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  if ((par->menu = bunny_load_pixelarray("menu.png")) == NULL)
    return (1);
  if ((par->cha.sprite = bunny_load_pixelarray("walker.png")) == NULL)
    return (1);
  if ((par->cha.character = bunny_new_pixelarray(110, 160)) == NULL)
    return (1);
  par->cha.step.x = 0;
  par->cha.step.y = 0;
  par->cha.pos.x = par->current_node->coordinate[0];
  par->cha.pos.y = par->current_node->coordinate[1] - 160 / 2;
  if ((par->box.font = bunny_load_pixelarray("my_font.png")) == NULL)
    return (1);
  if ((par->box.texture = bunny_load_pixelarray("texture_box.jpg")) == NULL)
    return (1);
  par->box.str = "Bonjour aventurier, tu viens\nde terminer ton voyage\n"
    "felicitation !!!!";
  return (0);
}

int	load_inventory(t_game *game)
{
  if ((game->inv.case_ivt =
       bunny_malloc(sizeof(t_bunny_pixelarray *) * 15)) == NULL)
    return (1);
  if ((game->inv.case_ivt[14] =
       bunny_load_pixelarray("Iron-Sword-icon.png"))
      == NULL)
    return (1);
  if ((game->inv.case_ivt[1] =
       bunny_load_pixelarray("Shield.png"))
      == NULL)
    return (1);
  if ((game->inv.move =
       bunny_load_pixelarray("move.png"))
      == NULL)
    return (1);
  if ((game->inv.texture =
       bunny_load_pixelarray("texture.jpg"))
      == NULL)
    return (1);
  return (0);
}

int			main(void)
{
  t_parallax		par;
  t_bunny_pixelarray	*tmp;

  if (game(&par))
    return (1);
  if (load_inventory(&par))
    return (1);
  tmp = bunny_load_pixelarray(LOADING);
  if ((par.win = bunny_start(WIDTH, HEIGHT, 0, TITLE)) == NULL)
    return (1);
  bunny_blit(&(par.win->buffer), &(tmp->clipable), NULL);
  bunny_display(par.win);
  if (load_game(&par))
    return (1);
  bunny_delete_clipable(&tmp->clipable);
  bunny_set_loop_main_function(&on_refresh);
  bunny_set_click_response(mouse);
  bunny_set_key_response(keyboard);
  bunny_loop(par.win, FPS, (void *)&par);
  bunny_stop(par.win);
  return (0);
}
