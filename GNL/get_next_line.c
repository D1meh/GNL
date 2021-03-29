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
#include <string.h>

int     len_buff(char *buff)
{
    int i;

    i = 0;
    while (buff[i] && buff[i] != '\n')
        i++;
    return (i);
}

char    *new_buf(int fd, char *buf, char *str)
{
    char    *tmp;
    int n;

    n = read(fd, buf, BUFFER_SIZE);
    while (n)
    {
        buf[n] = '\0';
        tmp = ft_strdup(str);
        str = ft_strjoin(tmp, buf);
        free(tmp);
        if (ft_strchr(buf, '\n') != NULL)
            break ;
        n = read(fd, buf, BUFFER_SIZE);
    }
    return (str);
}

int get_next_line(int fd, char **line)
{
    static char *str = "";
    char        buf[BUFFER_SIZE + 1];

    if (BUFFER_SIZE < 1 || fd < 0 || read(fd, buf, 0) < 0)
        return (-1);
    str = new_buf(fd, buf, str);
    printf("str = %s\n", str);
    *line = ft_substr(str, 0, len_buff(str));
    str = ft_substr(str, len_buff(str) + 1, ft_strlen(str) - len_buff(str));
    printf("2: str = %s\n", str);
    return (1);
}

int main(void)
{
    int fd;
    char *line = "acfevrdfghf";

    fd = open("alphabet.txt", O_RDONLY);
    get_next_line(fd, &line);
    printf("line = %s\n", line);
    get_next_line(fd, &line);
    printf("line = %s\n", line);
    get_next_line(fd, &line);
    printf("line = %s\n", line);
    get_next_line(fd, &line);
    printf("line = %s\n", line);
    get_next_line(fd, &line);
    printf("line = %s\n", line);
}

