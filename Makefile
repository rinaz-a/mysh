##
## Makefile for Makefile in /home/rinaz_a/rendu/PSU_2015_my_select
## 
## Made by selim rinaz
## Login   <rinaz_a@epitech.net>
## 
## Started on  Fri Dec  4 16:34:29 2015 selim rinaz
## Last update Sun Apr 10 23:05:40 2016 selim rinaz
##

CC	= gcc -g -g3

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
#CFLAGS	+= -ansi -pedantic
#CFLAGS	+= -I.

NAME	= mysh

SRCS	= my_essentials.c	\
	  get_next_line.c	\
	  str_to_wordtab.c	\
	  my_strcmp.c		\
	  my_getnbr.c		\
	  my_strcpy.c		\
	  my_strcat.c		\
	  my_strncmp.c		\
	  manage_env.c		\
	  my_cd.c		\
	  my_exec.c		\
	  my_get_env.c		\
	  my_setenv.c		\
	  other_utils.c		\
	  mysh.c

OBJS	= $(SRCS:.c=.o)


all:	 $(NAME)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS)

clean:
	 $(RM) $(OBJS)

fclean:  clean
	 $(RM) $(NAME)

re:	 fclean all

.PHONY:	 all clean fclean re
