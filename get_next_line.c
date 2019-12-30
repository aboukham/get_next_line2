#include "get_next_line.h"

int		save_line(char **rest, char **line, char *pos)
{
	char	*tmp;

	if (pos)
	{
		*pos = NULL_BYTE;	
		*line = ft_strdup(*rest);
		tmp = *rest;
		*rest = *(pos + 1) ? ft_strdup(pos + 1) : NULL;
		free(tmp);
		tmp = NULL;
		return (SUCCESS);
	}
	else if (**rest)
	{
		*line = ft_strdup(*rest);
		free(*rest);	
		*rest = NULL;
		return (SUCCESS);
	}
	return (EOFILE);
}

int		get_line(int fd, char **rest, char **line)
{
	char	buff[BUFF_SIZE + 1];
	int		r;
	char	*pos;

	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = NULL_BYTE;
		*rest = ft_strjoin_free(*rest, buff);
		if ((pos = ft_strchr(*rest, ENDLINE)))
		{
			save_line(rest, line, pos);
			return (SUCCESS);
		}
	}
	if (r == 0 && *rest)
		r = save_line(rest, line, ft_strchr(*rest, ENDLINE));
	return (r);
}

int		get_next_line(int fd, char **line)
{
	static char	*rest[FD_MAX];
	char		*pos;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (ERROR);
	if (rest[fd] != NULL && (pos = ft_strchr(rest[fd], ENDLINE)))
	{
		save_line(&rest[fd], line, pos);
		return (SUCCESS);
	}
	return (get_line(fd, &rest[fd], line));
}
