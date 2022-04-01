#include <stdint.h>

int	ft_setptr(void *dest, void *p)
{
	*(uintptr_t *)dest = (uintptr_t)p;
	return (!!p);
}
