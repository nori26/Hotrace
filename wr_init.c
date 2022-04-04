#include <unistd.h>
#include "wrbuf.h"

void	wr_init(t_wrbuf *wr)
{
	wr->fd = STDOUT_FILENO;
	wr->idx = 0;
}

void	wr_init_fd(t_wrbuf *wr, int fd)
{
	wr->fd = fd;
	wr->idx = 0;
}
