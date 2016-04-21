/*
** my_sh.c for my_sh in /home/rinaz_a/rendu/PSU_2015_minishell1
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Wed Jan 20 16:16:30 2016 selim rinaz
** Last update Wed Apr 13 21:11:36 2016 selim rinaz
*/

#include <signal.h>
#include <stdlib.h>
#include "mysh.h"

char	**manage_bulletins(t_shell in, char **env, char *func)
{
  if (my_strcmp(in.arg[0], "env") == 1)
    my_putstr_2d(env);
  else if (my_strcmp(in.arg[0], "setenv") == 1)
    {
      if ((env = my_setenv(in, env)) == NULL)
	return (NULL);
    }
  else if (my_strcmp(in.arg[0], "unsetenv") == 1)
    env = my_unsetenv(in, env);
  else if (my_strcmp(in.arg[0], "cd") == 1)
    env = my_cd(in, env);
  else if (my_strcmp(in.arg[0], "exit") == 1)
    if (in.arg[1] == NULL)
      exit(0);
    else
      exit(my_getnbr(in.arg[1]));
  else if ((func[0] != '\n') || (in.arg[0][0] == '/') || (in.arg[0][0] == '.'))
    my_exec(&in, env);
  return (env);
}

int		mysh(char **env)
{
  t_shell	in;
  char		*func;
  int		i;

  while (42)
    {
      if (isatty(1) == 1)
	my_putstr("$> ");
      if ((func = get_next_line(0)) == NULL)
	{
	  my_puterr("exit\n");
	  exit(1);
	}
      i = -1;
      in.sep = str_to_wordtab(my_epur_str(func), ';');
      while (in.sep[++i] != NULL)
	{
	  in.arg = str_to_wordtab(my_epur_str(in.sep[i]), ' ');
	  if (env != NULL && in.arg[0] != NULL && in.arg[0][0] != '\0')
	    {
	      in.path = str_to_wordtab(my_getenv(env, "PATH"), ':');
	      env = manage_bulletins(in, env, in.sep[i]);
	    }
	}
    }
}

int		main(int ac, char **av, char **env)
{
  signal(SIGINT, &manage_null);
  if (ac > 1)
    {
      my_puterr("mysh : can't imput file ");
      my_puterr(av[1]);
      my_puterr("\n");
      return (0);
    }
  mysh(env);
  return (0);
}
