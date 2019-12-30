#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H
# define FD_MAX		(2048)
# define ENDLINE	('\n')
# define NULL_BYTE	('\0')
# define SUCCESS	(1)
# define EOFILE		(0)
# define ERROR		(-1)

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int     ft_strlen(char *s);
char    *ft_strdup(char *s);
char    *ft_strjoin_free(char *s1, char *s2);
char    *ft_strchr(char *s, int c);

#endif
