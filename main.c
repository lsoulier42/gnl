#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char	*line = NULL;
	int 	fd;
	int 	ret;
	int 	i = 0;
	int		out;
	int		p[2];

	if (argc == 2)
	{	
		fd = open(argv[1], O_RDONLY);
		ret = get_next_line(19, &line);
		printf("Wrong fd : %s\n", line);
		printf("return value: %d\n", ret);
		while ((ret = get_next_line(fd, &line)) != 0)
		{
			printf("ligne %d : %s\n", i, line);
			printf("return value: %d\n", ret);
			free(line);
		}
		close (fd);
	}
	else
	{
		fd = 1;
		out = dup(fd);
		pipe(p);

		dup2(p[1], fd);
		write(fd, "aaa\nbbb\nccc\nddd\n", 16);
		dup2(out, fd);
		close(p[1]);
		ret = get_next_line(p[0], &line);
		printf("line: %s\n", line);
		printf("retour: %d\n", ret);
		printf("strcmp: %d\n", strcmp(line, "aaa") == 0);
		free(line);
		ret = get_next_line(p[0], &line);
		printf("line: %s\n", line);
		printf("retour: %d\n", ret);
		printf("strcmp: %d\n", strcmp(line, "bbb") == 0);
		free(line);
		ret = get_next_line(p[0], &line);
		printf("line: %s\n", line);
		printf("retour: %d\n", ret);
		printf("strcmp: %d\n", strcmp(line, "ccc") == 0);
		free(line);
		ret = get_next_line(p[0], &line);
		printf("line: %s\n", line);
		printf("retour: %d\n", ret);
		printf("strcmp: %d\n", strcmp(line, "ddd") == 0);
		free(line);
	}		
	return (0);
}
