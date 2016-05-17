/*
** player.c<house_scene> for dfiojd in /home/carlen/bauer/gfx_tekadventure/house_scene
** 
** Made by carlen
** Login   <carlen@epitech.net>
** 
** Started on  Thu Apr 14 17:31:18 2016 carlen
** Last update Fri Apr 15 14:45:39 2016 carlen
*/

#include "lapin.h"
#include "parallax.h"

void	set_position_player(t_player *player, const int x, const int y)
{
  int	buff_x;
  int	buff_y;

  buff_x = (x <= 0) ? 0 : x;
  buff_x = (x + 110 > WIDTH) ? WIDTH - 110 : x;
  buff_y = (y <= 0) ? 0 : y;
  buff_y = (y + 160 > HEIGHT) ? HEIGHT - 160 : y;
  player->pos.x = buff_x;
  player->pos.y = buff_y;
}

void	move_player_cursor_position(t_player *ply, int x, int y)
{
  int	buff_xy[2];

  buff_xy[0] = ply->pos.x;
  buff_xy[1] = ply->pos.y;
  if (ply->pos.x == x && ply->pos.y < y)
    set_position_player(ply, ply->pos.x, ply->pos.y + PLAYER_SPEED_AUTO);
  else if (ply->pos.x == x && ply->pos.y > y)
    set_position_player(ply, ply->pos.x, ply->pos.y - PLAYER_SPEED_AUTO);
  else if (ply->pos.y == y && ply->pos.x < x)
    set_position_player(ply, ply->pos.x + PLAYER_SPEED_AUTO, ply->pos.y);
  else if (ply->pos.y == y && ply->pos.x > x)
  set_position_player(ply, ply->pos.x - PLAYER_SPEED_AUTO, ply->pos.y);
  if (ply->pos.x < x && ply->pos.y < y)
    set_position_player(ply, ply->pos.x + PLAYER_SPEED_AUTO,
			  ply->pos.y + PLAYER_SPEED_AUTO);
  else if (ply->pos.x > x && ply->pos.y > y)
    set_position_player(ply, ply->pos.x - PLAYER_SPEED_AUTO,
			ply->pos.y - PLAYER_SPEED_AUTO);
  else if (ply->pos.x > x && ply->pos.y < y)
      set_position_player(ply, ply->pos.x - PLAYER_SPEED_AUTO,
			  ply->pos.y + PLAYER_SPEED_AUTO);
  else if (ply->pos.x < x && ply->pos.y > y)
    set_position_player(ply, ply->pos.x + PLAYER_SPEED_AUTO,
			ply->pos.y - PLAYER_SPEED_AUTO);
  adjuste_player_position(ply, x, y, buff_xy);
}

void	adjuste_player_position(t_player *player, int x, int y, int *buff_xy)
{
  int	i;

  i = 0;
  while (i < PLAYER_SPEED_AUTO)
    {
      if (player->pos.x + i == x || player->pos.x - i == x)
	set_position_player(player, x, player->pos.y);
      else if (player->pos.y + i == y || player->pos.y - i == y)
	set_position_player(player, player->pos.x, y - 6);
      i++;
    }
  if (player->pos.y > buff_xy[1])
    player->step.y = 0;
  else if (player->pos.y < buff_xy[1])
    player->step.y = 3;
  else if (player->pos.x > buff_xy[0])
    player->step.y = 2;
  else if (player->pos.x < buff_xy[0])
    player->step.y = 1;
  player->step.x = (player->pos.x == x ||
		    player->pos.x + 110 == WIDTH ||
		    ((player->pos.x == x && player->pos.y + 6 == y))) ?
    player->step.x : (player->step.x + 1) % 12;
}

