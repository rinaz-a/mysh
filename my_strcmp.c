/*
** my_strcmp.c for my_strcmp in /home/rinaz/rendu/SHELL/PSU_2015_minishell2
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Mon Mar 28 20:48:32 2016 selim rinaz
** Last update Mon Mar 28 20:54:17 2016 selim rinaz
*/

#include "mysh.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (-1);
      i++;
    }
  if (s1[i] != '\0' || s2[i] != '\0')
    return (-1);
  return (1);
}
