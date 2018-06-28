/*
** fonctions.c for  in /home/robin/delivery/CPE_2016_BSQ
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Mon Dec  5 18:24:42 2016 Robin Pronnier
** Last update Tue Dec 13 19:35:56 2016 Robin Pronnier
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      if (nb == -2147483648)
	{
	  my_put_nbr(-214748364);
	  my_putchar('8');
	  return (0);
	}
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0 && nb <= 9)
    {
      my_putchar(nb + 48);
    }
  if (nb > 9)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  return (0);
}

int	my_putstr(char *str)
{
  if ((write(1, str, my_strlen(str))) == -1)
    return (84);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

int	my_getnbr(char *str)
{
  int	x;
  int	y;
  int	z;

  x = 1;
  y = 0;
  z = 214748364;
  while (*str == 45 || *str == 43)
    {
      if (*str == 45)
	x = x * (-1);
      str = str + 1;
    }
  while (*str != '\0' && *str >= 48 && *str <= 57)
    {
      if (y > z || (y == z && *str > 7 && x == 1)
	  || (y == z && *str > 0 && x == -1))
	return (0);
      y = y * 10 + *str - 48;
      str = str + 1;
    }
  if (x == -1)
    y = y * -1;
  return (y);
}
