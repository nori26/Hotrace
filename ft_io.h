#ifndef FT_IO_H
# define FT_IO_H

# include <stdbool.h>
typedef struct s_wrbuf	t_wrbuf;

void	ft_putendl_fd(const char *s, int fd);
void	ft_putstr_fd(const char *s, int fd);
ssize_t	ft_puts(t_wrbuf *wr, const char *s);
ssize_t	ft_putstr_buf(t_wrbuf *wr, const char *s);

#endif
