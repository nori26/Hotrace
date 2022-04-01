#include <stddef.h>

size_t	ft_strnlen(const char *s, size_t limit)
{
	size_t	i;

	i = 0;
	while (i < limit && s[i])
		i++;
	return (i);
}
