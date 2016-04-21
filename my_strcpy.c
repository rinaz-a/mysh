/*
** my_strcpy.c for my_strcpy in /home/rinaz/rendu/SHELL/PSU_2015_minishell2
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Fri Apr  1 12:34:26 2016 selim rinaz
** Last update Fri Apr  1 12:53:47 2016 selim rinaz
*/

#include <stdlib.h>
#include "mysh.h"

char	*my_strcpy(char *src, char *dest)
{
  int	i;

  i = 0;
  if (src == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  src[i] = '\0';
  return (dest);
}
