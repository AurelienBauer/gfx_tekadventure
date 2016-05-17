/*
** function_graph_to_call.c for tekadventure in /home/carlen/gfx_tekadventure/position
**
** Made by carlen
** Login   <carlen@epitech.net>
**
** Started on  Sun Apr 10 16:45:34 2016 carlen
** Last update Sun Apr 17 13:20:08 2016 thomas
*/

#include "lapin.h"
#include "position.h"

int		can_reach(t_position *entity, const int index)
{
  t_scope	*d_buff;
  t_position	*d_buff_entity;

  d_buff = entity->graph;
  while (d_buff != NULL)
    {
      d_buff_entity = d_buff->scope;
      if (d_buff_entity->index == index)
	return (0);
      d_buff = d_buff->next;
    }
  return (1);
}

void		*get_path_next(t_position *entity, const int index, int curnt)
{
  unsigned int	i;
  t_scope	*d_buff;
  t_scope	*d_buff_return;

  i = 0;
  d_buff_return = NULL;
  if (curnt >= index)
    {
      while (curnt >= index)
	{
	  d_buff = entity->graph;
	  while (d_buff != NULL)
	    {
	      if (((t_position *)(d_buff->scope))->index == curnt && i++ == 0)
		d_buff_return = init_scope(d_buff->scope);
	      else if (((t_position *)(d_buff->scope))->index == curnt)
		append_scope(d_buff_return, d_buff->scope);
	      d_buff = d_buff->next;
	    }
	  curnt--;
	}
    }
  return (d_buff_return);
}

void		*get_path(t_position *entity, const int index, unsigned int i)
{
  int		curnt;
  t_scope	*d_buff;
  t_scope	*d_buff_return;

  curnt = entity->index;
  d_buff_return = NULL;
  if (curnt < index)
    {
      while (curnt <= index)
	{
	  d_buff = entity->graph;
	  while (d_buff != NULL)
	    {
	      if (((t_position *)(d_buff->scope))->index == curnt && i++ == 0)
		d_buff_return = init_scope(d_buff->scope);
	      else if (((t_position *)(d_buff->scope))->index == curnt)
		append_scope(d_buff_return, d_buff->scope);
	      d_buff = d_buff->next;
	    }
	  curnt++;
	}
    }
  else if (curnt >= index)
    d_buff_return = get_path_next(entity, index, curnt);
  return (d_buff_return);
}
