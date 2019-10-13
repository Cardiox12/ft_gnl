/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:24:10 by bbellavi          #+#    #+#             */
/*   Updated: 2019/10/14 00:52:05 by bbellavi         ###   ########.fr       */
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
		
		while ((*dst)[start] == NEWLINE && (*dst)[start] != '\0')
			start++;

		*dst = ft_strndup(&(*dst)[start], ft_strlen(&(*dst)[start]));
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

	if (fd == ERROR || line == NULL)
		return (ERROR);
	while ((bytes = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[bytes] = '\0';
		if (append(&dynamic, buffer) == NULL)
			return (ERROR);
		if ((newline_pos = locate(dynamic, NEWLINE)) != -1)
		{
			*line = ft_strndup(dynamic, newline_pos);
			if (resize(&dynamic, newline_pos) == NULL || *line == NULL)
				return (ERROR);
			return (SUCCESS);
		}
	}
	if (append(&dynamic, buffer) == NULL)
		return (ERROR);
	if ((newline_pos = locate(dynamic, NEWLINE)) != -1)
	{
		*line = ft_strndup(dynamic, newline_pos);
		if (resize(&dynamic, newline_pos) == NULL || *line == NULL)
			return (ERROR);
		return (SUCCESS);
	}
	return (END_OF_FILE);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		char	*line;
		int 	fd = open(argv[1], O_RDONLY);
		int		n;

		n = 5;
		line = NULL;
	/*	while (get_next_line(fd, &line) && n-- > 0)
		{
			printf("LINE : %s\n", line);
			free(line);
			line = NULL;
		}
		free(line);
		line = NULL;*/
		get_next_line(fd, NULL);
	}
	return (0);
}

// void	__attribute__((destructor))loop(void)
// {
// 	while (1);
// }
