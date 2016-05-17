/*
** toolbar_buttons.c for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Fri Apr 15 15:18:00 2016 Thomas HENON
** Last update Sun Apr 17 11:42:40 2016 John Doe
*/

#include "maps.h"

char				new_toolbar_btn(t_windows *windows,
						char *text,
						char (*callback)(void*))
{
  t_button			*btn;
  static t_bunny_position	cur_pos;

  if (cur_pos.y == 0)
    cur_pos.y = 5;
  if (NULL == (btn = bunny_malloc(sizeof(t_button))))
    return (0);
  set_button_defaults_values(btn);
  btn->background_color = BLACK;
  btn->text.color = RED;
  btn->borders_color = WHITE;
  btn->width = windows->buff_background[0]->clipable.clip_width - 20;
  btn->pos.x = cur_pos.x;
  btn->pos.y = cur_pos.y;
  btn->text.text = text;
  btn->on_click = callback;
  create_button(btn, &windows->buttons, windows->buff_background[0]);
  cur_pos.y += 40;
}

void		free_btns(t_windows *windows)
{
  t_linkedlist	*buttons;
  t_button	*button;

  buttons = windows->buttons;
  while (buttons)
    {
      button = (t_button*)buttons->data;
      bunny_free(button);
      buttons = buttons->next;
    }
  free_list(windows->buttons);
  windows->buttons = NULL;
}

char			init_toolbar_btn(t_windows *windows)
{
  windows->buttons = NULL;
  new_toolbar_btn(windows, "Charger scene 1", on_load_maps1_click);
  new_toolbar_btn(windows, "Charger scene 2", on_load_maps2_click);
  new_toolbar_btn(windows, "Enregistrer maps", on_save_maps_click);
  new_toolbar_btn(windows, "Point de depart", on_place_start_point_click);
  new_toolbar_btn(windows, "Point de changement maps",
		  on_next_maps_point_click);
  new_toolbar_btn(windows, "Point de deplacement", on_place_point_click);
  new_toolbar_btn(windows, "Supprimer un point", on_delete_point_click);
}
