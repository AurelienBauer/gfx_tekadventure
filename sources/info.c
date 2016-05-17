/*
** info.c for tekadventure in /home/carlen/gfx_tekadventure/position
** 
** Made by carlen
** Login   <carlen@epitech.net>
** 
** Started on  Sun Apr 10 14:35:39 2016 carlen
** Last update Sun Apr 10 14:36:56 2016 carlen
*/

#include "lapin.h"
#include "position.h"

void	my_mensetab_int(int *tab, int len, int value)
{
  int	i;

  i = 0;
  while (i < len)
    {
      tab[i] = value;
      i++;
    }
}

void	my_mensetab_char(char *tab, int len, char value)
{
  int	i;

  i = 0;
  while (i < len)
    {
      tab[i] = value;
      i++;
    }
}

int		set_entity(void *entity, void *scope, const char *field,
			   const int *infos)
{
  int		*buff_int;
  const char	*buff;

  buff = bunny_ini_scope_get_field(scope, field, infos[0]);
  if (buff == NULL)
    return (1);
  if (infos[1] == INT)
    {
      buff_int = (int *)entity;
      *buff_int = str_to_int((char *)buff);
    }
  return (0);
}

int	get_info(t_position *entity, void *scope)
{
  int	infos[2];

  infos[0] = 0;
  infos[1] = INT;
  if (set_entity(&entity->index, scope, "index", infos))
    return (1);
  if (set_entity(&entity->is_first, scope, "is_first", infos))
    return (1);
  if (set_entity(&entity->is_next, scope, "next", infos))
    return (1);
  infos[0] = 0;
  while (!(set_entity(&entity->tmp_path[infos[0]], scope, "path", infos)))
    infos[0]++;
  if (!infos[0])
    return (1);
  infos[0] = 0;
  while (!(set_entity(&entity->coordinate[infos[0]], scope, "coordinates",
		      infos)))
    infos[0]++;
  if (!infos[0])
    return (1);
  return (0);
}
