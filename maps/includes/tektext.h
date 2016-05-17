/*
** tektext.h for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps/includes
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Fri Apr 15 15:22:04 2016 Thomas HENON
** Last update Fri Apr 15 15:22:06 2016 thomas
*/

#ifndef __TEKTEXT_H__
# define __TEKTEXT_H__

# include <lapin.h>

# define TEKTEXT_FONT_PATH "font.png"

# define TEKTEXT_X_CENTER 2
# define TEKTEXT_Y_CENTER 4
# define TEKTEXT_ANIM_FADED 8

typedef struct		s_tektext
{
  t_bunny_pixelarray 	*buff_background;
  t_bunny_pixelarray	*font;
  t_bunny_position	pos;
  unsigned int		color;
  char			*text;
  int			margin[2];
  int			scale[2];
  int			flags;
}			t_tektext;

typedef struct		s_resizer
{
  int			width;
  int			height;
  int			i;
  int			j;
  int			px;
  int			py;
  double		x_ratio;
  double		y_ratio;
  t_bunny_pixelarray	*new_pixelarray;
}			t_resizer;

typedef struct		s_tekchar
{
  char			c;
  t_bunny_position	pos;
  int			width;
  int			height;
}			t_tekchar;

void		blit_tekchar(t_tektext *_tektext,
			     t_tekchar *_tekchar,
			     t_bunny_pixelarray *font);
char	tektext_load_font(t_tektext *_tektext, t_bunny_pixelarray **font);
void	tektext_set_position(t_tektext *_tektext, t_tekchar *_tekchar);
char	tektext_center_position(t_tektext *tektext);
void	set_tektext_defaults_values(t_tektext *_tektext);
char	tektext(t_tektext *_tektext);

#endif
