/*
** my_exec.c for my_exec in /home/rinaz/rendu/SHELL/PSU_2015_minishell2
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Sun Apr 10 00:45:19 2016 selim rinaz
** Last update Tue Apr 12 19:08:14 2016 selim rinaz
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "mysh.h"

void	manage_file(t_shell *in, char **env, char *file)
{
  if ((access(file, X_OK) != -1) && ((in->CHpid = fork()) != -1))
    {
      if ((in->CHpid == 0) && ((execve(file, in->arg, env)) != -1))
	exit(1);
    }
  else
    {
      my_puterr("mysh: command not found: ");
      my_puterr(in->arg[0]);
      my_puterr("\n");
    }
  waitpid(in->CHpid, &in->status, 0);
  if (WTERMSIG(in->status) == SIGSEGV)
    my_puterr("Segmentation fault\n");
}

int	my_exec(t_shell *in, char **env)
{
  char	*file;
  int	idx;

  idx = 0;
  in->status = 0;
  in->CHpid = -1;
  file = NULL;
  if ((in->arg[0][0] != '/') && (in->arg[0][0] != '.')
      && (my_getenv(env, "PATH") != NULL))
    while ((in->path[idx] != NULL) && (in->CHpid != 0)
	   && (access(file, X_OK) == -1))
      {
	if ((in->arg[0] == NULL)
	    || ((file = malloc((my_strlen(in->path[idx]))
			       + (my_strlen(in->arg[0])) + 2)) == NULL))
	  return (-1);
	file = my_strcat(file, in->path[idx]);
	file = my_strcat(file, "/");
	file = my_strcat(file, in->arg[0]);
	idx++;
      }
  else
    file = in->arg[0];
  manage_file(in, env, file);
  return (0);
}

