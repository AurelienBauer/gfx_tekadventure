/*
** my_putstr.c for  in /home/henon_t/rendu/Piscine_C_J04
** 
** Made by Thomas Henon
** Login   <henon_t@epitech.net>
** 
** Started on  Thu Oct  1 09:49:52 2015 Thomas Henon
** Last update Wed Jan  6 11:24:32 2016 thomas
*/

int	my_strlen(char *str)
{
  int	i;

  if (!str)
    return (0);
  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}
