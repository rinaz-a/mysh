/*
** my_cd.c for my_cd in /home/rinaz/rendu/SHELL/PSU_2015_minishell2
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Sun Apr 10 00:53:36 2016 selim rinaz
** Last update Mon Apr 11 17:26:50 2016 selim rinaz
*/

#include <stdlib.h>
#include "mysh.h"

char	**my_cd_home(char **env)
{
  int	idx;

  idx = 0;
  if ((chdir(my_getenv(env, "HOME"))) == -1)
    {
      my_puterr("cd: no file or directory: ");
      if (my_getenv(env, "HOME") != NULL)
	my_puterr(my_getenv(env, "HOME"));
      my_puterr("\n");
      return (env);
    }
  while ((env[idx] != NULL) && my_strncmp("OLDPWD", env[idx], 6) != 2)
    idx++;
  if ((env[idx] != NULL) && my_strncmp("OLDPWD", env[idx], 6) == 2)
    env[idx] = mod_my_env(env[idx], my_getenv(env, "PWD"));
  idx = 0;
  while ((env[idx] != NULL) && (my_strncmp("PWD", env[idx], 3) != 2))
    idx++;
  if ((env[idx] != NULL) && (my_strncmp("PWD", env[idx], 3) == 2))
    env[idx] = mod_my_env(env[idx], my_getenv(env, "HOME"));
  return (env);
}

char	**my_cd_back(char **env)
{
  int	idx;
  char	*savepwd;

  idx = 0;
  if ((savepwd = malloc(sizeof(my_getenv(env, "PWD")) + 1)) == NULL)
    exit(1);
  savepwd = my_getenv(env, "PWD");
  if ((chdir(my_getenv(env, "OLDPWD"))) == -1)
    {
      my_puterr("cd: no file or directory: ");
      if (my_getenv(env, "OLDPWD") != NULL)
	my_puterr(my_getenv(env, "OLDPWD"));
      my_puterr("\n");
      return (env);
    }
  while ((env[idx] != NULL) && (my_strncmp("PWD", env[idx], 3) != 2))
    idx++;
  if ((env[idx] != NULL) && (my_strncmp("PWD", env[idx], 3) == 2))
    env[idx] = mod_my_env(env[idx], my_getenv(env, "OLDPWD"));
  idx = 0;
  while ((env[idx] != NULL) && (my_strncmp("OLDPWD", env[idx], 6) != 2))
    idx++;
  if ((env[idx] != NULL) && (my_strncmp("OLDPWD", env[idx], 6) == 2))
    env[idx] = mod_my_env(env[idx], savepwd);
  return (env);
}

char	**my_cd_basic(t_shell in, char **env)
{
  int	idx;

  idx = 0;
  if ((chdir(in.arg[1])) == -1)
    {
      my_puterr("cd: no file or directory: ");
      my_puterr(in.arg[1]);
      my_puterr("\n");
      return (env);
    }
  while ((env[idx] != NULL) && my_strncmp("OLDPWD", env[idx], 6) != 2)
    idx++;
  if ((env[idx] != NULL) && my_strncmp("OLDPWD", env[idx], 6) == 2)
    env[idx] = mod_my_env(env[idx], my_getenv(env, "PWD"));
  idx = 0;
  while ((env[idx] != NULL) && my_strncmp("PWD", env[idx], 3) != 2)
    idx++;
  if ((env[idx] != NULL) && my_strncmp("PWD", env[idx], 3) == 2)
    env[idx] = mod_my_env(env[idx], in.arg[1]);
  return (env);
}

char	**my_cd(t_shell in, char **env)
{
  if (in.arg[1] == NULL)
    env = my_cd_home(env);
  else if ((in.arg[1] == NULL) || (my_strcmp(in.arg[1], "-") == 1))
    env = my_cd_back(env);
  else if (in.arg[1] != NULL)
    env = my_cd_basic(in, env);
  return (env);
}

