/*
** graph.c for tekadventure in /home/carlen/gfx_tekadventure/position
**
** Made by carlen
** Login   <carlen@epitech.net>
**
** Started on  Sun Apr 10 14:37:34 2016 carlen
** Last update Sun Apr 17 13:24:09 2016 thomas
*/

#include "lapin.h"
#include "position.h"

t_position	*init_graph(void *scope)
{
  t_position	*new;

  if ((new = bunny_malloc(sizeof(t_position))) == NULL)
    return (NULL);
  new->next = NULL;
  my_mensetab_int(new->tmp_path, DEFAULT_INT_TAB_LEN, DEFAULT_NO_VALUE);
  my_mensetab_int(new->coordinate, DEFAULT_INT_TAB_LEN, DEFAULT_NO_VALUE);
  if (get_info(new, scope))
    return (NULL);
  return (new);
}

t_position	*append_graph(t_position *head, void *scope)
{
  t_position	*new;
  t_position	*buff;

  buff = head;
  if ((new = bunny_malloc(sizeof(t_position))) == NULL)
    return (NULL);
  while (buff->next != NULL)
    buff = buff->next;
  buff->next = new;
  my_mensetab_int(new->tmp_path, DEFAULT_INT_TAB_LEN, DEFAULT_NO_VALUE);
  my_mensetab_int(new->coordinate, DEFAULT_INT_TAB_LEN, DEFAULT_NO_VALUE);
  if (get_info(new, scope))
    return (NULL);
  new->next = NULL;
  return (head);
}

void		free_graph(t_position *list)
{
  t_position	*buff;

  buff = list;
  while (buff != NULL)
    {
      bunny_free(buff);
      buff = buff->next;
    }
  bunny_free(list);
}

int		check_index(t_position *list, unsigned int i,
			    unsigned int len)
{
  unsigned int	j;
  int		d_tab[DEFAULT_INT_TAB_LEN];

  my_mensetab_int(d_tab, DEFAULT_INT_TAB_LEN, DEFAULT_NO_VALUE);
  while (list != NULL)
    {
      d_tab[i] = list->index;
      list = list->next;
      i++;
    }
  while (d_tab[len] != DEFAULT_NO_VALUE)
    len++;
  i = 0;
  while (i < len)
    {
      j = i + 1;
      while (j < len)
	{
	  if (d_tab[i] == d_tab[j])
	    return (1);
	  j++;
	}
      i++;
    }
  return (0);
}

t_position	*fill_graph(t_scope *scopes)
{
  unsigned int	i;
  t_position	*graph;
  char		*type;

  i = 0;
  graph = NULL;
  scopes = scopes->next;
  while (scopes != NULL)
    {
      type = (char *)bunny_ini_scope_get_field(scopes->scope, "type", 0);
      if (my_strcmp(type, "position") == 0)
	{
	  if ((graph = (i == 0) ?
	       init_graph(scopes->scope) :
	       append_graph(graph, scopes->scope)) == NULL)
	    return (NULL);
	  i++;
	}
      scopes = scopes->next;
    }
  return ((check_index(graph, 0, 0)) ? NULL : graph);
}
