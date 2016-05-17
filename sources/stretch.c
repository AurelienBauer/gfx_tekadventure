/*
** stretch.c for stretcher in /home/antoine/EPITECH/skilltest/stretcher_2020
**
** Made by Antoine
** Login   <antoine@epitech.net>
**
** Started on  Tue Dec 15 13:03:48 2015 Antoine
** Last update Sun Apr 17 13:17:20 2016 thomas
*/

#include <stdio.h>
#include "lapin.h"

void				stretch_loop(t_bunny_pixelarray *pix,
					     t_bunny_pixelarray *ori,
					     double ratio_x, double ratio_y)
{
  t_color			*array_pix;
  t_color			*array_ori;
  double			pix_index;
  double			ori_index;
  t_bunny_position		pos_ori;
  t_bunny_position		pos;

  array_pix = pix->pixels;
  array_ori = ori->pixels;
  pos.y = 0;
  while (pos.y < (double)pix->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < (double)pix->clipable.clip_width)
	{
	  pos_ori.x = ((int)(ratio_x * pos.x));
	  pos_ori.y = ((int)(ratio_y * pos.y));
	  pix_index = pos.x + pos.y * (double)pix->clipable.clip_width;
	  ori_index = pos_ori.x + pos_ori.y * ori->clipable.clip_width;
	  array_pix[(int)pix_index].full = array_ori[(int)ori_index].full;
	  pos.x = pos.x + 1;
	}
      pos.y = pos.y + 1;
    }
}

void		stretch(t_bunny_pixelarray *pix,
			t_bunny_pixelarray *ori)
{
  double	ratio_x;
  double	ratio_y;

  ratio_x = (double)(ori->clipable.clip_width) /
      (double)(pix->clipable.clip_width);
  ratio_y = (double)(ori->clipable.clip_height) /
      (double)(pix->clipable.clip_height);
  stretch_loop(pix, ori, ratio_x, ratio_y);
}
