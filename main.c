#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char *line;
	int fd;

	if (argc == 1)
	{
		while (get_next_line(0, &line) > 0)
			printf("line : %s\n", line);
		printf("line : %s\n", line);
	}
	else
	{
		fd = open(*++argv, O_RDONLY);
		while (get_next_line(fd, &line) > 0)
		{
			//printf("line : %s\n", line);
			free(line);
			line = NULL;
		}
		//printf("line : %s\n", line);
	}
	return (0);
}
