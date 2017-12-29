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
#include <stdio.h>

static int		ft_alloc(char *s)
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

static int		ft_end_line_find(char *s, char c, int n)
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

static char		*ft_after(char *line, char *str, size_t n)
{
	int k;

	k = 0;
//	printf("ft_after STR: %s\n", str);
	ft_bzero(line, ft_strlen(line));
	if ((k = ft_end_line_find(str, '\n', n)) > 0)
	{
		//printf("%s\n", "ft_end_line_find");
		ft_strncat(line, str, k);
		line[--k] = '\0';
		str = ft_memchr(str, '\n', n);
	//	str = ft_strchr(str, '\n');
	//	printf("IN AFTER line: %s\n", line);
	//	printf("IN AFTER str :%s\n", str);
	}
	else
	{
		ft_strncat(line, str, n);
		str = NULL;
	//	printf("ft_after - else : %s\n", line);
	//	printf("STR in else :%s\n", str);
	}
	return (str);
}

static char		*ft_read(int fd, char **line, char *str)
{
	int i;
	int k;
	char *tmp;

	tmp = ft_strnew(BUFF_SIZE);
	while ((i = read(fd, tmp, BUFF_SIZE) > 0))
	{
	//	printf("i = %d\n", i);
	//	printf("READ = %s\n", tmp);
		// printf("%s\n", "INWHILE");
		if ((k = ft_end_line_find(tmp, '\n', BUFF_SIZE)) > 0)
		{
		//	printf("%s\n", "FIND");
			ft_strncat(*line, tmp, k);
			line[0][ft_strlen(*line) - 1] = '\0';
			str = ft_memchr(tmp, '\n', BUFF_SIZE);
		//	printf("STR = %s\n", str);
		//	printf("IF-LINE = %s\n", *line);
		//	free(tmp);
			return (str);
		}
		else
		{
		//	printf("TMP BEFORE :%s\n", tmp);
			*line = ft_strjoin(*line, tmp);
			if (ft_strlen(tmp) < BUFF_SIZE)
				break ;
		//	printf("TMP :%s\n", tmp);
		//	printf("LINE :%s\n", *line);
		//	printf("str = %s\n", str);
		}
		ft_alloc(*line);
		//printf("tmp-len %zu\n", ft_strlen(tmp));
		ft_bzero(tmp, ft_strlen(tmp));
		//printf("tmp-len %zu\n", ft_strlen(tmp));
	}
	free(tmp);
//	printf("last LINE :%s\n", *line);
	if (i <= 0)
		return (NULL);
	return (*line);
}

int				get_next_line(const int fd, char **line)
{
	static char *str = NULL;

	*line = ft_strnew(BUFF_SIZE);
//	printf("STR : %s\n", str);
//	printf("line : %s\n", *line);
	if (fd < 0)
		return (-1);
	if (str != NULL)
	{
		str = ft_after(*line, str, BUFF_SIZE);
		ft_alloc(*line);
	//	printf("if-line :%s\n", *line);
		// printf("if-str :%s\n", str);
		if (str == NULL)
		{
			if ((str = ft_read(fd, line, str)) == NULL)
			{
			//	printf("if-if-if line = %s\n", *line);
			//	printf("if-if-if str = %s\n", str);
				return (0);
			}
			//printf("if-if-if line = %s\n", *line);
			// printf("if-if-if str = %s\n", str);
			return (1);
		}
	}
	else
	{
		if ((str = ft_read(fd, line, str)) == NULL)
		{
		//	printf("LINE : %s\n", *line);
		//	printf("if-if-if str = %s\n", str);
			return(0);
		}
		return (1);
	}
	return (1);
}

// - leaks
// - BUFF_SIZE == 1 without '\n'
// - BUFF_SIZE == 9999 && 100000
// - doesn't check closed fd








