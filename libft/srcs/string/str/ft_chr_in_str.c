#include <stdbool.h>
#include "ft_string.h"

bool	ft_chr_in_str(char c, const char *s)
{
	return (c && ft_strchr(s, c));
}
