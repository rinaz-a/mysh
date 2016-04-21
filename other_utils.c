/*
** other_utils.c for other_utils in /home/rinaz/rendu/SHELL/PSU_2015_minishell2
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Sun Apr 10 00:52:58 2016 selim rinaz
** Last update Tue Apr 12 11:26:17 2016 selim rinaz
*/

#include <stdlib.h>
#include "mysh.h"

int	tab_lengh_count(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

int	*my_int_tab_maker(int size)
{
  int	*idx;
  int	y;

  y = 0;
  if ((idx = malloc(sizeof(int) * 4)) == NULL)
    exit(1);
  while (y < size)
    idx[y++] = 0;
  return (idx);
}

void	manage_null()
{
  if (isatty(1) == 1)
    my_putstr("\n$> ");
}
