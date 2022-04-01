#ifndef FT_STRING_H
# define FT_STRING_H
# define LSB_MASK 0x0101010101010101ull
# define MSB_MASK 0x8080808080808080ull
# include <stddef.h>
# include <stdbool.h>

bool	ft_atol(const char *str, long *n);
bool	ft_chr_in_str(char c, const char *s);
bool	ft_streq(const char *s1, const char *s2);
bool	get_next_token(char **strptr, char *delims, char **token);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strbsearch(char *key, char **strs, size_t nmemb);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strndup(const char *src, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strsep(char **strptr, char *delims);
char	*ft_strsjoin(char **strs);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, size_t start, size_t len);
int		ft_atoi(const char *str);
int		ft_atoi_err(char *s, int *i);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_fastrlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strnlen(const char *s, size_t limit);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	ft_itoa_buf(int n, char *buf);

#endif
