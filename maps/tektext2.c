/*
** tektext2.c for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Sun Apr 17 13:22:11 2016 Thomas HENON
** Last update Sun Apr 17 13:22:39 2016 thomas
*/

#include "maps.h"

void	set_tektext_defaults_values(t_tektext *_tektext)
{
  _tektext->buff_background = _tektext->buff_background;
  _tektext->color = BLACK;
  _tektext->pos.x = 0;
  _tektext->pos.y = 0;
  _tektext->margin[0] = 3;
  _tektext->margin[1] = 1;
  _tektext->text = "Hello world";
  _tektext->scale[0] = 1;
  _tektext->scale[1] = 1;
  _tektext->flags = TEKTEXT_X_CENTER | TEKTEXT_Y_CENTER;
}
