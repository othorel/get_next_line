/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:30:45 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/14 17:54:26 by olthorel         ###   ########.fr       */
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

/* ************************************************************************** */
/*					GET_NEXT_LINE                                             */
/* ************************************************************************** */

char	*next_line(char *buffer);
char	*ft_read(int fd, char *total);
char	*get_line(char *buffer);
char	*get_next_line(int fd);

#endif
