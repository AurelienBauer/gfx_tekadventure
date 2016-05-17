/*
** text.c for  in /home/tek/rendu/gfx_tekgui
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Mon Feb 22 16:09:00 2016 
** Last update Sat Feb 27 08:53:39 2016 
*/

#include "tekgui.h"

void			make_text(t_bunny_pixelarray *pix, t_bunny_pixelarray *img,
				  char *text, t_bunny_position pos)
{
  t_bunny_position	pos_rela;

  pos_rela = pos;
  while (*text)
    {
      if (*text == '\n')
	{
	  pos_rela.y = pos_rela.y + 7;
	  pos_rela.x = pos.x;
	}
      teklettre(pix, img, &pos_rela, *text);
      text++;
      pos_rela.x = pos_rela.x + 6;
    }
}
