/*
** addnew_elem_inlist.c for  in /home/aurelien/rendu/IGRAPH/gfx_tekgui/lib/my
**
** Made by Aur�lien
** Login   <aurelien.bauer@epitech.net>
**
** Started on  Mon Feb  8 11:05:20 2016 Aur�lien
** Last update Sun Apr 17 14:45:35 2016 Thomas HENON
*/

#include "lapin.h"
#include "parallax.h"

t_list		*addnew_elem_inlist(t_list *list, void *data)
{
  t_list	*new_list;
  t_list	*tmp_list;

  tmp_list = list;
  if ((new_list = malloc(sizeof(*list))) == NULL)
    return (NULL);
  new_list->data = data;
  new_list->next = NULL;
  if (list == NULL)
    return (new_list);
  while (tmp_list->next != NULL)
    tmp_list = tmp_list->next;
  tmp_list->next = new_list;
  return (list);
}
