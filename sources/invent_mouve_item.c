/*
** invent_mouve_item.c for  in /home/tek/rendu/gfx_tekadventure
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Tue Mar 22 16:32:57 2016 
** Last update Fri Apr 15 15:36:39 2016 carlen
*/

#include "lapin.h"
#include "parallax.h"

t_bunny_pixelarray		**mouse_in_case(t_bunny_pixelarray **item,
						t_bunny_square *sqr,
						int clik,
						int i,
						t_bunny_pixelarray *save_pix)
{
  const bool                    *key;
  t_bunny_position              *pos;

  pos = (t_bunny_position *)bunny_get_mouse_position();
  key = bunny_get_mouse_button();
  if ((pos->x > sqr->pos.x &&
       pos->x < sqr->pos.x + sqr->width) &&
      (pos->y > sqr->pos.y &&
       pos->y < sqr->pos.y + sqr->height))
    {
      if (key[BMB_LEFT] == true && clik == 0)
	{
	  save_pix = item[i];
	  item[i] = NULL;
	  clik = 1;
	}
      if (key[BMB_LEFT] == false && clik == 1)
	{
	  item[i] = save_pix;
	  clik = 0;
	}
    }
  return (item);
}

t_mv_item			is_an_item(t_bunny_position *pos,
					     t_bunny_square *sqr,
					   const bool *key, t_mv_item mv_item)
{
  if ((pos->x > sqr->pos.x && pos->x < sqr->pos.x + sqr->width) &&
      (pos->y > sqr->pos.y && pos->y < sqr->pos.y + sqr->height))
    {
      if (key[BMB_LEFT] == true && mv_item.clik == 0 &&
	  mv_item.item[mv_item.i] != NULL)
	{
	  mv_item.save = mv_item.item[mv_item.i];
	  mv_item.item[mv_item.i] = NULL;
	  mv_item.clik = 1;
	}
      if (key[BMB_LEFT] == false && mv_item.clik == 1 &&
	  mv_item.item[mv_item.i] == NULL)
	{
	  mv_item.item[mv_item.i] = mv_item.save;
	  mv_item.clik = 0;
	}
    }
  return (mv_item);
}

t_bunny_pixelarray              **mouve_item(t_bunny_pixelarray *pix,
					     t_bunny_pixelarray **item,
					     t_list *list,
					     t_bunny_position *pos)
{
  t_bunny_square                *sqr;
  const bool                    *key;
  static t_bunny_pixelarray     *save_pix;
  static int                    clik;
  t_mv_item			mv_item;

  key = bunny_get_mouse_button();
  mv_item.clik = clik;
  mv_item.item = item;
  mv_item.save = save_pix;
  mv_item.i = 0;
  while (list != NULL)
    {
      sqr = (t_bunny_square *)list->data;
      mv_item = is_an_item(pos, sqr, key, mv_item);
      if (key[BMB_LEFT] == true && mv_item.clik == 1)
	blit_pix(pix, mv_item.save, pos);
      list = list->next;
      mv_item.i++;
    }
  clik = mv_item.clik;
  item = mv_item.item;
  save_pix = mv_item.save;
  return (item);
}
