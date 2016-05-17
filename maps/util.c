/*
** util.c for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Fri Apr 15 15:18:07 2016 Thomas HENON
** Last update Fri Apr 15 15:18:08 2016 thomas
*/

#include "maps.h"

char	alert_box(char *str, t_windows *windows, char type)
{
  t_tektext	_tektext;

  if (NULL == (windows->buffer[2] = bunny_start_style(600, 80,
				     TITLEBAR | CLOSE_BUTTON, "AlertBox")))
    return (0);
  if (NULL == (windows->buff_background[2] = bunny_new_pixelarray(600, 80)))
    return (0);
  fill_buffer(windows->buff_background[2], BLACK);
  _tektext.buff_background = windows->buff_background[2];
  if (type == SUCCESS_ALERT_TYPE)
    _tektext.color = GREEN;
  else if (type == ERROR_ALERT_TYPE)
    _tektext.color = RED;
  else if (type == SUCCESS_ALERT_TYPE)
    _tektext.color = WHITE;
  _tektext.pos.x = 10;
  _tektext.pos.y = 10;
  _tektext.margin[0] = 5;
  _tektext.margin[1] = 5;
  _tektext.text = str;
  _tektext.scale[0] = 2;
  _tektext.scale[1] = 2;
  _tektext.flags = TEKTEXT_X_CENTER | TEKTEXT_Y_CENTER;
  tektext(&_tektext);
}

t_bunny_pixelarray	*cpy_pixelarray(t_bunny_pixelarray *src)
{
  int			x;
  int			y;
  int			i;
  t_bunny_pixelarray	*dest;

  if (NULL == (dest = bunny_new_pixelarray(src->clipable.clip_width,
					   src->clipable.clip_height)))
    return (NULL);
  y = 0;
  while (y < src->clipable.clip_height)
    {
      x = 0;
      while (x < src->clipable.clip_width)
	{
	  i = y * src->clipable.clip_width + x;
	  ((t_color*)dest->pixels)[i].full = ((t_color*)src->pixels)[i].full;
	  x++;
	}
      y++;
    }
  return (dest);
}
