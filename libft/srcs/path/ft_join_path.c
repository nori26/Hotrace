#include "ft_string.h"

char	*ft_join_path(char *parent, char *child)
{
	size_t	last;

	if (!*parent || child[0] == '/')
		return (ft_strdup(child));
	last = ft_strlen(parent) - 1;
	if (parent[last] == '/' || !*child)
		return (ft_strjoin(parent, child));
	else
		return (ft_strsjoin((char *[]){parent, "/", child, NULL}));
}
