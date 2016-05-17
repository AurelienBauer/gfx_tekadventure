/*
** tekchar.c for tekadventure in /home/carlen/gfx_tekadventure
** 
** Made by carlen
** Login   <carlen@epitech.net>
** 
** Started on  Wed Mar  9 14:12:18 2016 carlen
** Last update Thu Apr 14 22:25:35 2016 carlen
*/

#include "lapin.h"
#include "parallax.h"

void			fill_color(t_bunny_pixelarray *ar,
				   unsigned int color)
{
  t_bunny_position	pos;

  pos.x = 0;
  while (pos.x < ar->clipable.clip_width)
    {
      pos.y = -1;
      while (++pos.y < ar->clipable.clip_height)
	tekpixel_alpha(ar, &pos, color);
      pos.x++;
    }
}

t_color			get_pixel(t_bunny_pixelarray *pix,
				  t_bunny_position *pos)
{
  t_color		color;
  t_bunny_clipable      *clip;
  t_color               *array;

  clip = &(pix->clipable);
  array = pix->pixels;
  color = array[pos->x + pos->y * clip->clip_width];
  return (color);
}

void			tekchar(t_bunny_pixelarray *out,
				t_bunny_position *step,
				t_bunny_pixelarray *sprite)
{
  t_bunny_position	pos;
  t_bunny_position	pos_out;
  t_color		color;

  pos.y = step->y * 157;
  pos_out.y = 0;
  while (pos_out.y < 157)
    {
      pos.x = step->x * 95;
      pos_out.x = 0;
      while (pos_out.x < 95)
	{
	  color = get_pixel(sprite, &pos);
	  tekpixel_alpha(out, &pos_out, color.full);
	  pos.x = pos.x + 1;
	  pos_out.x = pos_out.x + 1;
	}
      pos.y = pos.y + 1;
      pos_out.y = pos_out.y + 1;
    }
}
