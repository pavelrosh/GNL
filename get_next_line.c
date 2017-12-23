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
#define BUFF_SIZE 5

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
		//	printf("k = %d\n", k);
			return (k);
		}
		k++;
		s++;
		n--;
	}
	return (0);
}

char	*ft_after(char *line, char *str, size_t n)
{
	int k;

	k = 0;
//	printf("ft_after STR: %s\n", str);
	if ((k = ft_end_line_find(str, '\n', n)) > 0)
	{
		//printf("%s\n", "ft_end_line_find");
		ft_strncat(line, str, k);
		line[--k] = '\0';
		str = ft_memchr(str, '\n', n);
	//	printf("IN AFTER line: %s\n", line);
	//	printf("IN AFTER str :%s\n", str);
	}
	else
	{
		ft_strncat(line, str, n);
		str = NULL;
	//	printf("ft_after - else : %s\n", line);
	//	printf("%s\n", str);
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	int i;
	int k;
	static char *str;
	char *tmp;

	tmp = ft_strnew(BUFF_SIZE);
	//printf("STR :%s\n", str);
	//printf("line - %s\n", *line);
	if (str)
	{
		str = ft_after(*line, str, BUFF_SIZE);
		ft_alloc(*line);
	//	printf("LINE after ft :%s\n", *line);
	}
	else
	{
		*line = ft_strnew(BUFF_SIZE);
		while ((i = read(fd, tmp, BUFF_SIZE) > 0))
		{
			// printf("READ = %s\n", tmp);
			// printf("%s\n", "INWHILE");
			if ((k = ft_end_line_find(tmp, '\n', BUFF_SIZE)) > 0)
			{
				ft_strncat(*line, tmp, k);
				line[0][ft_strlen(*line) - 1] = '\0'; //*line[--k] ???
			//printf("final line :%s", *line);
				str = ft_memchr(tmp, '\n', BUFF_SIZE);
	//				printf("STR = %s\n", str);
				return (1);
			}
			else
			{
			//	printf("%s\n", "ELSE");
				ft_strncat(*line, tmp, BUFF_SIZE);
			//	printf("%s\n", *line);
			}
			ft_alloc(*line);
		}
		return (0);
	}
	return (1);
}



