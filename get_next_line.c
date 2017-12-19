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
#define BUFF_SIZE 10

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
		{
			printf("k = %d\n", k);
			return (k);
		}
		k++;
		s++;
		n--;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int i;
	int k;
	static char *str;

	if (!str)
	{
		//printf("%s\n", "ft_strnew");
		str = ft_strnew(BUFF_SIZE);
		*line = ft_strnew(BUFF_SIZE);
	}
	while((i = read(fd, str, BUFF_SIZE)) > 0)
	{
	//	printf("%s\n", "WHILE");
		if ((k = ft_end_line_find(str, '\n', BUFF_SIZE)) != 0)
		{
		//	printf("%s\n", "IF");
			ft_strncat(*line, str, --k);
		//	printf("%s\n", *line);
			ft_strdel(&str);
			return (1);
		}
		else
		{
	//		printf("%s\n", "ELSE");
			ft_strncat(*line, str, BUFF_SIZE);
		//	printf("line :%s\n", *line);
			ft_alloc(*line);
			str = ft_strnew(BUFF_SIZE);
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char *line;
	int fd;
	fd = open(argv[1], O_RDONLY);
//	printf("fd = %d\n", fd);
//	printf("%d\n", get_next_line(fd, &(*line)));
//	get_next_line(fd, &line);
//	printf("%s", line);
	while ((get_next_line(fd, &line) > 0))
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}









