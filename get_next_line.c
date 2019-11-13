/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:24:10 by bbellavi          #+#    #+#             */
/*   Updated: 2019/11/08 17:11:03 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

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

static int	get_line(char **dynamic, char *buffer, char **line)
{
	int		newline_pos;
	size_t	index;

	if (append(dynamic, buffer) == NULL)
		return (ERROR);
	if ((newline_pos = locate(buffer, NEWLINE)) != NOT_FOUND)
	{
		index = 0;
		while (index < BUFFER_SIZE)
		{
			buffer[index] = '\0';
			index++;
		}
	}
	if ((newline_pos = locate(*dynamic, NEWLINE)) != NOT_FOUND)
	{
		*line = ft_strndup(*dynamic, newline_pos);
		if (resize(dynamic, newline_pos) == NULL || *line == NULL)
			return (ERROR);
		return (SUCCESS);
	}
	return (END_OF_FILE);
}

int		get_next_line(int fd, char **line)
{
	static char	*dynamic;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;
	int			key_code;

	if ((read(fd, buffer, 0)) == ERROR || fd == ERROR || line == NULL)
		return (ERROR);
	while ((bytes = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[bytes] = '\0';
		if ((key_code = get_line(&dynamic, buffer, line)) == ERROR || key_code == SUCCESS)
			return (key_code);
	}
	key_code = get_line(&dynamic, buffer, line);
	if (key_code == SUCCESS || key_code == ERROR)
		return (key_code);
	return (END_OF_FILE);
}

// int		main(int argc, char **argv)
// {
// 	if (argc > 1)
// 	{
// 		size_t	nb_line;
// 		char	*line;
// 		int		code;
// 		int 	fd = open(argv[1], O_RDONLY);

// 		line = NULL;
// 		nb_line = 1;
// 		while ((code = get_next_line(fd, &line)) == SUCCESS)
// 		{
// 			printf("%zu : %s\n", nb_line, line);
// 			nb_line++;
// 			free(line);
// 			line = NULL;
// 		}
// 		free(line);
// 		line = NULL;
// 	}
// 	return (0);
// }
int		main(int argc, char **argv)
{
	if (argc)
	{
		size_t	nb_line;
		char	*line;
		int		code;
		int 	fd = (argc == 1) ? 0 : open(argv[1], O_RDONLY);

		line = NULL;
		nb_line = 1;
		while ((code = get_next_line(fd, &line)) == SUCCESS)
		{
			printf("%zu : %s\n", nb_line, line);
			nb_line++;
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

