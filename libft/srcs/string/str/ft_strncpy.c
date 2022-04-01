#include <stddef.h>
#include "ft_string.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *src)
	{
		dest[i] = src[i];
		i++;
	}
	ft_bzero(dest + i, n - i);
	return (dest);
}
