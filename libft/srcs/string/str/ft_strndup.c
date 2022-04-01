#include <stddef.h>
#include <stdlib.h>
#include "ft_string.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dest;
	size_t	len;

	len = ft_strnlen(src, n);
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, src, len);
	dest[len] = '\0';
	return (dest);
}
