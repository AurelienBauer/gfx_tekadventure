/*
** square_alpha.c for  in /home/tek/rendu/gfx_tekadventure
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Thu Mar 10 17:01:28 2016 
** Last update Fri Apr 15 15:36:19 2016 carlen
*/

#include "lapin.h"
#include "parallax.h"

void                    square_alpha_xp_yp(t_bunny_pixelarray *pix,
					   t_bunny_square *squ,
					   unsigned int color)
{
  t_bunny_position      posi;

  posi.y = squ->pos.y - 1;
  while (++posi.y < (squ->height + squ->pos.y))
    {
      posi.x = squ->pos.x - 1;
      while (++posi.x < (squ->width + squ->pos.x))
        tekpixel_alpha(pix, &posi, color);
    }
}

void                    square_alpha_xp_yn(t_bunny_pixelarray *pix,
					   t_bunny_square *squ,
					   unsigned int color)
{
  t_bunny_position      posi;

  posi.y = squ->pos.y + 1;
  while (--posi.y > (squ->height + squ->pos.y))
    {
      posi.x = squ->pos.x - 1;
      while (++posi.x < (squ->width + squ->pos.x))
        tekpixel_alpha(pix, &posi, color);
    }
}

void                    square_alpha_xn_yp(t_bunny_pixelarray *pix,
					   t_bunny_square *squ,
					   unsigned int color)
{
  t_bunny_position      posi;

  posi.y = squ->pos.y - 1;
  while (++posi.y < (squ->height + squ->pos.y))
    {
      posi.x = squ->pos.x + 1;
      while (--posi.x > (squ->width + squ->pos.x))
        tekpixel_alpha(pix, &posi, color);
    }
}

void                    square_alpha_xn_yn(t_bunny_pixelarray *pix,
					   t_bunny_square *squ,
					   unsigned int color)
{
  t_bunny_position  posi;

  posi.y = squ->pos.y + 1;
  while (--posi.y > (squ->height + squ->pos.y))
    {
      posi.x = squ->pos.x + 1;
      while (--posi.x > (squ->width + squ->pos.x))
        tekpixel_alpha(pix, &posi, color);
    }
}

void                    square_alpha(t_bunny_pixelarray *pix,
				     t_bunny_square *squ,
				     unsigned int color)
{
  if (squ->width >= 0 && squ->height >= 0)
    square_alpha_xp_yp(pix, squ, color);
  if (squ->width >= 0 && squ->height < 0)
    square_alpha_xp_yn(pix, squ, color);
  if (squ->width < 0 && squ->height >= 0)
    square_alpha_xn_yp(pix, squ, color);
  if (squ->width < 0 && squ->height < 0)
    square_alpha_xn_yn(pix, squ, color);
}
