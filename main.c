/*
** main.c for  in /home/robin/delivery/CPE_2016_BSQ
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Mon Dec  5 13:42:47 2016 Robin Pronnier
** Last update Thu Dec 15 13:48:13 2016 Robin Pronnier
*/

#include <sys/stat.h>
#include <stdlib.h>
#include "my.h"

int		main(int ac, char **av)
{
  struct stat	sa;

  if (ac == 2)
    {
      if ((my_recup(&sa, av[1])) == 84)
	return (84);
    }
  else
    return (84);
  return (0);
}
