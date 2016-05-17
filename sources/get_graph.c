/*
** get_graph.c for tekadventure in /home/carlen/gfx_tekadventure/position
** 
** Made by carlen
** Login   <carlen@epitech.net>
** 
** Started on  Sun Apr 10 14:40:06 2016 carlen
** Last update Sun Apr 10 14:40:21 2016 carlen
*/

#include "lapin.h"
#include "position.h"

t_position	*get_graph(const char *file_name)
{
  t_position	*graph;
  t_bunny_ini	*ini;
  t_scope	*scope;
  t_scope	*buff;

  ini = get_ini(file_name);
  if (ini == NULL)
    return (NULL);
  scope = get_scope(ini);
  if (scope == NULL)
    return (NULL);
  graph = fill_graph(scope);
  buff = scope;
  while (buff != NULL)
    {
      bunny_free(buff);
      buff = buff->next;
    }
  bunny_free(scope);
  return (graph);
}
