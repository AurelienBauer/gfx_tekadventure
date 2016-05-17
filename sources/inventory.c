/*
** inventory.c for  in /home/tek/rendu/gfx_tekadventure
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Wed Mar  9 16:43:38 2016 
** Last update Sun Apr 17 16:59:39 2016 carlen
*/

#include "lapin.h"
#include "parallax.h"

void				init_inventory(t_bunny_pixelarray *pix,
					       t_bunny_position pos,
					       t_inventaire ivt)
{
  blit_pix(pix, ivt.texture, &pos);
  pos.x = pos.x - 5;
  pos.y = pos.y + INVE_HEIGHT - 5;
  blit_pix(pix, ivt.move, &pos);
}

t_list				*init_case(t_bunny_pixelarray *pix,
					   t_bunny_position pos,
					   t_list *list,
					   int i)
{
  int				j;
  t_bunny_square		*sqr;

  if ((sqr = bunny_malloc(sizeof(t_bunny_square) * 17)) == NULL)
    return (NULL);
  sqr->pos.x = pos.x + 37;
  sqr->pos.y = pos.y + 17;
  while (++i < 3)
    {
      j = -1;
      while (++j < 5)
	{
	  sqr[i * 5 + j].width = 57;
	  sqr[i * 5 + j].height = 57;
	  empty_square(pix, sqr[i * 5 + j] , WHITE, 3);
	  list = addnew_elem_inlist(list, (void *)&sqr[i * 5 + j]);
	  sqr[i * 5 + j + 1].pos.x = sqr[i * 5 + j].pos.x + 100;
	  sqr[i * 5 + j + 1].pos.y = sqr[i * 5 + j].pos.y;
	}
      sqr[(i + 1) * 5].pos.x = sqr[0].pos.x;
      sqr[(i + 1) * 5].pos.y = sqr[i * 5 + j - 1].pos.y + 90;
    }
  bunny_free(sqr);
  return (list);
}

void			display_item(t_bunny_pixelarray *pix, t_list *list,
				     t_bunny_pixelarray **case_ivt)
{
  t_bunny_square       	*sqr;
  int			i;

  i = 0;
  while (list != NULL)
    {
      sqr = (t_bunny_square *)list->data;
      if (case_ivt[i] != NULL)
	blit_pix(pix, case_ivt[i], &sqr->pos);
      list = list->next;
      i++;
    }
}

void				anim_invent(t_bunny_pixelarray *pix, t_list *list)
{
  const t_bunny_position       	*mouse_pos;
  t_bunny_square		*sqr;

  mouse_pos = bunny_get_mouse_position();
  while (list != NULL)
    {
      sqr = (t_bunny_square *)list->data;
      if ((mouse_pos->x > sqr->pos.x &&
	   mouse_pos->x < sqr->pos.x + sqr->width) &&
	  (mouse_pos->y > sqr->pos.y &&
	   mouse_pos->y < sqr->pos.y + sqr->height))
	square_alpha(pix, sqr, 0x77FFFFFF);
      list = list->next;
    }
}

void			display_inventory(t_bunny_position pos,
					  t_bunny_pixelarray *pix,
					  t_inventaire ivt)
{
  t_list		*list;
  t_bunny_position	*mouse_pos;

  pos.y -= 200;
  pos.x += 50;
  mouse_pos = (t_bunny_position *)bunny_get_mouse_position();
  list = NULL;
  init_inventory(pix, pos, ivt);
  list = init_case(pix, pos, list, -1);
  anim_invent(pix, list);
  ivt.case_ivt = mouve_item(pix, ivt.case_ivt, list, mouse_pos);
  display_item(pix, list, ivt.case_ivt);
}
