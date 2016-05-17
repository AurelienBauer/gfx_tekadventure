/*
** scaling.c for  in /home/henon_t/Documents/text_foot_2020
**
** Made by Thomas Henon
** Login   <henon_t@epitech.net>
**
** Started on  Thu Mar 10 15:27:30 2016 Thomas Henon
** Last update Tue Apr 12 17:25:59 2016 John Doe
*/

#include "maps.h"

void	resize_buffer_loops(t_bunny_pixelarray *buffer, t_resizer *rsz)
{
  rsz->i = 0;
  while (rsz->i < rsz->height)
    {
      rsz->j = 0;
      while (rsz->j < rsz->width)
	{
	  rsz->px = rsz->j * rsz->x_ratio;
	  rsz->py = rsz->i * rsz->y_ratio;
	  ((t_color*)rsz->new_pixelarray->pixels)[rsz->i *
	  rsz->width + rsz->j].full = ((t_color*)buffer->pixels)[(rsz->py *
				       buffer->clipable.clip_width) +
	  rsz->px].full;
	  rsz->j++;
	}
      rsz->i++;
    }
}

t_bunny_pixelarray	*resize_buffer(t_bunny_pixelarray *buffer)
{
  t_resizer		rsz;

  rsz.width = buffer->clipable.clip_width * buffer->clipable.scale.x;
  rsz.height = buffer->clipable.clip_height * buffer->clipable.scale.y;
  rsz.x_ratio = (double)buffer->clipable.clip_width / (double)rsz.width;
  rsz.y_ratio = (double)buffer->clipable.clip_height / (double)rsz.height;
  if (NULL == (rsz.new_pixelarray = bunny_new_pixelarray(rsz.width,
							 rsz.height)))
    return (NULL);
  resize_buffer_loops(buffer, &rsz);
  return (rsz.new_pixelarray);
}
