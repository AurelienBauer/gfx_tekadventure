/*
** scope.c for tekadventure in /home/carlen/gfx_tekadventure/position
**
** Made by carlen
** Login   <carlen@epitech.net>
**
** Started on  Sun Apr 10 14:19:57 2016 carlen
** Last update Sun Apr 17 13:23:33 2016 thomas
*/

#include "lapin.h"
#include "position.h"

t_scope		*init_scope(void *scope)
{
  t_scope	*head;

  if ((head = bunny_malloc(sizeof(t_scope))) == NULL)
    return (NULL);
  head->scope = scope;
  head->next = NULL;
  return (head);
}

t_scope		*append_scope(t_scope *head, void *scope)
{
  t_scope	*new;
  t_scope	*buff;

  buff = head;
  if ((new = bunny_malloc(sizeof(t_scope))) == NULL)
    return (NULL);
  while (buff->next != NULL)
    buff = buff->next;
  buff->next = new;
  new->scope = scope;
  new->next = NULL;
  return (head);
}

t_scope		*get_scope(t_bunny_ini *ini)
{
  t_scope	*scopes;
  void		*f_scope;

  f_scope = bunny_ini_first(ini);
  if (f_scope == NULL)
    return (NULL);
  scopes = init_scope(f_scope);
  if (scopes == NULL)
    return (NULL);
  while ((f_scope = bunny_ini_next(ini, f_scope)) != NULL)
    append_scope(scopes, f_scope);
  return (scopes);
}
