/*
** bases.c for gfx_tekgui in /home/thomas/Documents/epitech/gfx_tekgui
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Tue Feb 02 09:35:34 2016 Thomas HENON
** Last update Fri Apr 15 15:18:24 2016 thomas
*/

#include "maps.h"

void		fill_buffer(t_bunny_pixelarray *buffer,
			    unsigned color)
{
  unsigned int	i;
  unsigned int	dim;

  i = 0;
  dim = buffer->clipable.clip_width * buffer->clipable.clip_height;
  while (i < dim)
    ((t_color*)buffer->pixels)[i++].full = color;
}

void		set_pixel(t_bunny_pixelarray *buffer,
			  unsigned int color,
			  int x,
			  int y)
{
  unsigned int	index;

  index = buffer->clipable.clip_width * y + x;
  if (x >= 0 && x <= buffer->clipable.clip_width &&
      y >= 0 && y <= buffer->clipable.clip_height)
    ((t_color*)buffer->pixels)[index].full = color;
}

unsigned int	get_pixel(t_bunny_pixelarray *buffer,
			  int x,
			  int y)
{
  unsigned int	color;
  unsigned int	i;

  i = buffer->clipable.clip_width * y + x;
  if (x >= 0 && x <= buffer->clipable.clip_width &&
      y >= 0 && y <= buffer->clipable.clip_height)
    color = (((t_color*)buffer->pixels)[i].full);
  else
    color = 0;
  return (color);
}

void		blit_pixelarrays(t_bunny_pixelarray *background,
				 t_bunny_pixelarray *buffer,
				 t_bunny_position *pos)
{
  unsigned int	x;
  unsigned int	y;

  y = (unsigned int)pos->y;
  while (y < (((unsigned int)pos->y) + buffer->clipable.clip_height))
    {
      x = (unsigned int)pos->x;
      while (x < (((unsigned int)pos->x) + buffer->clipable.clip_width))
	{
	  if (x < (unsigned int)background->clipable.clip_width &&
	      y < (unsigned int)background->clipable.clip_height)
	    {
	      set_pixel(background, get_pixel(buffer,
	      x-pos->x + buffer->clipable.clip_x_position,
	      y-pos->y + buffer->clipable.clip_y_position), x, y);
	    }
	  x++;
	}
      y++;
    }
}

void	 	blit_pixelarrays2(t_bunny_pixelarray *background,
				  t_bunny_pixelarray *buffer,
				  t_bunny_position *pos,
				  t_dim *dim)
{
  unsigned int	x;
  unsigned int	y;

  y = 0;
  while (y < dim->height)
    {
      x = 0;
      while (x < dim->width)
	{
	  set_pixel(background,
	    get_pixel(buffer, x + buffer->clipable.clip_x_position,
	    y + buffer->clipable.clip_y_position),
	    x + pos->x,
	    y + pos->y);
	  x++;
	}
      y++;
    }
}
