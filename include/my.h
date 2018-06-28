/*
** my.h for  in /home/robin/delivery/CPool_Day09/include
** 
** Made by Robin Pronnier
** Login   <robin@epitech.net>
** 
** Started on  Thu Oct 13 11:53:32 2016 Robin Pronnier
** Last update Wed Dec 14 20:57:29 2016 Robin Pronnier
*/

#ifndef MY_H_
# define MY_H_

# include <stdarg.h>
# include <sys/stat.h>
# include "struct.h"

void	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
int	my_recup(struct stat *sa, char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	my_transfo(char *str, int k, int col, int lin);
int	fill_square(char **av, int lin, int col, int size);
int	find_square(char **av, int lin, int col, int size);
int	appel(char **av, struct s_bsq infos);
int	my_show_tab(char **av);
int	nb_colums(char **str);
int	nb_lines(char *str);
int	stct(char **av, struct s_bsq *nom);
int	err1(char *str);
int	err2(char *str);
int	err3(char *str, int i, int len, int len_up);
int	err4(char *str);

#endif /* !MY_H_ */
