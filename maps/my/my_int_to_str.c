/*
** my_int_to_str.c for epitech in /home/thomas/Documents/epitech/gfx_tekadventure/maps/my
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Fri Apr 15 15:21:31 2016 Thomas HENON
** Last update Fri Apr 15 15:21:33 2016 thomas
*/

#include "my.h"

char	*remove_useless_zero(char *str)
{
  int	i;
  char	*str_cleaned;

  i = 0;
  while (str[i] == '0')
    i++;
  return (&str[i]);
}

long long	my_long_power_rec(long long nb, int power)
{
  if (power == 0)
    return (1);
  if (power != 1)
    nb = nb * my_long_power_rec(nb, (power - 1));
  else
    return (nb);
}

char	*my_int_to_str(int nbr)
{
  int	i;
  char	*str;
  char	neg;

  if (nbr == 0)
    return ("0");
  if (NULL == (str = malloc(11)))
    return (NULL);
  str[10] = 0;
  neg = (nbr < 0) ? 1 : 0;
  i = 0;
  while (i < 10)
    str[i] = '0' + (nbr / my_long_power_rec(10, i++) % 10);
  str = remove_useless_zero(my_revstr(str));
  if (neg)
    return (my_strcat("-", str));
  return (str);
}
