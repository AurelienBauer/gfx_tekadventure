/*
** button.h for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps/includes
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Fri Apr 15 15:21:52 2016 Thomas HENON
** Last update Fri Apr 15 15:21:54 2016 thomas
*/

#ifndef __BUTTON_H__
# define __BUTTON_H__

# include "linkedlists.h"

# define BUTTONFLAG_CENTERIZE_X 2
# define BUTTONFLAG_CENTERIZE_Y 4

typedef struct		s_button
{
  t_bunny_pixelarray	*buff_background;
  int			width;
  int			height;
  unsigned int		background_color;
  unsigned int		borders_size;
  unsigned int		borders_color;
  t_tektext		text;
  t_bunny_position	pos;
  int			flags;
  char			(*on_click)(void*);
}			t_button;

void	set_button_defaults_values(t_button *btn);
char	create_button(t_button *btn,
		      t_linkedlist **btns,
		      t_bunny_pixelarray *win_background);

#endif
