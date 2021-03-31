/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:47:25 by mtaouil           #+#    #+#             */
/*   Updated: 2021/03/30 14:47:28 by mtaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
#include <stdio.h>

char    *ft_strchr(char *s, int c);
unsigned int    ft_strlen(char *s);
char    *ft_substr(char *s, unsigned int start, size_t len);
char    *ft_strdup(char *s1);
int     buff_len(char *s);
char    *ft_strjoin(char *s1, char *s2);
int get_next_line(int fd, char **line);

#endif