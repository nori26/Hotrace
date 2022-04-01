#include <stdlib.h>

void	*free_set(void *p1, void *p2)
{
	free(p1);
	return (p2);
}
