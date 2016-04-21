/*
** mysh.h for mysh in /home/rinaz_a/rendu/PSU_2015_minishell1
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Fri Jan 22 14:56:47 2016 selim rinaz
** Last update Wed Apr 13 20:59:22 2016 selim rinaz
*/

#ifndef MYSH_H_
# define MYSH_H_

# ifndef READ_SIZE
#  define READ_SIZE (800)
# endif /* !READ_SIZE */

#include <unistd.h>

typedef struct	s_data
{
  char		buf[READ_SIZE];
  int		idx;
  int		ret;
}		t_data;

typedef struct	s_tmp
{
  char		*line;
  int		kill;
  int		pos;
}		t_tmp;

typedef struct	s_shell
{
  char		**arg;
  char		**sep;
  char		**path;
  pid_t		CHpid;
  int		status;
}		t_shell;

typedef struct	s_add_an_env
{
  char		**env;
  int		*idx;
  int		fail;
}		t_add_an_env;

char		*my_epur_str(char *str);
int		my_getnbr(char *str);
char		*my_strcpy(char *src, char *dest);
void		my_putstr_2d(char **str);
int		my_strncmp(char *s1, char *s2, int n);
int		my_strcmp(char *s1, char *s2);
char		*get_next_line(const int fd);
char		*alloc(int idx, int pos, char *buf, char *line);
int		my_strlen(char *str);
void		my_putchar(char c);
void		my_putstr(char *str);
void		my_puterr(char *str);
int		my_wordlen(char *str, int pos, char delim);
int		word_counter(char *str, char delim);
char		**str_to_wordtab(char *str, char delim);
char		*my_getenv(char **env, char *element);
int		*my_int_tab_maker(int size);
char		*my_strcat(char *dest, char *src);
void		manage_file(t_shell *in, char **env, char *file);
char		*mod_my_env(char *bas_env, char *to_put_in);
int		tab_lengh_count(char **tab);
t_add_an_env	fill_new_env(t_add_an_env all, char *fill_this, char *with_this);
t_add_an_env	fill_new_env2(t_add_an_env all, char *fill_this, char *with_this);
char		**add_an_env(char **env, char *fill_this, char *with_this);
void		manage_null();
char		**my_cd_home(char **env);
char		**my_cd_back(char **env);
char		**my_cd_basic(t_shell in, char **env);
char		**my_cd(t_shell in, char **env);
char		**my_setenv(t_shell in, char **env);
char		**my_unsetenv(t_shell in, char **env);
char		**manage_bulletins(t_shell in, char **env, char *func);
int		mysh(char **env);
int		my_exec(t_shell *in, char **env);
int		main(int ac, char **av, char **env);

#endif /* !MYSH_H_ */
