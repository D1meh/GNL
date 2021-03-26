/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:19:50 by mtaouil           #+#    #+#             */
/*   Updated: 2021/03/26 11:19:51 by mtaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    char    str[BUFFER_SIZE];
    
    if (*line)
    {
        new_line(fd, str);
        printf("%s\n", str);
        while (ft_strcmp(str, *line) != 0)
        {
            new_line(fd, str);
            printf("%s\n", str);
            printf("%d\n", ft_strcmp(str, *line));
        }
        /* free(*line); */
    }
    new_line(fd, str);
    *line = ft_strdup(str);
    return (1);
}

int main(void)
{
    int fd;
    char *line = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    fd = open("test.txt", O_RDONLY);
    get_next_line(fd, &line);
    printf("%s\n", line);
}