/*
** my_strcat.c for my_strcat in /home/rinaz/rendu/SHELL/PSU_2015_minishell2
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Sun Apr 10 00:44:30 2016 selim rinaz
** Last update Sun Apr 10 00:44:57 2016 selim rinaz
*/

#include "mysh.h"

char	*my_strcat(char *dest, char *src)
{
  int	x;
  int	z;

  z = 0;
  x = 0;
  while (dest[x] != '\0')
    x = x + 1;
  while (src[z] != '\0')
    {
      dest[x] = src[z];
      z = z + 1;
      x = x + 1;
    }
  dest[x] = '\0';
  return (dest);
}
