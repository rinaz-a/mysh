/*
** manage_env.c for manage_env in /home/rinaz/rendu/SHELL/PSU_2015_minishell2
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Sun Apr 10 00:46:54 2016 selim rinaz
** Last update Mon Apr 11 18:00:17 2016 selim rinaz
*/

#include <stdlib.h>
#include "mysh.h"

t_add_an_env	fill_new_env(t_add_an_env all, char *fill_this, char *with_this)
{
  if (with_this != NULL)
    {
      if ((all.env[all.idx[0]] = malloc(my_strlen(fill_this)
					+ my_strlen(with_this) + 2)) == NULL)
	{
	  all.fail = 1;
	  return (all);
	}
      while (fill_this[all.idx[2]] != '\0')
	{
	  all.env[all.idx[0]][all.idx[2]] = fill_this[all.idx[2]];
	  all.idx[2]++;
	}
      all.env[all.idx[0]][all.idx[2]++] = '=';
      while (with_this[all.idx[1]] != '\0')
	all.env[all.idx[0]][all.idx[2]++] = with_this[all.idx[1]++];
    }
  return (all);
}

t_add_an_env	fill_new_env2(t_add_an_env all, char *fill_this, char *with_this)
{
  if (with_this == NULL)
    {
      if ((all.env[all.idx[0]] = malloc(my_strlen(fill_this) + 2)) == NULL)
	{
	  all.fail = 1;
	  return (all);
	}
      while (fill_this[all.idx[2]] != '\0')
	{
	  all.env[all.idx[0]][all.idx[2]] = fill_this[all.idx[2]];
	  all.idx[2]++;
	}
      all.env[all.idx[0]][all.idx[2]++] = '=';
    }
  return (all);
}

char		**add_an_env(char **env, char *fill_this, char *with_this)
{
  t_add_an_env	all;

  all.idx = my_int_tab_maker(3);
  if ((all.env = malloc(sizeof(char *) * (tab_lengh_count(env) + 1))) == NULL)
    return (NULL);
  while (env[all.idx[0]] != NULL)
    {
      if ((all.env[all.idx[0]] = malloc(my_strlen(env[all.idx[0]]) + 1))
	  == NULL)
	return (NULL);
      all.env[all.idx[0]] = my_strcpy(env[all.idx[0]], all.env[all.idx[0]]);
      all.idx[0]++;
    }
  all = fill_new_env(all, fill_this, with_this);
  all = fill_new_env2(all, fill_this, with_this);
  if (all.fail == 1)
    return (NULL);
  all.env[all.idx[0]++][all.idx[2]] = '\0';
  all.env[all.idx[0]] = NULL;
  return (all.env);
}

char	*mod_my_env(char *bas_env, char *to_put_in)
{
  char	*env_mod;
  int	i;
  int	y;

  y = 0;
  i = 0;
  if (to_put_in != NULL)
    if ((env_mod = malloc(my_strlen(bas_env)
			  + my_strlen(to_put_in) + 2)) == NULL)
      exit(1);
  if (to_put_in == NULL)
    if ((env_mod = malloc(my_strlen(bas_env) + 2)) == NULL)
      exit(1);
  while (bas_env[i] != '=')
    {
      env_mod[i] = bas_env[i];
      i++;
    }
  env_mod[i] = '=';
  i++;
  if (to_put_in != NULL)
    while (to_put_in[y] != '\0')
      env_mod[i++] = to_put_in[y++];
  env_mod[i] = '\0';
  return (env_mod);
}
