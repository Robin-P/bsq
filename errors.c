/*
** errors.c for  in /home/robin/delivery/CPE_2016_BSQ
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Sun Dec 11 15:22:38 2016 Robin Pronnier
** Last update Tue Dec 13 19:52:42 2016 Robin Pronnier
*/

#include <unistd.h>
#include "my.h"

int		err1(char *str)
{
  int		i;

  i = 0;
  if (str[i] == '\0')
    {
      write(1, "Error: empty file\n", 18);
      return (-1);
    }
  while (str[i] != '\n')
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  write(1, "Error: only numbers in the first line\n", 38);
	  return (-1);
	}
      i = i + 1;
    }
  i = i + 1;
  if (str[i] == '\0')
    {
      write(1, "Error: empty square\n", 20);
      return (-1);
    }
  return (0);
}

int		err2(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\n')
    i = i + 1;
  i = i + 1;
  while (str[i] != '\0')
    {
      if (str[i] != '.' && str[i] != 'o' && str[i] != '\n')
	{
	  write(1, "Error: invalid characters\n", 26);
	  return (-1);
	}
      i = i + 1;
    }
  return (0);
}

int		err3(char *str, int i, int len, int len_up)
{
  while (str[i] != '\n')
    i = i + 1;
  i = i + 1;
  while (str[i] != '\n' && str[i] != '\0')
    {
      len = len + 1;
      i = i + 1;
    }
  i = i + 1;
  while (str[i] != '\0')
    {
      len_up = 0;
      while (str[i] != '\n')
	{
	  len_up = len_up + 1;
	  i = i + 1;
	}
      if (len != len_up)
	{
	  write(1, "Error: different line sizes\n", 28);
	  return (-1);
	}
      i = i + 1;
    }
  return (0);
}

int		err4(char *str)
{
  int	i;
  int	nb;
  int	nb_lines;

  i = 0;
  nb = my_getnbr(str);
  nb_lines = -1;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	nb_lines = nb_lines + 1;
      i = i + 1;
    }
  if (nb != nb_lines)
    {
      write(1, "Error: invalid number of lines\n", 31);
      return (-1);
    }
  return (0);
}
