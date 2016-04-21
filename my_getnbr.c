/*
** my_getnbr.c for my_getnbr in /home/rinaz_a/rendu/Piscine_C_J07/lib/my
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Tue Oct  6 11:10:42 2015 selim rinaz
** Last update Wed Apr  6 10:58:07 2016 selim rinaz
*/

#include "mysh.h"

int	my_getnbr(char *str)
{
  int	a;
  int	res;
  int	x;

  res = 0;
  a = 0;
  x = 0;
  while (str[a] < '0' || str[a] > '9')
    a = a + 1;
  while (str[a])
    {
      res = res * 10 + (str[a] - 48);
      a = a + 1;
      x = x + 1;
    }
  if (str[0] == '-')
    return (-res);
  return (res);
}
