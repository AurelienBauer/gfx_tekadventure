/*
** free_e.c for dfh in /home/carlen/bauer/gfx_tekadventure
** 
** Made by carlen
** Login   <carlen@epitech.net>
** 
** Started on  Fri Apr 15 13:37:23 2016 carlen
** Last update Fri Apr 15 14:21:46 2016 carlen
*/

#include "lapin.h"
#include "parallax.h"

void	free_one(t_game *game)
{
  bunny_delete_clipable((t_bunny_clipable *)&game->mgnd1);
}
