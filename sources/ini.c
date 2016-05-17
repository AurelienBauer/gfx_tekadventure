/*
** ini.c for tekadventure in /home/carlen/gfx_tekadventure/position
** 
** Made by carlen
** Login   <carlen@epitech.net>
** 
** Started on  Sun Apr 10 14:18:56 2016 carlen
** Last update Sun Apr 10 14:19:11 2016 carlen
*/

#include "lapin.h"
#include "position.h"

t_bunny_ini	*get_ini(const char *file_name)
{
  t_bunny_ini	*ini;

  ini = bunny_load_ini(file_name);
  return (ini);
}
