#include "hash.h"
#include "ft_list.h"
#include "ft_string.h"

t_list	*hash_get_bucket(t_hash *hash, uint64_t hash_val)
{
	return (*hash_get_bucket_ptr(hash, hash_val));
}

t_list	**hash_get_bucket_ptr(t_hash *hash, uint64_t hash_val)
{
	size_t	index;

	index = hash_get_buckets_index(hash, hash_val);
	return (&hash->buckets[index]);
}

size_t	hash_get_buckets_index(t_hash *hash, uint64_t hash_val)
{
	return (hash_val % hash->size);
}

t_kvp	*hash_find_kvp_in_bucket(t_list *lst, char *key)
{
	t_kvp	*kvp;

	while (lst)
	{
		kvp = (t_kvp *)lst->content;
		if (!ft_strcmp(kvp->key, key))
			return (kvp);
		lst = lst->next;
	}
	return (NULL);
}
