/*
** finish_graph.c for tekadventure in /home/carlen/gfx_tekadventure/position
**
** Made by carlen
** Login   <carlen@epitech.net>
**
** Started on  Sun Apr 10 15:53:49 2016 carlen
** Last update Sun Apr 17 13:24:46 2016 thomas
*/

#include "lapin.h"
#include "position.h"

void			*make_graph_copy(void *graph)
{
  unsigned short	i;
  t_scope		*d_buff;
  t_scope		*d_buff_copy;

  i = 0;
  d_buff = graph;
  while (d_buff != NULL)
    {
      if (i == 0)
	d_buff_copy = init_scope(d_buff->scope);
      else
	append_scope(d_buff_copy, d_buff->scope);
      d_buff = d_buff->next;
      i++;
    }
  return (d_buff_copy);
}

void		append_two_graph(t_position *to_had_entity, void *graph)
{
  t_scope	*d_buff;
  t_scope	*d_buff_to_append;

  d_buff = graph;
  d_buff_to_append = to_had_entity->graph;
  while (d_buff_to_append != NULL)
    {
      append_scope(d_buff, d_buff_to_append->scope);
      d_buff_to_append = d_buff_to_append->next;
    }
}

void		complete_graph_path(t_position *graph)
{
  t_scope	*d_buff;
  t_scope	*d_buff_copy;

  while (graph != NULL)
    {
      d_buff = graph->graph;
      d_buff_copy = make_graph_copy(graph->graph);
      while (d_buff != NULL)
	{
	  append_two_graph(d_buff->scope, d_buff_copy);
	  d_buff = d_buff->next;
	}
      graph->graph = d_buff_copy;
      graph = graph->next;
    }
}

short		is_in_already_in_graph(int *tab, int item)
{
  unsigned int	i;
  unsigned int	len;

  i = 0;
  len = 0;
  while (tab[len] > DEFAULT_NO_VALUE)
    len++;
  i = 0;
  while (i < len)
    {
      if (tab[i] == item)
	return (1);
      i++;
    }
  return (0);
}

void		delete_node(t_scope *node, t_scope **head)
{
  t_scope	*temp;
  t_scope	*current;
  t_scope	*previous;

  if (node == *head)
    {
      temp = *head;
      *head = (*head)->next;
      return;
    }
  current = (*head)->next;
  previous = *head;
  while (current != NULL && previous != NULL)
    {
      if (node == current)
	{
	  temp = current;
	  previous->next = current->next;
	  bunny_free(temp);
	  return;
	}
      previous = current;
      current = current->next;
    }
  return;
}
