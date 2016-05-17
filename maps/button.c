/*
** button.c for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Fri Apr 15 15:17:19 2016 Thomas HENON
** Last update Fri Apr 15 15:18:27 2016 thomas
*/

#include "maps.h"

void	set_button_defaults_values(t_button *btn)
{
  btn->width = 200;
  btn->height = 35;
  btn->background_color = WHITE;
  set_tektext_defaults_values(&btn->text);
  btn->pos.x = 0;
  btn->pos.y = 0;
  btn->borders_size = 2;
  btn->borders_color = BLACK;
  btn->flags = BUTTONFLAG_CENTERIZE_X;
}

void	draw_borders(t_button *btn)
{
  int	x;
  int	y;

  y = 0;
  while (y < btn->height)
    {
      x = 0;
      while (x < btn->width)
	{
	  if (x <= btn->borders_size ||
	      x >= (btn->width - btn->borders_size)
	      || y <= btn->borders_size ||
	      y >= (btn->height - btn->borders_size))
	    {
	      set_pixel(btn->buff_background, btn->borders_color,
			x, y);
	    }
	  x++;
	}
      y++;
    }
}

void	centerize_btn(t_button *btn, t_bunny_pixelarray *parent_background)
{
  if (btn->flags & BUTTONFLAG_CENTERIZE_X)
    btn->pos.x = parent_background->clipable.clip_width / 2 - btn->width / 2;
  if (btn->flags & BUTTONFLAG_CENTERIZE_Y)
    btn->pos.y = parent_background->clipable.clip_height / 2 - btn->height / 2;
}

char	create_button(t_button *btn,
		      t_linkedlist **btns,
		      t_bunny_pixelarray *parent_background)
{
  if (NULL == (btn->buff_background = bunny_new_pixelarray(btn->width,
							   btn->height)))
    return (0);
  fill_buffer(btn->buff_background, btn->background_color);
  draw_borders(btn);
  centerize_btn(btn, parent_background);
  btn->text.buff_background = btn->buff_background;
  tektext(&btn->text);
  blit_pixelarrays(parent_background, btn->buff_background, &btn->pos);
  push_back(btns, (void*)btn);
  return (1);
}
