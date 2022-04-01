#include <stdlib.h>

void	ft_free_assign(void **dest, void *src)
{
	free(*dest);
	*dest = src;
}
