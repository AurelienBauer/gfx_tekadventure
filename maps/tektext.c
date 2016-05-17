/*
** tektext.c for gfx_tekgui in /home/thomas/Documents/epitech/gfx_tekgui/tcore
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Tue Feb 02 09:16:04 2016 Thomas HENON
** Last update Sun Apr 17 13:22:42 2016 thomas
*/

# include "maps.h"

void		blit_tekchar(t_tektext *_tektext,
			     t_tekchar *_tekchar,
			     t_bunny_pixelarray *font)
{
  unsigned int	x;
  unsigned int	y;
  unsigned int	color;

  y = 0;
  while (y < _tekchar->height)
    {
      x = 0;
      while (x < _tekchar->width)
	{
	  color = get_pixel(font, x + font->clipable.clip_x_position,
			    y + font->clipable.clip_y_position);
	  if (color != 0)
	    set_pixel(_tektext->buff_background, _tektext->color,
		      x + _tekchar->pos.x, y + _tekchar->pos.y);
	    x++;
	}
      y++;
    }
}

char			tektext_load_font(t_tektext *_tektext,
					  t_bunny_pixelarray **font)
{
  t_bunny_pixelarray	*tmp;

  *font = bunny_load_pixelarray(TEKTEXT_FONT_PATH);
  if (*font == NULL)
    return (0);
  else
    {
      (*font)->clipable.scale.x = _tektext->scale[0];
      (*font)->clipable.scale.y = _tektext->scale[1];
      tmp = *font;
      *font = resize_buffer(*font);
      bunny_delete_clipable(&tmp->clipable);
    }
  _tektext->font = *font;
  return (1);
}

void	tektext_set_position(t_tektext *_tektext, t_tekchar *_tekchar)
{
  if ((_tekchar->pos.x + _tekchar->height) >
      (_tektext->buff_background->clipable.clip_width - _tekchar->width +
       _tektext->margin[0]))
    {
      _tekchar->pos.x = _tektext->pos.x;
      _tekchar->pos.y += _tekchar->height + _tektext->margin[1];
    }
  else
    _tekchar->pos.x = _tekchar->pos.x + _tekchar->width + _tektext->margin[0];
}

char	tektext_center_position(t_tektext *tektext)
{
  int	win_dims[2];
  int	char_dims[2];
  int	margin_center;
  int	text_center;
  int	text_len;

  if (!(tektext->flags & TEKTEXT_X_CENTER))
    return (0);
  win_dims[0] = tektext->buff_background->clipable.clip_width;
  win_dims[1] = tektext->buff_background->clipable.clip_height;
  char_dims[0] = tektext->font->clipable.clip_width / 128;
  char_dims[1] = tektext->font->clipable.clip_height;
  text_len = my_strlen(tektext->text);
  margin_center = (text_len * tektext->margin[0]) / 2;
  text_center = (text_len * char_dims[0]) / 2;
  tektext->pos.x = (win_dims[0] / 2) - text_center - margin_center;
  tektext->pos.y = (win_dims[1] / 2);
}

char				tektext(t_tektext *_tektext)
{
  t_bunny_pixelarray		*font;
  t_tekchar			_tekchar;
  int				char_i;

  if (!tektext_load_font(_tektext, &font))
    return (0);
  char_i = 0;
  tektext_center_position(_tektext);
  _tekchar.pos = _tektext->pos;
  while (_tektext->text[char_i])
    {
      _tekchar.c = _tektext->text[char_i];
      _tekchar.width = font->clipable.clip_width / 128;
      _tekchar.height = font->clipable.clip_height;
      font->clipable.clip_x_position = _tekchar.c * _tekchar.width;
      font->clipable.clip_y_position = 0;
      blit_tekchar(_tektext, &_tekchar, font);
      tektext_set_position(_tektext, &_tekchar);
      char_i++;
    }
  bunny_delete_clipable(&font->clipable);
  return (1);
}
