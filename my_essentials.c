/*
** my_essentials.c for my_essentials in /home/rinaz_a/rendu/PSU_2015_my_select
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Tue Dec  8 16:22:05 2015 selim rinaz
** Last update Fri Apr  8 18:22:23 2016 selim rinaz
*/

#include <unistd.h>
#include "mysh.h"

int	my_strlen(char *str)
{
  int	idx;

  idx = 0;
  while (str[idx] != '\0')
    idx = idx + 1;
  return (idx);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	my_puterr(char *str)
{
  write(2, str, my_strlen(str));
}

void	my_putstr_2d(char **str)
{
  int	y;

  y = 0;
  while (str[y] != NULL)
    {
      if (str[y][0] != '\0')
	{
	  write(1, str[y], my_strlen(str[y]));
	  write(1, "\n", 1);
	}
      y = y + 1;
    }
}
