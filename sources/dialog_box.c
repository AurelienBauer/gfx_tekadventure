/*
** dialog_box.c for  in /home/tek/rendu/gfx_tekadventure/text_box
** 
** Made by 
** Login   <tek@epitech.net>
** 
** Started on  Wed Apr  6 15:16:38 2016 
** Last update Sun Apr 17 15:39:28 2016 
*/

#include "parallax.h"

int				my_strlen(char *str)
{
  int				i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char				*cut_str(char *str, int n)
{
  int				i;
  char				*new_str;

  if ((new_str = malloc(sizeof(char) * n + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\0' && i < n)
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = '\0';
  return (new_str);
}

t_bunny_pixelarray		*init_box(t_bunny_pixelarray *texture,
					  t_bunny_square *dim)
{
  t_bunny_pixelarray	*strch;

  if ((strch = bunny_new_pixelarray(dim->width, dim->height)) == NULL)
    return (NULL);
  stretch(strch, texture);
  return (strch);
}

void				dialog_box(t_bunny_pixelarray *pix, t_dialog_box box,
					    t_bunny_square *dim)
{
  t_bunny_pixelarray		*text_box;
  t_bunny_pixelarray		*strch;
  static int			nb_print = 0;

  if ((strch = bunny_new_pixelarray(1150, 20)))
    {
      stretch(strch, box.font);
      text_box = init_box(box.texture, dim);
      my_blit(pix, text_box, &dim->pos);
      tektext(pix, strch, &dim->pos, cut_str(box.str, nb_print / 2));
      bunny_delete_clipable(&text_box->clipable);
      bunny_delete_clipable(&strch->clipable);
      if (nb_print < my_strlen(box.str) * 2)
	nb_print++;
    }
}
