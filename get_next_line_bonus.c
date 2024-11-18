/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:31:32 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/18 13:12:45 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = nmemb * size;
	if (nmemb != 0 && total_size / nmemb != size)
		return (NULL);
	ptr = (void *)malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}
/*ft_next_line is used to update the given string buffer by removing 
the first line (up to and including the newline character \n) and returning 
the remaining part of the string. It is typically used in the context of reading
 a file line by line, where after extracting the current line, this function 
prepares the buffer for the next line extraction.*/

char	*ft_next_line(char *str)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new = ft_calloc(sizeof(char), ft_strlen(str) - i + 1);
	if (!new)
	{
		free(str);
		return (NULL);
	}
	i++;
	j = 0;
	while (str[i])
		new[j++] = str[i++];
	free(str);
	return (new);
}
/*ft_read_and_stock function reads data from a file descriptor (fd) into a 
dynamically allocated string buffer (str). It continuously reads from the 
file until it encounters a newline character (\n) or reaches the end of the
 file. The function accumulates the read content in str, effectively storing
  all read characters up to and including a newline.
This function is commonly used in implementations like get_next_line to read 
file content line by line.*/

char	*ft_read_and_stock(int fd, char *str)
{
	char	*buffer;
	int		b_read;

	if (!str)
		str = ft_calloc(1, 1);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	b_read = 1;
	while (!ft_strchr(str, '\n') && b_read != 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[b_read] = 0;
		str = ft_free(str, buffer);
	}
	free(buffer);
	return (str);
}
/*ft_extract_line function extracts the first line from a given string (str)
 and returns it as a new dynamically allocated string. The function reads 
 characters from str until it encounters a newline character (\n) or reaches
 the end of the string. It then creates a new string containing the extracted
 line, including the newline character.
This function is commonly used in implementations like get_next_line to extract
 the current line from a buffer containing file content.*/

char	*ft_extract_line(char *str)
{
	char	*new;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new = ft_calloc(sizeof(char), i + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	return (new);
}
/*get_next_line function reads a file descriptor (fd) line by line and returns
 the line read from the file without the newline character (\n). The function
  uses a static buffer to store the read content and updates it as needed. 
  It reads from the file descriptor until it encounters a newline character 
  or reaches the end of the file, extracting and returning the current line 
  each time it is called.
This function is commonly used to read text files line by line in C programs.*/

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read_and_stock(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_extract_line(buffer[fd]);
	buffer[fd] = ft_next_line(buffer[fd]);
	if (!buffer[fd])
		free(buffer[fd]);
	return (line);
}

/* int	main(void)
{
	int fd1 = open("test1.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	char *line1;
	char *line2;
	
	while ((line1 = get_next_line(fd1)) || (line2 = get_next_line(fd2)))
	{
		if (line1)
		{
			printf("%s\n", line1);
			free(line1);
		}
		if (line2)
		{
			printf("%s\n", line2);
			free(line1);
		}
	}
	close(fd1);
	close(fd2);
	return (0);
} */
