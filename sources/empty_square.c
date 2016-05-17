/*
** empty_square.c for  in /home/tek/rendu/gfx_tekadventure
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Thu Mar 10 09:47:09 2016 
** Last update Fri Apr 15 15:35:32 2016 carlen
*/

#include "lapin.h"
#include "parallax.h"

void                            empty_square(t_bunny_pixelarray *pix,
                                             t_bunny_square squar,
                                             unsigned int color,
                                             int size)
{
  t_bunny_position              pos2;
  t_bunny_position              pos3;
  t_bunny_position              pos4;

  pos2.x = squar.pos.x + squar.width;
  pos2.y = squar.pos.y;
  pos3.x = squar.pos.x + squar.width;
  pos3.y = squar.pos.y + squar.height;
  pos4.x = squar.pos.x;
  pos4.y = squar.pos.y + squar.height;
  squar.width = size;
  squar.height = size;
  line(pix, squar, pos2, color);
  line(pix, squar, pos4, color);
  squar.pos = pos2;
  line(pix, squar, pos3, color);
  squar.pos = pos4;
  line(pix, squar, pos3, color);
}
