#include "ft_string.h"
#include "ft_utils.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	char	*ret;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	if (!ft_setptr(&ret, malloc(len1 + len2 + 1)))
		return (NULL);
	tmp = ret;
	while (len1 && *s1)
		*tmp++ = *s1++;
	while (len2 && *s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (ret);
}
