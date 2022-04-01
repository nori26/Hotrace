#include <stdbool.h>
#include "ft_string.h"

bool	ft_is_relative_path(const char *path)
{
	return (ft_streq(path, ".") || ft_streq(path, "..") || \
			!ft_strncmp(path, "./", 2) || !ft_strncmp(path, "../", 3));
}
