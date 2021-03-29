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

unsigned int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_substr(char *s, unsigned int start, size_t len)
{
    char    *str;
    unsigned int  i;
    unsigned int  j;

    if (!s || start >= ft_strlen(s))
        return (ft_strdup(""));
    if (ft_strlen(&(s[start])) < len)
        len = ft_strlen(&(s[start]));
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
    str[j] = 0;
    return (str);
}

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

char    *ft_strdup(char *s1)
{
    char    *dest;
    int     i;

    dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
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

char    *ft_strchr(char *s, char c)
{
    unsigned int    i;

    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return (s + i);
        i++;
    }
    if (s[i] == c)
        return (s + i);
    return (NULL);
}