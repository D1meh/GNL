#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		size;
	int		i;
	int		j;

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

int	new_line(int fd, char **s)
{
	int		n;
	char	*tmp;
	char	buf[BUFFER_SIZE + 1];

	n = read(fd, buf, BUFFER_SIZE);
	if (n < 1)
		return (n);
	buf[n] = '\0';
	tmp = ft_strjoin(*s, buf);
	free(*s);
	*s = tmp;
	return (n);
}

void	final_free(void **s)
{
	free(*s);
	*s = NULL;
}

int	get_next_line(int fd, char **line)
{
	static char	*s[1024];
	char		*tmp;
	int			n;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, s, 0) < 0)
		return (-1);
	if (s[fd] == NULL)
		s[fd] = ft_strdup("");
	n = 1;
	while (!ft_strchr(s[fd], '\n') && n)
		n = new_line(fd, &s[fd]);
	if (n < 0)
		return (-1);
	else if (n == 0)
		*line = ft_strdup(s[fd]);
	else
		*line = ft_substr(s[fd], 0, bufL(s[fd]));
	tmp = ft_substr(s[fd], bufL(s[fd]) + 1, ft_strlen(s[fd]) - bufL(s[fd]));
	free(s[fd]);
	s[fd] = tmp;
	if (n > 0)
		return (1);
	final_free((void **)&s[fd]);
	return (0);
}