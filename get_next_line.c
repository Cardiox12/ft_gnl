/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:24:10 by bbellavi          #+#    #+#             */
/*   Updated: 2019/10/13 04:17:28 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
	

int		get_next_line(int fd, char **line)
{
	static char	*dynamic;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;
	(void)line;

	while ((bytes = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[bytes] = '\0';
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
