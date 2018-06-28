/*
** sausageparty.c for  in /home/robin/delivery/CPE_2016_BSQ
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Mon Dec  5 13:20:31 2016 Robin Pronnier
** Last update Thu Dec 15 13:47:28 2016 Robin Pronnier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

int		my_show_tab(char **av)
{
  int		i;

  i = 0;
  while (av[i])
    {
      my_putstr(av[i]);
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}

int		my_line_size(char *str)
{
  int		i;
  int		len;

  i = 0;
  len = 0;
  while (str[i] != '\n')
    {
      i = i + 1;
    }
  i = i + 1;
  while (str[i] != '\n' && str[i] != '\0')
    {
      i = i + 1;
      len = len + 1;
    }
  return (len);
}

int		my_transfopre(char *str, int i, int k)
{
  char		*av;
  int		len;
  int		col;

  len = my_line_size(str);
  col = my_getnbr(str);
  if ((av = malloc(sizeof(str) * (len + 1) * (col + 1))) == NULL)
    return (-1);
  while (str[i] != '\n')
    i = i + 1;
  i = i + 1;
  while (str[i] != '\0')
    {
      av[k] = str[i];
      i = i + 1;
      k = k + 1;
    }
  av[k] = '\0';
  if ((my_transfo(av, 0, col, len)) == -1)
    return (-1);
  free(av);
  return (col);
}

int		my_transfo(char *str, int k, int col, int lin)
{
  t_bsq		bsq;
  char		**av;
  int		i;
  int		j;

  i = 0;
  if ((av = malloc(sizeof(char *) * (lin + 1) *(col + 1))) == NULL)
    return (-1);
  while (str[i] != '\0')
    {
      if ((av[k] = malloc(sizeof(char) * (lin + 1))) == NULL)
	return (-1);
      j = 0;
      while (str[i] != '\n' && str[i] != '\0')
	{
	  av[k][j] = str[i];
	  j = j + 1;
	  i = i + 1;
	}
      av[k][j] = '\0';
      i = i + 1;
      k = k + 1;
    }
  av[k] = '\0';
  stct(av, &bsq);
}

int		my_recup(struct stat *sa, char *str)
{
  int		fd;
  char		*buffer;

  if (stat(str, sa) == -1 ||
      ((buffer = malloc(sizeof(str) * (sa->st_size))) == NULL) ||
      ((fd = open(str, O_RDONLY)) == -1) ||
      ((read(fd, buffer, sa->st_size)) == -1))
    return (84);
  if ((err1(buffer) == -1) ||
      (err2(buffer) == -1) ||
      (err3(buffer, 0, 0, 0) == - 1) ||
      (err4(buffer) == -1))
    return (84);
  if (my_transfopre(buffer, 0, 0) == -1)
    return (84);
  free(buffer);
  close(fd);
  return (0);
}
