/*
** tekgui_display2.c for tekgui in /home/antoine/EPITECH/tekgui/gfx_tekgui
**
** Made by Antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 14:26:30 2016 Antoine
** Last update Thu Apr 14 16:15:14 2016 carlen
*/

#include <stdlib.h>
#include "lapin.h"
#include "parallax.h"

void                    my_blit(t_bunny_pixelarray *dest,
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
          tekpixel_alpha(dest, &pos_dest, color);
          pos_ori.x = pos_ori.x + 1;
        }
      pos_ori.y = pos_ori.y + 1;
    }
}
