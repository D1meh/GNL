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
int     ft_strcmp(char *s1, char *s2);
char    *ft_strdup(char *s1);
char    *new_line(int fd, char *str);

#endif