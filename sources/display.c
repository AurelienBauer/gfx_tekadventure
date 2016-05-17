/*
** position.c for tekadventure in /home/carlen/gfx_tekadventure/position
** 
** Made by carlen
** Login   <carlen@epitech.net>
** 
** Started on  Sat Apr  9 17:15:35 2016 carlen
** Last update Thu Apr 14 22:24:36 2016 carlen
*/

#include "lapin.h"
#include "position.h"

int	cursor_aabb_collision(int cursor_x, int cursor_y, int pos_x, int pos_y)
{
   if (cursor_x >= pos_x && cursor_x < pos_x + 40 &&
       cursor_y >= pos_y && cursor_y < pos_y + 40)
     return (1);
   return (0);
}

void			display_graph(t_position *graph,
				      t_bunny_pixelarray *bg,
				      t_bunny_pixelarray *pic)
{
  t_bunny_position	pos;

  while (graph != NULL)
    {
      pos.x = graph->coordinate[0];
      pos.y = graph->coordinate[1];
      my_blit(bg, pic, &pos);
      graph = graph->next;
    }
}
