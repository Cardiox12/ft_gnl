/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:24:10 by bbellavi          #+#    #+#             */
/*   Updated: 2019/11/01 18:25:21 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static int locate(char *haystack, char needle)
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

static char *resize(char **dst, size_t start)
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

static void	resize_static(char **dst, size_t start)
{
	size_t	dst_len = ft_strlen(&(*dst)[start]);
	size_t	index;
	char	tmp_buffer[dst_len];

	if (*dst)
	{
		index = 0;
		while (index < dst_len)
		{
			tmp_buffer[index] = (*dst)[start + index];
			index++;
		}
		index = 0;
		while (index < dst_len)
		{
			(*dst)[index] = tmp_buffer[index];
			index++;
		}
		(*dst)[index] = '\0';
	}
}

static int	get_line(char **dynamic, char *buffer, char **line)
{
	int	newline_pos;

	if (append(dynamic, buffer) == NULL)
		return (ERROR);
	if ((newline_pos = locate(buffer, NEWLINE)) != NOT_FOUND)
		resize_static(&buffer, newline_pos);
	if ((newline_pos = locate(*dynamic, NEWLINE)) != NOT_FOUND)
	{
		*line = ft_strndup(*dynamic, newline_pos);
		if (resize(dynamic, newline_pos) == NULL || *line == NULL)
			return (ERROR);
		return (SUCCESS);
	}
	return (CONTINUE);
}

int		get_next_line(int fd, char **line)
{
	static char	*dynamic;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;
	int			key_code;

	if (fd == ERROR || line == NULL)
		return (ERROR);
	key_code = get_line(&dynamic, buffer, line);
	while (key_code == CONTINUE)
		key_code = get_line(&dynamic, buffer, line);
	if (key_code == SUCCESS || key_code == ERROR)
		return (ERROR);
	while ((bytes = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[bytes] = '\0';
		if ((key_code = get_line(&dynamic, buffer, line)) == ERROR)
			return (ERROR);
		else if (key_code == SUCCESS)
			return (SUCCESS);
	}
	return (END_OF_FILE);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		char	*line;
		int		code;
		int 	fd = open(argv[1], O_RDONLY);

		line = NULL;
		while ((code = get_next_line(fd, &line)) == SUCCESS)
		{
			printf("LINE : %s\n", line);
			free(line);
			line = NULL;
		}
		free(line);
		line = NULL;
	}
	return (0);
}

// void	__attribute__((destructor))loop(void)
// {
// 	while (1);
// }
