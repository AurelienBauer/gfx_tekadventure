/*
** tekpixel_alpha.c for tekpixel_alpha in /home/antoine
**
** Made by Antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 18 13:46:30 2016 Antoine
** Last update Thu Apr 14 22:15:09 2016 carlen
*/

#include "lapin.h"
#include "parallax.h"

t_color		get_res_col(t_color *col,
			    t_color *prec_col,
			    float ratio_alpha)
{
  t_color	res_col;

  res_col.argb[ALPHA_CMP] = 255;
  res_col.argb[BLUE_CMP] = prec_col->argb[BLUE_CMP] * (100 - ratio_alpha) / 100
    + col->argb[BLUE_CMP] * ratio_alpha / 100;
  res_col.argb[GREEN_CMP] = prec_col->argb[GREEN_CMP] * (100 - ratio_alpha) / 100
    + col->argb[GREEN_CMP] * ratio_alpha / 100;
  res_col.argb[RED_CMP] = prec_col->argb[RED_CMP] * (100 - ratio_alpha) / 100
    + col->argb[RED_CMP] * ratio_alpha / 100;
  return (res_col);
}

void		tekpixel_alpha(t_bunny_pixelarray *pix,
			       t_bunny_position *pos,
			       unsigned int color)
{
  int		pos_pix;
  t_color	col;
  t_color	prec_col;
  t_color	res_col;
  float		ratio_alpha;
  t_color	*pixel_tab;

  col.full = color;
  pixel_tab = pix->pixels;
  ratio_alpha = col.argb[ALPHA_CMP] * 100 / 255;
  if (pos->y >= 0 && pos->y < pix->clipable.clip_height
      && pos->x >= 0 && pos->x < pix->clipable.clip_width)
    {
      pos_pix = (pos->x + pos->y * pix->clipable.clip_width);
      prec_col = pixel_tab[pos_pix];
      res_col = get_res_col(&col, &prec_col, ratio_alpha);
      pixel_tab[pos_pix] = res_col;
    }
}
