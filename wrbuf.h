#ifndef WRBUF_H
# define WRBUF_H

# include <unistd.h>
# define WRBUF_SIZE 4096

typedef struct s_wrbuf
{
	int		fd;
	size_t	idx;
	char	buf[WRBUF_SIZE];
}	t_wrbuf;

void	wr_init(t_wrbuf *wr);
void	wr_init_fd(t_wrbuf *wr, int fd);
void	wr_store(t_wrbuf *wr, const char **sp);
ssize_t	wr_flush_filled(t_wrbuf *wr);
ssize_t	wr_flush(t_wrbuf *wr, size_t size);
ssize_t	wr_end(t_wrbuf *wr);
ssize_t	wr_write(int fd, const void *buf, size_t n);

#endif
