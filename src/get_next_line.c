/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 01:05:41 by mnidoque          #+#    #+#             */
/*   Updated: 2019/09/30 17:22:14 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	finish(char **static_line, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*static_line)[i] != EOL_SYMB && (*static_line)[i] != EOF_SYMB)
		i++;
	if ((*static_line)[i] == EOL_SYMB)
	{
		*line = ft_strsub(*static_line, 0, i);
		tmp = ft_strdup(&((*static_line)[i + 1]));
		free(*static_line);
		*static_line = tmp;
		if ((*static_line)[0] == EOF_SYMB)
			ft_strdel(static_line);
	}
	else
	{
		*line = ft_strdup(*static_line);
		ft_strdel(static_line);
	}
	return (1);
}

static int	check_line(char **static_line, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && static_line[fd] == NULL)
		return (0);
	else
		return (finish(&static_line[fd], line));
}

static int	start_read(char **static_line, char **line, int ret, int fd)
{
	char	*tmp;
	char	buff[BUFF_SIZE + 1];

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = EOF_SYMB;
		if (static_line[fd] == NULL)
			static_line[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(static_line[fd], buff);
			free(static_line[fd]);
			static_line[fd] = tmp;
		}
		if (ft_strchr(static_line[fd], EOL_SYMB))
			break ;
	}
	return (check_line(static_line, line, ret, fd));
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*static_line[LINE_SIZE];

	ret = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	return (start_read(static_line, line, ret, fd));
}
