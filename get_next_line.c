/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:24:10 by bbellavi          #+#    #+#             */
/*   Updated: 2019/10/21 20:56:40 by bbellavi         ###   ########.fr       */
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

/*
** GET_LINE
** The get line function append a file chunk to the buffer previously passed in parameter, 
** store it in line and resize dynamic if NEWLINE has been found in the chunk. 
**
** :param dynamic: the dynamic buffer previously allocated
** 
** get_line :
*/

static int	get_line(char **dynamic, char *buffer, char **line)
{
	int	newline_pos;

	if (append(dynamic, buffer) == NULL)
		return (ERROR);
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
	while ((bytes = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[bytes] = '\0';
		if ((key_code = get_line(&dynamic, buffer, line)) == ERROR)
			return (ERROR);
		else if (key_code == SUCCESS)
			return (SUCCESS);
	}
	if ((key_code = get_line(&dynamic, buffer, line)) != CONTINUE)
		return (key_code);
	return (END_OF_FILE);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		char	*line;
		int 	fd = open(argv[1], O_RDONLY);

		line = NULL;
		while (get_next_line(fd, &line))
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
