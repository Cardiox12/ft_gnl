/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:24:10 by bbellavi          #+#    #+#             */
/*   Updated: 2019/11/28 17:59:08 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

static int	locate(char *haystack, char needle)
{
	int index;

	index = 0;
	while (haystack[index])
	{
		if (haystack[index] == needle)
			return (index);
		index++;
	}
	return (-1);
}

static char	*append(char **dst, const char *src)
{
	char *old_ptr;

	if (*dst == NULL)
		*dst = ft_strndup(src, ft_strlen(src));
	else
	{
		old_ptr = *dst;
		*dst = ft_strjoin(*dst, src);
		if (*dst == NULL)
			return (NULL);
		free(old_ptr);
	}
	return (*dst);
}

static char	*resize(char **dst, size_t start)
{
	char *old_ptr;

	if (*dst)
	{
		old_ptr = *dst;
		if ((*dst)[start] != '\0' && (*dst)[start] == NEWLINE)
			start++;
		*dst = ft_strndup(&(*dst)[start], ft_strlen(&(*dst)[start]));
		if (*dst == NULL)
			return (NULL);
		free(old_ptr);
	}
	return (*dst);
}

static int	get_line(t_buf *buf, char **line)
{
	int		newline_pos;

	if (append(&buf->dynamic, buf->buffer) == NULL)
		return (ERROR);
	if ((newline_pos = locate(buf->buffer, NEWLINE)) != NOT_FOUND)
		buf->buffer[0] = '\0';
	if ((newline_pos = locate(buf->dynamic, NEWLINE)) != NOT_FOUND)
	{
		*line = ft_strndup(buf->dynamic, newline_pos);
		if (resize(&buf->dynamic, newline_pos) == NULL || *line == NULL)
			return (ERROR);
		return (SUCCESS);
	}
	return (END_OF_FILE);
}

int			get_next_line(int fd, char **line)
{
	static t_buf	*first = NULL;
	t_buf			*buf;
	int				bytes;
	int				key_code;

	if ((buf = manage_buffer(&first, fd)) == NULL)
		return (ERROR);
	if ((read(fd, buf->buffer, 0)) == ERROR || fd == ERROR || line == NULL)
		return (ERROR);
	while ((bytes = read(buf->fd, buf->buffer, BUFFER_SIZE)))
	{
		buf->buffer[bytes] = '\0';
		if ((key_code = get_line(buf, line)) == ERROR || key_code == SUCCESS)
			return (key_code);
	}
	buf->buffer[bytes] = '\0';
	if ((key_code = get_line(buf, line)) == SUCCESS || key_code == ERROR)
		return (key_code);
	if ((*line = ft_strndup(buf->dynamic, ft_strlen(buf->dynamic))) == NULL)
		return (ERROR);
	resize(&buf->dynamic, ft_strlen(buf->dynamic));
	free(first);
	return (END_OF_FILE);
}
