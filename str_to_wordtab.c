/*
** str_to_wordtab.c for str_to_wordtab in /home/rinaz_a/rendu/PSU_2015_minishell1
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Wed Jan 20 17:30:10 2016 selim rinaz
** Last update Tue Apr 12 19:10:32 2016 selim rinaz
*/

#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"

char	*my_epur_str(char *str)
{
  int	idx[2];

  idx[0] = 0;
  idx[1] = 0;
  while ((str[idx[0]] == ' ') || (str[idx[0]] == '\t'))
    idx[0]++;
  while (str[idx[0]] != '\0')
    {
      if ((str[idx[0]] != ' ') && (str[idx[0]] != '\t'))
	str[idx[1]++] = str[idx[0]];
      if ((str[idx[0] + 1] == ' ') || (str[idx[0] + 1] == '\t'))
	{
	  while ((str[idx[0] + 1] == ' ') || (str[idx[0] + 1] == '\t'))
	    idx[0]++;
	  str[idx[1]++] = ' ';
	}
      idx[0] = idx[0] + 1;
    }
  str[idx[1]] = '\0';
  if (idx[1] > 0 && str[idx[1] - 1] == ' ')
    str[idx[1] - 1] = '\0';
  return (str);
}

int	my_wordlen(char *str, int pos, char delim)
{
  int	idx;

  idx = 0;
  while (str[pos] != delim && str[pos] != '\0')
    {
      pos = pos + 1;
      idx = idx + 1;
    }
  return (idx);
}

int	word_counter(char *str, char delim)
{
  int	count;
  int	i;

  i = 0;
  count = 0;
  if ((str[0] != '\0') && (str[0] != delim))
    count = count + 1;
  while (str[i++] != '\0')
    if (str[i - 1] == delim && str[i] != delim)
      count = count + 1;
  return (count);
}

char	**str_to_word_cpy(char *str, char delim, int idx[3], char **wordtab)
{
  while (str[idx[1]] != '\0')
    {
      if (str[idx[1]] != delim && str[idx[1]] != '\0')
	{
	  if ((wordtab[idx[2]]
	       = malloc(sizeof(char)
			* ((my_wordlen(str, idx[1], delim)) + 1))) == NULL)
	    return (NULL);
	  while (str[idx[1]] != delim && str[idx[1]] != '\0')
	    {
	      wordtab[idx[2]][idx[0]] = str[idx[1]];
	      idx[1] = idx[1] + 1;
	      idx[0] = idx[0] + 1;
	    }
	  wordtab[idx[2]++][idx[0]] = '\0';
	  idx[0] = 0;
	}
      else
	idx[1] = idx[1] + 1;
    }
  return (wordtab);
}

char	**str_to_wordtab(char *str, char delim)
{
  char	**wordtab;
  int	idx[3];

  idx[0] = 0;
  idx[1] = 0;
  idx[2] = 0;
  if (str == NULL)
    return (NULL);
  if ((wordtab = (malloc(sizeof(char *)
			 * ((word_counter(str, delim)) + 1)))) == NULL)
    return (NULL);
  return (wordtab = str_to_word_cpy(str, delim, idx, wordtab));
}
