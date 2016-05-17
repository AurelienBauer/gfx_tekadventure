/*
** path.c for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Fri Apr 15 15:17:48 2016 Thomas HENON
** Last update Fri Apr 15 15:17:49 2016 thomas
*/

#include "maps.h"

char    *my_strcat(char *str1, char *str2)
{
  int   i;
  int   i2;
  char  *str3;

  if (0 == (str3 = bunny_malloc(my_strlen(str1) + my_strlen(str2) + 1)))
    return (NULL);
  i = 0;
  i2 = 0;
  while (str1 && str1[i2])
    str3[i++] = str1[i2++];
  i2 = 0;
  while (str2 && str2[i2])
    str3[i++] = str2[i2++];
  str3[i] = '\0';
  return (str3);
}

char	*concat_path(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i])
    i++;
  if (str1[i - 1] != '/')
      str1 = my_strcat(str1, "/");
  return (my_strcat(str1, str2));
}
