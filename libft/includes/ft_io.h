#ifndef FT_IO_H
# define FT_IO_H
# include <stddef.h>

void	ft_putbin(size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(const char *s, int fd);
void	ft_puterr(char **msgs);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putstrs_fd(char **strs, int fd);

#endif
