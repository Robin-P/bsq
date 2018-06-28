/*
** algo.c for  in /home/robin/delivery/CPE_2016_BSQ
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Tue Dec  6 12:52:14 2016 Robin Pronnier
** Last update Wed Dec 14 20:57:54 2016 Robin Pronnier
*/

#include "struct.h"
#include "my.h"

int		stct(char **av, struct s_bsq *infos)
{
  infos->x = 0;
  infos->y = 0;
  infos->size = 0;
  infos->nb_col = nb_lines(av[0]) - 1;
  infos->nb_lin = nb_colums(av) - 1;
  infos->size_up = 0;
  infos->col = -1;
  infos->lin = -1;
  appel(av, *infos);
}

int		appel(char **av, struct s_bsq infos)
{
  while (infos.lin != infos.nb_lin)
    {
      infos.lin = infos.lin + 1;
      infos.col = -1;
      while (infos.col != infos.nb_col)
	{
	  infos.col = infos.col + 1;
	  while ((find_square(av, infos.lin, infos.col, infos.size_up) == 1))
	    infos.size_up = infos.size_up + 1;
	  if (infos.size < infos.size_up - 1)
	    {
	      infos.size = infos.size_up - 1;
	      infos.y = infos.lin;
	      infos.x = infos.col;
	    }
	}
    }
  fill_square(av, infos.y, infos.x, infos.size);
  return (0);
}

int		fill_square(char **av, int lin, int col, int size)
{
  int		i;
  int		j;
  int		size_i;
  int		size_c;

  i = lin - 1;
  j = col - 1;
  size_i = size + i;
  size_c = size + j;
  while (i < size_i)
    {
      i = i + 1;
      j = col - 1;
      while (j < size_c)
	{
	  j = j + 1;
	  av[i][j] = 'x';
	}
    }
  my_show_tab(av);
  return (0);
}

int		find_square(char **av, int lin, int col, int size)
{
  int		i;
  int		j;
  int		size_i;
  int		size_c;

  i = lin - 1;
  j = col - 1;
  size_i = size + i;
  size_c = size + j;
  while (i < size_i)
    {
      i = i + 1;
      if (av[i] == '\0')
	return (0);
      j = col - 1;
      while (j < size_c)
	{
	  j = j + 1;
	  if (av[i][j] != '.')
	    return (0);
	}
    }
  return (1);
}
