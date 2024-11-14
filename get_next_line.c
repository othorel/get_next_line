/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:18:23 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/14 17:01:05 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *buffer)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
	{
		new[j] = buffer[i];
		i++;
		j++;
	}
	free(buffer);
	return (new);
}

char	*ft_read(int fd, char *total)
{
	char	*buffer;
	int		b_read;

	if (!total)
		total = malloc(sizeof(char));
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[b_read] = 0;
		total = ft_free(total, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (total);
}

char	*get_line(char *buffer)
{
	char	*new;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 2));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		new[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = next_line(buffer);
	return (line);
}
/*
int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error open !");
		return (1);
	}
	char	*line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
