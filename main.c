/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 19:25:49 by proshchy          #+#    #+#             */
/*   Updated: 2017/12/18 19:26:00 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char *line;
	int fd;
//	int fd1;
	int i;

	if (argc != 2)
		return (0);
	i = 0;
	fd = open(argv[1], O_RDONLY);
//	fd1 = open(argv[2], O_RDONLY);
	line = NULL;
	while ((i = get_next_line(fd, &line)) > 0)
	{
	//	printf("i = %d\n", i);
		printf("%s\n", line);
		ft_strdel(&line);
	}
	// while ((i = get_next_line(fd1, &line)) > 0)
	// {
	// //	printf("i = %d\n", i);
	// 	printf("%s\n", line);
	// 	ft_strdel(&line);
	// }
	close(fd);
	// close(fd1);

 	return (0);
}
