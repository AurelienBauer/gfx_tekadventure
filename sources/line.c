/*
** line.c for  in /home/thomas/Documents/epitech
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Mon Jan 25 10:40:51 2016 thomas
** Last update Fri Apr 15 15:32:50 2016 carlen
*/

#include "lapin.h"
#include "parallax.h"

void                    right_abs(t_bunny_pixelarray *pix,
                                  t_bunny_position *pos,
                                  t_bunny_position post,
                                  t_line info)
{
  info.temp = pos[0].y;
  while (post.x < pos[1].x)
    {
      info.square.pos = post;
      square(pix, &info.square, info.color);
      info.temp += info.coef;
      post.y = (int)info.temp;
      post.x++;
    }
}

void                    left_abs(t_bunny_pixelarray *pix,
                                 t_bunny_position *pos,
                                 t_bunny_position post,
                                 t_line info)
{
  info.temp = pos[0].y;
  while (post.x > pos[1].x)
    {
      info.square.pos = post;
      square(pix, &info.square, info.color);
      info.temp -= info.coef;
      post.y = (int)info.temp;
      post.x--;
    }
}

void                    ordonate(t_bunny_pixelarray *pix,
                                 t_bunny_position *pos,
                                 t_bunny_position post,
                                 t_line info)
{
  while (post.y != pos[1].y)
    {
      info.square.pos = post;
      square(pix, &info.square, info.color);
      post.y++;
      if (pos[0].x <= pos[1].x && pos[0].y < pos[1].y)
	info.temp += info.coef;
      else if (pos[0].x > pos[1].x && pos[0].y < pos[1].y)
	info.temp += info.coef;
      else if (pos[0].x <= pos[1].x && pos[0].y > pos[1].y)
        {
          info.temp -= info.coef;
          post.y -= 2;
        }
      else if (pos[0].x > pos[1].x && pos[0].y > pos[1].y)
        {
          info.temp -= info.coef;
          post.y -= 2;
        }
      post.x = (int)info.temp;
    }
}

void                    line(t_bunny_pixelarray *pix,
                             t_bunny_square squar,
			     t_bunny_position pos2,
                             unsigned int color)
{
  t_bunny_position      post;
  t_bunny_position	pos[2];
  t_line                info;

  pos[0] = squar.pos;
  pos[1] = pos2;
  info.coef = (double)(pos[1].y - pos[0].y) /(double)(pos[1].x
                                                      - pos[0].x);
  info.color = color;
  post.x = pos[0].x;
  post.y = pos[0].y;
  info.square = squar;
  if (pos[0].x < pos[1].x && (info.coef <= 1 && info.coef >= -1))
    right_abs(pix, pos, post, info);
  else if (pos[0].x > pos[1].x && (info.coef <= 1 && info.coef >= -1))
    left_abs(pix, pos, post, info);
  else if (info.coef > 1 || info.coef < - 1 || info.coef == 0)
    {
      info.coef = 1 / info.coef;
      info.temp = pos[0].x;
      ordonate(pix, pos, post, info);
    }
  squar.pos = pos[1];
  square(pix, &squar, color);
}
