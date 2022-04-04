#include <unistd.h>
#include "wrbuf.h"

ssize_t	ft_putstr_buf(t_wrbuf *wr, const char *s)
{
	while (*s)
	{
		wr_store(wr, &s);
		wr_flush_filled(wr);
	}
	return (1);
}
