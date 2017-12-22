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
		printf("%s\n", line);
	close(fd);
	return (0);

}
