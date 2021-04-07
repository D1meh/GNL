#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(char *s, int c);
unsigned int	ft_strlen(char *s);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strdup(char *s1);
int				bufL(char *s);
int				get_next_line(int fd, char **line);
int				new_line(int fd, char **s);
void			final_free(void **s);

#endif