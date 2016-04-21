/*
** my_setenv.c for my_setenv in /home/rinaz/rendu/SHELL/PSU_2015_minishell2
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Sun Apr 10 00:54:36 2016 selim rinaz
** Last update Mon Apr 11 17:44:39 2016 selim rinaz
*/

#include "mysh.h"

char	**my_setenv(t_shell in, char **env)
{
  int	idx;

  idx = 0;
  if (in.arg[1] == NULL)
    my_putstr_2d(env);
  else if ((in.arg[1][0] >= 65 && in.arg[1][0] <= 90)
	   || (in.arg[1][0] >= 97 && in.arg[1][0] <= 122))
    {
      while ((env[idx] != NULL) && (in.arg[1] != NULL)
	     && my_strncmp(in.arg[1], env[idx], my_strlen(in.arg[1])) != 2)
	idx++;
      if ((env[idx] != NULL) && (in.arg[1] != NULL)
	  && my_strncmp(in.arg[1], env[idx], my_strlen(in.arg[1])) == 2)
	{
	  if ((env[idx] = mod_my_env(env[idx], in.arg[2])) == NULL)
	    return (NULL);
	}
      else if ((env != NULL) && (in.arg[1] != NULL))
	if ((env = add_an_env(env, in.arg[1], in.arg[2])) == NULL)
	  return (NULL);
      idx = 0;
    }
  else
    my_puterr("setenv: Variable name must begin with a letter.\n");
  return (env);
}

char	**my_unsetenv(t_shell in, char **env)
{
  int	x;
  int	idx;

  idx = 0;
  x = 1;
  if (in.arg[1] == NULL)
    my_puterr("unsetenv: Too few arguments.\n");
  while (in.arg[x] != NULL)
    {
      while ((env[idx] != NULL) && (in.arg[x] != NULL)
	     && my_strncmp(in.arg[x], env[idx], my_strlen(in.arg[x])) != 2)
	idx++;
      if ((env[idx] != NULL) && (in.arg[x] != NULL)
	  && my_strncmp(in.arg[x], env[idx], my_strlen(in.arg[x])) == 2)
	env[idx][0] = '\0';
      idx = 0;
      x++;
    }
  return (env);
}
