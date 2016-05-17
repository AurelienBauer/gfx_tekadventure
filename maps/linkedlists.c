/*
** linkedlists.c for PSU_2015_my_select in /home/thomas/Documents/epitech/PSU_2015_my_select
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Tue Feb 16 10:49:08 2016 Thomas HENON
** Last update Tue Apr 12 12:05:21 2016 John Doe
*/

#include "linkedlists.h"

char		push_back(t_linkedlist **head, void *data)
{
  t_linkedlist	*tmp;

  if (*head == NULL)
    {
      if (NULL == (*head = new_elem(data)))
	return (0);
      return (1);
    }
  tmp = *head;
  while (tmp->next)
    tmp = tmp->next;
  if (NULL == (tmp->next = new_elem(data)))
    return (0);
  (*head)->nbr_elems++;
  return (1);
}

t_linkedlist	*new_elem(void *data)
{
  t_linkedlist	*elem;

  if (NULL == (elem = malloc(sizeof(t_linkedlist))))
    return (NULL);
  elem->data = data;
  elem->next = NULL;
  elem->nbr_elems = 1;
  return (elem);
}

void		free_list(t_linkedlist *head)
{
  t_linkedlist	*tmp;

  while (head)
    {
      tmp = head;
      head = head->next;
      free(tmp);
    }
}

void		delete_elem(t_linkedlist **head, void *ptr)
{
  t_linkedlist	*cur;
  t_linkedlist	*prev;

  cur = *head;
  prev = NULL;
  while (cur)
    {
      if (cur->data == ptr)
	{
	  if (prev)
	    prev->next = cur->next;
	  else if (!prev && cur->next)
	    *head = cur->next;
	  else
	    *head = NULL;
	}
      prev = cur;
      cur = cur->next;
    }
}

t_linkedlist	*get_elem(t_linkedlist *head, int i)
{
  int	i2;

  i2 = 0;
  while (head && i2 < i)
    {
      head = head->next;
      i2++;
    }
  return (head);
}
