/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:46:55 by mtaouil           #+#    #+#             */
/*   Updated: 2021/03/30 14:47:05 by mtaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strjoin(char *s1, char *s2)
{
    char    *dest;
    int     size;
    int     i;
    int     j;

    if (!s1)
        return (s2);
    if (!s2)
        return (s1);
    size = ft_strlen(s1) + ft_strlen(s2);
    dest = malloc(sizeof(char) * size + 1);
    if (!dest)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
    {
        dest[i] = s1[i];
        i++;
    }
    while (s2[j])
        dest[i++] = s2[j++];
    dest[i] = '\0';
    return (dest);
}

char    *new_line(int fd, int a)
{
    char    *s;
    char    *tmp;
    char    buf[BUFFER_SIZE + 1];
    int     n;

    s = "";
    n = read(fd, buf, BUFFER_SIZE);
    while (n != 0)
    {
        if (n < 0)
            return (NULL);
        buf[n] = '\0';
        tmp = s;
        s = ft_strjoin(tmp, buf);
        if (a)
            free(tmp);
        if (ft_strchr(buf, '\n') != NULL)
            break ;
        a++;
        n = read(fd, buf, BUFFER_SIZE);
    }
    return (s);
}

int get_next_line(int fd, char **line)
{
    static char *s = "";
    static int  a = 0;
    char        *buf;
    int         len;

    if (fd < 0 || BUFFER_SIZE < 1 || !line)
        return (-1);
    if (ft_strchr(s, '\n') != NULL)
        buf = s;
    else
        buf = ft_strjoin(s, new_line(fd, a));
    if (!buf)
        return (-1);
    len = buff_len(buf);
    *line = ft_substr(buf, 0, len);
    s = ft_substr(buf, len + 1, ft_strlen(buf) - len);
    free(buf);
    if (ft_strchr(buf, '\n') != NULL)
        return (1);
    free(s);
    return (0);
}

/* int main(void)
{
    char *line;
    int fd;

    fd = open("alphabet.txt", O_RDONLY);
    printf("1er appel\n");
    get_next_line(fd, &line);
    printf("line = %s\n2e appel\n", line);
    get_next_line(fd, &line);
    printf("line = %s\n3e appel\n", line);
    get_next_line(fd, &line);
    printf("line = %s\n4e appel\n", line);
    get_next_line(fd, &line);
    printf("line = %s\n5e appel\n", line);
    get_next_line(fd, &line);
    printf("line = %s\n", line);
} */