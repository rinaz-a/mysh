/*
** my_strncmp.c for my_strncmp in /home/rinaz/rendu/SHELL/PSU_2015_minishell2
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Tue Mar 29 19:43:50 2016 selim rinaz
** Last update Tue Mar 29 20:24:51 2016 selim rinaz
*/

#include "mysh.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while ((i < n) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
      if (s1[i] != s2[i])
	return (-1);
      i = i + 1;
    }
  if (s2[i] == '=')
    return (2);
  return (0);
}
