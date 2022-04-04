#include <unistd.h>
#include "ft_io.h"
#include "wrbuf.h"

ssize_t	ft_puts(t_wrbuf *wr, const char *s)
{
	ssize_t		written1;
	ssize_t		written2;
	const char	*nl = "\n";

	written1 = ft_putstr_buf(wr, s);
	if (written1 < 0)
		return (-1);
	wr_store(wr, &nl);
	written2 = wr_flush_filled(wr);
	if (written2 < 0)
		return (-1);
	return (written1 + written2);
}
