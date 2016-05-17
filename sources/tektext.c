/*
** teklettre.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Sat Feb 27 08:51:29 2016 
** Last update Sun Apr 17 15:37:14 2016 
*/

#include "parallax.h"

unsigned int		get_pixelss(t_bunny_pixelarray *buffer,
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

void                    my_blit_text(t_bunny_pixelarray *background,
                                     t_bunny_pixelarray *buffer,
                                     t_bunny_position *pos)
{
  t_bunny_position      pos_rela;
  unsigned int          color;

  pos_rela.y = pos->y;
  while (pos_rela.y < 20 + pos->y)
    {
      pos_rela.x = pos->x;
      while (pos_rela.x < 9 + pos->x)
        {
          color = get_pixelss(buffer, pos_rela.x +
			      buffer->clipable.clip_x_position - pos->x,
			      pos_rela.y + buffer->clipable.clip_y_position
			      - pos->y);
          if (color != 0)
            tekpixel_alpha(background, &pos_rela, color);
          pos_rela.x++;
        }
      pos_rela.y++;
    }
}

void			teklettre(t_bunny_pixelarray *pix,
				  t_bunny_pixelarray *img,
				  t_bunny_position *pos,
				  char lettre)
{
  img->clipable.clip_x_position = 9 * (lettre - 'a') + 872;
  my_blit_text(pix, img, pos);
}

void			tektext(t_bunny_pixelarray *pix,
				t_bunny_pixelarray *img,
				t_bunny_position *pos,
				char *str)
{
  t_bunny_position	rela_pos;

  rela_pos.x = pos->x;
  rela_pos.y = pos->y;
  while (*str)
    {
      if (*str == '\n')
	{
	  rela_pos.y += 22;
	  rela_pos.x = pos->x;
	  str++;
	}
      else
	{
	  teklettre(pix, img, &rela_pos, *str);
	  rela_pos.x += 12;
	  str++;
	}
    }
}
