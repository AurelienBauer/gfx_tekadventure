/*
** blit_tektext.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb 27 08:53:16 2016 
** Last update Fri Apr 15 15:26:37 2016 carlen
*/

#include "lapin.h"
#include "parallax.h"

unsigned int    get_pixels(t_bunny_pixelarray *buffer,
                          int x,
                          int y)
{
  unsigned int  color;
  unsigned int  i;

  i = buffer->clipable.clip_width * y + x;
  if (x >= 0 && x <= buffer->clipable.clip_width &&
      y >= 0 && y <= buffer->clipable.clip_height)
    return (color = (((t_color*)buffer->pixels)[i].full));
  return (color = 0);
}

void                    blit_pix(t_bunny_pixelarray *destination,
                                 t_bunny_pixelarray *origin,
				 t_bunny_position *pos)
{
  t_bunny_position      pos_rela;
  unsigned int          color;

  pos_rela.y = pos->y;
  while (pos_rela.y < origin->clipable.clip_height + pos->y)
    {
      pos_rela.x = pos->x;
      while (pos_rela.x < origin->clipable.clip_width + pos->x)
        {
          color = get_pixels(origin, pos_rela.x +
                            origin->clipable.clip_x_position - pos->x,
                            pos_rela.y + origin->clipable.clip_y_position
                            - pos->y);
          if (color != 0)
            tekpixel_alpha(destination, &pos_rela, color);
          pos_rela.x++;
        }
      pos_rela.y++;
    }
}
