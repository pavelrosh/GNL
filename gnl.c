#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

//#include "lidft.h"
#define BUF_SIZE 100

// int get_next_line(const int fd, char **line)
// {
// 	int i;
// 	//*line = malloc(sizeof(char *) * 11);
// 	printf("1");
// 	i = read(fd, *line, BUF_SIZE);
// 	printf("2");
// 	return (i);
// }

// int		main(int argc, char **argv)
// {
// 	char **line;
// 	int fd;
// 	printf("404");
// 	*line = malloc(sizeof(char *) * 11);
// 	printf("0");
// 	fd = open (argv[1], O_RDONLY);
// 	printf("%d\n", get_next_line(fd, &(*line)));
// 	//printf("%s\n", *line);
// 	return (0);
// }
size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int main (int argc, char **argv)
{
	int fd;
	int ret;
	char **ch;
	size_t size;
	size = ft_strlen(argv[1]);
	ch = (char **)malloc(sizeof(ch) * 1);\
	*ch = (char *)malloc(sizeof(char) * size + 1);
	fd = open (argv[1], O_RDONLY);
	while ((ret = read (fd, *ch, size)) > 0)
		printf("%s", *ch);
	close (fd);
}
