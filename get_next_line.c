/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:34:07 by proshchy          #+#    #+#             */
/*   Updated: 2017/12/16 15:34:09 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFF_SIZE 8

int		ft_alloc(char *s)
{
	char *tmp;

	if (!(tmp = ft_strnew(ft_strlen(s))))
		return (0);
	ft_strcpy(tmp, s);
	if (!(s = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)))
		return (0);
	ft_strcpy(s,tmp);
	free(tmp);
	return (1);
}

int		ft_end_line_find(char *s, char c, int n)
{
	int k;

	k = 1;
	while (*s || n > 0)
	{
		if (*s == c)
			return (k);
		k++;
		s++;
		n--;
	}
	printf("%s\n", k);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int i;
	static char *str = NULL;

	if (!str)
		str = ft_strnew(BUFF_SIZE);
	//printf("%zu\n", ft_strlen(str));
	while((i = read(fd, *line, BUFF_SIZE)) > 0)
	{
		//printf("0");
		if ((ft_end_line_find(*line, '\n', BUFF_SIZE)) != 0)
		{
			printf("%s\n", "1");
			str = ft_memcpy(str, *line, ft_end_line_find(*line, '\n', BUFF_SIZE));
			return (1);
		}
		else
		{
			str = ft_memcpy(str, *line, BUFF_SIZE);
			ft_alloc(str);
		}
	}
	printf("%s", str);
	return (1);
}

int		main(int argc, char **argv)
{
	char **line;
	int fd;
//	size_t size;

	//printf("-1");
	//size = ft_strlen(argv[1]);
	//printf("-1");
	line = (char **)malloc(sizeof(line) * 1);
	*line = (char *)malloc(sizeof(char) * 1000);
	fd = open(argv[1], O_RDONLY); 
//	printf("fd = %d\n", fd);
	get_next_line(fd, &(*line));
	//close(fd);
	return (0);
}










