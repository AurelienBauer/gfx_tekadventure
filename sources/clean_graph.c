/*
** clean_graph.c for tekadventure in /home/carlen/gfx_tekadventure/position
** 
** Made by carlen
** Login   <carlen@epitech.net>
** 
** Started on  Sun Apr 10 15:56:29 2016 carlen
** Last update Thu Apr 14 22:24:26 2016 carlen
*/

#include "lapin.h"
#include "position.h"

void		clean_graph_remove_same(t_position *graph)
{
  t_scope	*d_buff;
  t_position	*d_buff_entity;

  while (graph != NULL)
    {
      d_buff = graph->graph;
      while (d_buff != NULL)
	{
	  d_buff_entity = d_buff->scope;
	  if (graph->index == d_buff_entity->index)
	    delete_node(d_buff, (t_scope **)&graph->graph);
	  d_buff = d_buff->next;
	}
      graph = graph->next;
    }
}

void		clean_graph(t_position *graph, int i)
{
  int		tmp_path[DEFAULT_INT_TAB_LEN];
  t_scope	*d_buff;
  t_scope	*head;
  t_position	*d_head;
  t_position	*d_buff_entity;

  d_head = graph;
  while (graph != NULL)
    {
      d_buff = graph->graph;
      my_mensetab_int(tmp_path, DEFAULT_INT_TAB_LEN, DEFAULT_NO_VALUE);
      i = 0;
      head = d_buff;
      while (d_buff != NULL)
	{
	  d_buff_entity = d_buff->scope;
	  if (is_in_already_in_graph(tmp_path, d_buff_entity->index))
	    delete_node(d_buff, &head);
	  tmp_path[i] = d_buff_entity->index;
	  i++;
	  d_buff = d_buff->next;
	}
      graph = graph->next;
    }
  clean_graph_remove_same(d_head);
}
