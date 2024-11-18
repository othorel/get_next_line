/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:30:45 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/18 12:10:06 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
//# include <stdio.h>

/* ************************************************************************** */
/*					GET_NEXT_LINE_UTILS                                       */
/* ************************************************************************** */

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_free(char *buffer, char *b);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

/* ************************************************************************** */
/*					GET_NEXT_LINE                                             */
/* ************************************************************************** */

char	*ft_next_line(char *str);
char	*ft_read_and_stock(int fd, char *str);
char	*ft_extract_line(char *str);
char	*get_next_line(int fd);

#endif
