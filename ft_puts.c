#include <unistd.h>
#include "ft_io.h"
#include "wrbuf.h"

ssize_t	ft_puts(t_wrbuf *wr, const char *s)
{
	const char	*nl = "\n";

	ft_putstr_buf(wr, s);
	wr_store(wr, &nl);
	wr_flush_filled(wr);
	return (1);
}
