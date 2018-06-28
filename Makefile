##
## Makefile for  in /home/robin/delivery/CPool_Day10
## 
## Made by Robin Pronnier
## Login   <robin@epitech.net>
## 
## Started on  Fri Oct 14 08:41:52 2016 Robin Pronnier
## Last update Tue Dec 13 19:38:44 2016 Robin Pronnier
##

CC	= gcc -g

RM	= rm -f

NAME	= bsq

CFLAGS	+= -I./include

SRCS	= base.c \
	  main.c \
	  functions.c \
	  numbers.c \
	  algo.c \
	  errors.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
