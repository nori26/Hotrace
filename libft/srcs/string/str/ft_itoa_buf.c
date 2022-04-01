#include <stddef.h>
#include "ft_utils.h"

void	ft_itoa_buf(int n, char *buf)
{
	uint32_t	u;
	size_t		len;

	u = ft_labs(n);
	if (n < 0)
		buf[0] = '-';
	len = ft_utoa_len(u, buf, n < 0);
	buf[len] = '\0';
}
