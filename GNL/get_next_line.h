/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:19:55 by mtaouil           #+#    #+#             */
/*   Updated: 2021/03/26 11:19:56 by mtaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>

int     get_next_line(int fd, char **line);
int     len_buff(char *buff);
char    *new_buf(int fd, char *buf, char *str);
char    *ft_strdup(char *s1);
char    *ft_strjoin(char *s1, char *s2);
unsigned int     ft_strlen(char *str);
char    *ft_strchr(char *s, char c);
char    *ft_substr(char *s, unsigned int start, size_t len);

#endif