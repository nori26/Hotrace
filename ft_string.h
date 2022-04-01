#ifndef FT_STRING_H
# define FT_STRING_H
# define LSB_MASK 0x0101010101010101ull
# define MSB_MASK 0x8080808080808080ull
# include <stddef.h>
# include <stdbool.h>

char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *s, int c, size_t n);

#endif
