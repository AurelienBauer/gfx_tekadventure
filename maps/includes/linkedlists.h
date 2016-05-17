/*
** linkedlists.h for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps/includes
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Fri Apr 15 15:21:58 2016 Thomas HENON
** Last update Fri Apr 15 15:21:59 2016 thomas
*/

#ifndef __LINKEDLISTS_H__
# define __LINKEDLISTS_H__

# include <stdlib.h>

typedef struct          s_linkedlist
{
  int                   nbr_elems;
  void                  *data;
  struct s_linkedlist   *next;
}                       t_linkedlist;

char		push_back(t_linkedlist **head, void *data);
t_linkedlist	*new_elem(void *data);
void		free_list(t_linkedlist *head);
void		delete_elem(t_linkedlist **head, void *ptr);
t_linkedlist	*get_elem(t_linkedlist *head, int i);

#endif
