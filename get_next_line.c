/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:24:10 by bbellavi          #+#    #+#             */
/*   Updated: 2019/10/13 22:04:11 by bbellavi         ###   ########.fr       */
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

//static char *resize(char **dst, size_t start)
//{
//	char *old_ptr;
//
//	if (*dst == NULL)
//		return (NULL);
//}

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
		*dst = ft_strndup(&old_ptr[start], ft_strlen(&old_ptr[start]));
		if (*dst == NULL)
			return (NULL);
		free(old_ptr);
	}
	return (*dst);
}

int		get_next_line(int fd, char **line)
{
	static char	*dynamic;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;
	int			newline_pos;
	(void)line;

	while ((bytes = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[bytes] = '\0';
		append(&dynamic, buffer);
		if ((newline_pos = locate(dynamic, NEWLINE)))
		{
			*line = ft_strndup(dynamic, newline_pos);
			resize(&dynamic, newline_pos);
			return (1);
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		int 	fd = open(argv[1], O_RDONLY);
		char	*line;

		if (fd != -1)
			get_next_line(fd, &line);
	}
	return (0);
}
