/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:50:51 by bbellavi          #+#    #+#             */
/*   Updated: 2019/11/27 16:56:52 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int     main(int argc, char **argv)
{
	int     index;
	char    *line;
	int     retour;
	int		fd;

	index = 0;
	if (argc == 1)
		while (get_next_line(0, &line) != 0)
			printf("line : %s\n", line);
	else 
	{
		while (argc-- != 1)
		{
			fd = open(*++argv, O_RDONLY);
			while ((retour = get_next_line(fd, &line)) > 0)
				printf("line (%i): %s\n", retour, line);
			printf("line (%i): %s\n", retour, line);
		}
	}
}
