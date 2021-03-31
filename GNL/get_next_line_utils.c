/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:47:10 by mtaouil           #+#    #+#             */
/*   Updated: 2021/03/30 14:47:20 by mtaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strchr(char *s, int c)
{
    unsigned int    i;

    i = 0;
    while (s[i])
    {
        if (s[i] == (char)c)
            return ((char *)s + i);
        i++;
    }
    if (s[i] == (char)c)
        return ((char *)s + i);
    return (NULL);
}

unsigned int    ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char    *ft_substr(char *s, unsigned int start, size_t len)
{
    char    *str;
    size_t  i;
    size_t  j;

    if (!s || start >= ft_strlen(s))
        return (ft_strdup(""));
    str = malloc(sizeof(char) * len + 1);
    if (!str)
        return (NULL);
    i = 0;
    j = 0;
    while (s[i])
    {
        if (i >= start && j < len)
        {
            str[j] = s[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
    return (str);
}

char    *ft_strdup(char *s1)
{
    char    *dest;
    int     i;

    dest = malloc(sizeof(char) * ft_strlen(s1) + 1);
    if (!dest)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        dest[i] = s1[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}

int     buff_len(char *s)
{
    int i;

    i = 0;
    while (s[i] && s[i] != '\n')
        i++;
    return (i);
}