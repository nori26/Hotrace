#include <unistd.h>
#include "wrbuf.h"

ssize_t	ft_putstr_buf(t_wrbuf *wr, const char *s)
{
	ssize_t	written;
	ssize_t	total;

	total = 0;
	while (*s)
	{
		wr_store(wr, &s);
		written = wr_flush_filled(wr);
		if (written < 0)
			return (-1);
		total += written;
	}
	return (total);
}
