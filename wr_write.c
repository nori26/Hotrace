#include <unistd.h>
#include <errno.h>
#include "wrbuf.h"

ssize_t	wr_flush_filled(t_wrbuf *wr)
{
	if (wr->idx == WRBUF_SIZE)
		return (wr_flush(wr, WRBUF_SIZE));
	return (0);
}

void	wr_store(t_wrbuf *wr, const char **sp)
{
	const char	*s;

	s = *sp;
	while (wr->idx < WRBUF_SIZE && *s)
	{
		wr->buf[wr->idx] = *s;
		wr->idx++;
		s++;
	}
	*sp = s;
}

ssize_t	wr_flush(t_wrbuf *wr, size_t size)
{
	if (!size)
		return (1);
	wr->idx = 0;
	return (wr_write(wr->fd, wr->buf, size));
}

ssize_t	wr_end(t_wrbuf *wr)
{
	return (wr_flush(wr, wr->idx));
}

ssize_t	wr_write(int fd, const void *buf, size_t n)
{
	size_t	remained;
	size_t	written;
	char	*ptr;

	ptr = buf;
	remained = n;
	while (remained > 0)
	{
		written = write(fd, buf, n);
		if (written < 0)
		{
			if (errno == EINTR)
				written = 0;
			else
				return (-1);
		}
		remained -= written;
		ptr += written;
	}
	return (n);
}
