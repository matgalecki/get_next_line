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

char	*fill_line(int fd, char *buf, char *lchr)
{
	char	*tmp;
	int		len;

	len = 1;
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len <= 0 && !lchr)
			return (NULL);
		if (!lchr)
			lchr = ft_strdup("");
		tmp = lchr;
		if (!len)
			break ;
		buf[len] = '\0';
		lchr = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (lchr);
}

char	*set_lchr(char *buf, char **lchr)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (buf == 0)
		return (NULL);
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0')
	{
		*lchr = NULL;
		return (buf);
	}
	else
	{
		if (i + 1 != ft_strlen(buf))
			*lchr = ft_substr(buf, i + 1, ft_strlen(buf) - (i + 1));
		else
			*lchr = NULL;
	}
	tmp = ft_substr(buf, 0, i + 1);
	free(buf);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*lchr;
	char		*fnl;
	char		*buf;
	char		*tmp;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		(void)lchr;
		free(buf);
		return (NULL);
	}
	else
		tmp = fill_line(fd, buf, lchr);
	fnl = set_lchr(tmp, &lchr);
	free(buf);
	return (fnl);
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
	printf("%s", tmp);
	free(tmp);
	tmp = NULL;
	}
	close(fd);
	return (0);
}
*/