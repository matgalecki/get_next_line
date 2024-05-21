/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalecki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:26:41 by mgalecki          #+#    #+#             */
/*   Updated: 2024/05/13 21:26:47 by mgalecki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*lchr;
	char		*fnl;
	char		*buf;
	char		*tmp;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
}

char *read_file (int fd)
{
	int	i;
	char	*tmp;

	tmp = (char *)malloc(sizeof(int) * (BUFFER_SIZE) + 1);
	if (tmp == NULL)
		return (NULL);
	i = read(fd, tmp, BUFFER_SIZE);
	if (i <= 0)
		return (NULL);
	return (tmp);
}

char *_set_line(char *line_buffer)
{
	
}
/* 
#include <stdio.h>
int	main()
{
	int		fd;
	char	*tmp;

	fd = open("text.txt", O_RDONLY);
	
	while(1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break;
		printf("%s\n", tmp);
		free(tmp);
		tmp = NULL;
	}
	close(fd);
	return (0);
}
*/