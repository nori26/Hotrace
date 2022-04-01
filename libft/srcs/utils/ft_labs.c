#include "ft_utils.h"
#include <limits.h>

t_ulong	ft_labs(long n)
{
	t_ulong	u;

	u = n;
	if (u > LONG_MAX)
		u = ~u + 1;
	return (u);
}
