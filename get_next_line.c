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

char    *new_line(int fd)
{
    char    *s;
    char    *tmp;
    char    buf[BUFFER_SIZE + 1];
    int     n;

    s = ft_strdup("");
    n = read(fd, buf, BUFFER_SIZE);
    while (n != 0)
    {
        if (n < 0)
            return (NULL);
        buf[n] = '\0';
        tmp = ft_strjoin(s, buf);
        free(s);
        s = tmp;
        if (ft_strchr(buf, '\n') != NULL)
            break ;
        n = read(fd, buf, BUFFER_SIZE);
    }
    return (s);
}

char    *recup_buff(char *s, int fd)
{
    char    *tmp;
    char    *buf;

    tmp = new_line(fd);
    buf = ft_strjoin(s, tmp);
    free(tmp);
    return (buf);
}

void    delete_if(void **s, int *a)
{
    if (*a > 0)
    {
        free(*s);
        *s = NULL;
    }
    *a = *a + 1;
}

int get_next_line(int fd, char **line)
{
    static char *s = "";
    char        *buf;
    int         len;
    static int  a = 0;

    if (fd < 0 || read(fd, s, 0) < 0 || BUFFER_SIZE < 1 || !line)
        return (-1);
    if (ft_strchr(s, '\n') != NULL)
        buf = s;
    else
        buf = recup_buff(s, fd);
    if (!buf)
        return (-1);
    len = buff_len(buf);
    *line = ft_substr(buf, 0, len);
    delete_if((void **)&s, &a);
    s = ft_substr(buf, len + 1, ft_strlen(buf) - len);
    if (ft_strchr(buf, '\n') != NULL)
    {
        free(buf);
        return (1);
    }
    free(buf);
    //free(s);
    return (0);
}

/* int main()
{
    int fd;
    char *line;

    fd = open("alphabet.txt", O_RDONLY);
    get_next_line(fd, &line);
    get_next_line(fd, &line);
    get_next_line(fd, &line);
    free(line);
} */