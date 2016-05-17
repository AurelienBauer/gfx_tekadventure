/*
** str.c for tekadventure in /home/carlen/gfx_tekadventure/position
** 
** Made by carlen
** Login   <carlen@epitech.net>
** 
** Started on  Sun Apr 10 14:17:05 2016 carlen
** Last update Sun Apr 10 14:18:15 2016 carlen
*/

#include "lapin.h"
#include "position.h"

int	my_strcmp(char *s, char *s1)
{
  while (*s && *s1)
    {
      if (*s != *s1)
	return (1);
      s++;
      s1++;
    }
  if (*s != '\0' || *s1 != '\0')
    return (1);
  return (0);
}

void	my_strcpy(char *s, char *s1)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (s == NULL)
    return;
  while (s[i] != '\0')
    {
      s[i] = s1[j];
      i++;
      j++;
    }
}

int	str_to_int(char *str)
{
  int	i;
  int	rest;
  int	neg;

  i = -1;
  neg = 0;
  rest = 0;
  if (*str == '-')
    {
      neg = 1;
      str++;
    }
  while (str[++i] != '\0')
    rest = rest * 10 + str[i] - '0';
  return ((neg) ? rest * -1 : rest);
}
