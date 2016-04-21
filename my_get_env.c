/*
** my_get_env.c for my_get_env in /home/rinaz/rendu/SHELL/PSU_2015_minishell2
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Sun Apr 10 00:43:21 2016 selim rinaz
** Last update Mon Apr 11 17:26:25 2016 selim rinaz
*/

#include <stdlib.h>
#include "mysh.h"

char	*my_getenv(char **env, char *element)
{
  int	*idx;
  char	*getenv;

  idx = my_int_tab_maker(4);
  while (env[idx[0]] != NULL)
    {
      idx[2] = 0;
      while ((env[idx[0]][idx[1]] != '\0') && (env[idx[0]] != NULL)
	     && (my_strncmp(element, env[idx[0]], my_strlen(element)) == 2))
	{
	  if ((env[idx[0]][idx[1]] == '=') && (idx[1]++))
	    {
	      if ((getenv = malloc(my_wordlen(env[idx[0]], idx[1], '\0')))
		  == NULL)
		exit(1);
              while (env[idx[0]][idx[1]] != '\0' && env[idx[0]][idx[1]])
		(getenv[idx[3]++] = env[idx[0]][idx[1]++]) && (getenv[idx[3]] = '\0');
	      return (getenv);
	    }
	  idx[1] = idx[1] + 1;
	  idx[2] = idx[2] + 1;
	}
      idx[0]++;
    }
  return (NULL);
}

