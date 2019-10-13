/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:24:10 by bbellavi          #+#    #+#             */
/*   Updated: 2019/10/13 04:55:42 by bbellavi         ###   ########.fr       */
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

static char *resize(char **dst, size_t start)
{
	char *old_ptr;

	if (*dst == NULL)
		return (NULL);
}

static char	*append(char **dst, const char *src)
{
	char *old_ptr;

	if (*dst == NULL)
		*dst = ft_strdup(src);
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
		if ((newline_pos = locate(dynamic, NEWLINE)) != -1)
			printf("Newline at char : [%i]\n", newline_pos);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		int fd = open(argv[1], O_RDONLY);
		if (fd != -1)
			get_next_line(fd, NULL);
	}
	return (0);
}
