/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:27:12 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/17 16:57:55 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
//# include <stdio.h>

/* ************************************************************************** */
/*					GET_NEXT_LINE_UTILS_BONUS                                 */
/* ************************************************************************** */

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_free(char *buffer, char *b);

/* ************************************************************************** */
/*					GET_NEXT_LINE_BONUS                                       */
/* ************************************************************************** */

char	*next_line(char *str);
char	*ft_read(int fd, char *str);
char	*ft_get_line(char *str);
char	*get_next_line(int fd);

#endif