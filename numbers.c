/*
** numbers.c for  in /home/robin/delivery/CPE_2016_BSQ
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Fri Dec  9 14:11:51 2016 Robin Pronnier
** Last update Fri Dec  9 14:12:49 2016 Robin Pronnier
*/

#include "my.h"

int	nb_colums(char **str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

int	nb_lines(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
