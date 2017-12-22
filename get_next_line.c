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
	if ((k = ft_end_line_find(str, '\n', n)) > 0)
	{
		printf("%s\n", "ft_end_line_find");
		ft_strncat(line, str, k);
		line[--k] = '\0';
		str = ft_memchr(str, '\n', n);
		return (line);
	}
	else
	{
		ft_strncat(line, str, n);
	//	printf("ft_after - else : %s", line);
		str = NULL;
	//	printf("%s\n", "ft_strdel");
	}
	return(NULL);
}

int		get_next_line(const int fd, char **line)
{
	int i;
	int k;
	static char *str;
	char *tmp;

	tmp = ft_strnew(BUFF_SIZE);
	*line = ft_strnew(BUFF_SIZE);
	if (str == NULL)
	{
	//	printf("%s\n", "STR == NULL");
		//str = ft_strnew(BUFF_SIZE);
	}
	else
	{
	//	printf("%s\n", "else");
		printf("STR IN ELSE = %s\n", str);
		ft_after(*line, str, BUFF_SIZE);
	//	printf("%s\n", "ft_after");
		ft_alloc(*line);
	}
	while ((i = read(fd, tmp, BUFF_SIZE) > 0))
	{
	//	printf("READ = %s\n", tmp);
	//	printf("%s\n", "INWHILE");
		if ((k = ft_end_line_find(tmp, '\n', BUFF_SIZE)) > 0)
		{
	//		printf("%s\n","IF");
			ft_strncat(*line, tmp, k);
			line[0][ft_strlen(*line) - 1] = '\0'; //*line[--k] ???
			//printf("final line :%s", *line);
			if (k != BUFF_SIZE)
			{
				str = ft_memchr(tmp, '\n', BUFF_SIZE);
			//	printf("STR = %s\n", str);
			}
			ft_strdel(&tmp);
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






