/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:19:59 by mtaouil           #+#    #+#             */
/*   Updated: 2021/03/26 11:20:00 by mtaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1 && s2 && s1[i] == s2[i] && i < BUFFER_SIZE - 1)
        i++;
    return (s1[i] - s2[i]);
}

char    *ft_strdup(char *s1)
{
    char    *str;
    int     i;

    str = malloc(sizeof(char) * BUFFER_SIZE);
    if (!str)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = 0;
    return (str);
}

char    *new_line(int fd, char *str)
{
    char    c;
    int     i;
    int     n;

    n = read(fd, &c, 1);
    i = 0;
    while (n == 1 && c != '\n')
    {
        str[i] = c;
        printf("i = %d, s = %c\n", i, str[i]);
        i++;
        if (i == BUFFER_SIZE)
            break ;
        n = read(fd, &c, 1);
    }
    str[i] = 0;
    return (str);
} 