/*
** profuce_graph.c for tekadventure in /home/carlen/gfx_tekadventure/position
** 
** Made by carlen
** Login   <carlen@epitech.net>
** 
** Started on  Sun Apr 10 14:21:10 2016 carlen
** Last update Sun Apr 10 14:35:01 2016 carlen
*/

#include "lapin.h"
#include "position.h"

short	       init_node_graph(t_position *list, t_position *entity,
			       const int pos)
{
  while (list != NULL)
    {
      if (list->index == pos)
	{
	  if ((entity->graph = init_scope(list)) == NULL)
	    return (1);
	  return (0);
	}
      list = list->next;
    }
  return (1);
}

short		append_node_graph(t_position *list, t_position *entity,
				  const int pos)
{
  while (list != NULL)
    {
      if (list->index == pos)
	{
	  if ((append_scope(entity->graph, list)) == NULL)
	    return (1);
	  return (0);
	}
      list = list->next;
    }
  return (1);
}

int	check_proper_graph(t_position *list)
{
  int	i;
  int	j;
  int	len;

  while (list != NULL)
    {
      len = 0;
      while (list->tmp_path[len] != DEFAULT_NO_VALUE)
	len++;
      i = 0;
      while (i < len)
	{
	  j = i + 1;
	  while (j < len)
	    {
	      if (list->tmp_path[i] == list->tmp_path[j])
		return (1);
	      j++;
	    }
	  i++;
	}
      list = list->next;
    }
  return (0);
}

int		produce_graph(t_position *list)
{
  short		error;
  int		i;
  t_position	*head;

  head = list;
  while (list != NULL)
    {
      i = 0;
      while (list->tmp_path[i] != DEFAULT_NO_VALUE)
	{
	  if (i == 0)
	    error = init_node_graph(head, list, list->tmp_path[i]);
	  else
	    error = append_node_graph(head, list, list->tmp_path[i]);
	  if (error)
	    return (1);
	  i++;
	}
      list = list->next;
    }
  return (check_proper_graph(head));
}
