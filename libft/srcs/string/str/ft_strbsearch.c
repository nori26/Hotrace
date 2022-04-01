#include <stddef.h>
#include "ft_string.h"

char	*ft_strbsearch(char *key, char **strs, size_t nmemb)
{
	size_t	low;
	size_t	mid;
	size_t	high;
	int		diff;

	if (!nmemb)
		return (NULL);
	low = 0;
	high = nmemb - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		diff = ft_strcmp(strs[mid], key);
		if (diff == 0)
			return (strs[mid]);
		else if (diff < 0)
			low = mid + 1;
		else if (diff > 0 && mid > 0)
			high = mid - 1;
		else
			return (NULL);
	}
	return (NULL);
}
