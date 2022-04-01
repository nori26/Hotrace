#include <stdlib.h>
#include "ft_list.h"
#include "ft_string.h"

static size_t	get_pathlen(t_clist *tokens)
{
	char			*path;
	size_t			len;
	const size_t	num_of_slash = ft_clst_size(tokens);

	len = 0;
	tokens = ft_clstfirst(tokens);
	while (!ft_clst_isend(tokens))
	{
		path = tokens->data;
		len += ft_strlen(path);
		tokens = tokens->next;
	}
	return (len + num_of_slash);
}

static void	join_tokens(t_clist *tokens, char *buf, size_t len)
{
	size_t	i;
	char	*path;

	i = 0;
	tokens = ft_clstfirst(tokens);
	while (!ft_clst_isend(tokens))
	{
		path = tokens->data;
		buf[i++] = '/';
		i += ft_strlcpy(buf + i, path, len + 1);
		tokens = tokens->next;
	}
}

char	*ft_create_normalized(t_clist *tokens)
{
	size_t	len;
	char	*normalized;

	if (!ft_clst_size(tokens))
		return (ft_strdup("/"));
	len = get_pathlen(tokens);
	normalized = malloc(len + 1);
	if (!normalized)
		return (NULL);
	join_tokens(tokens, normalized, len);
	return (normalized);
}
