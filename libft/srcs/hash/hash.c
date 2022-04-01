#include "hash.h"
#include "ft_list.h"
#include "ft_string.h"
#include <stddef.h>
#include <stdlib.h>

t_hash	*hash_new(size_t size)
{
	t_hash	*hash;

	hash = (t_hash *)malloc(sizeof(t_hash));
	if (!hash)
		return (NULL);
	hash->size = size;
	hash->buckets = (t_list **)ft_calloc(size, sizeof(t_list *));
	if (!hash->buckets)
	{
		free(hash);
		return (NULL);
	}
	hash->count = 0;
	hash_init_get_all_kvp(hash);
	return (hash);
}
