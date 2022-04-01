#include "hash.h"
#include "ft_list.h"

char	*hash_get(t_hash *hash, char *key)
{
	t_kvp	*kvp;

	kvp = hash_get_kvp(hash, key);
	if (!kvp)
		return (NULL);
	return (kvp->value);
}

bool	hash_exists(t_hash *hash, char *key)
{
	t_kvp	*kvp;

	kvp = hash_get_kvp(hash, key);
	return (kvp != NULL);
}

t_kvp	*hash_get_kvp(t_hash *hash, char *key)
{
	const uint64_t	hash_val = hash_gen_fnv1a(key);
	t_list			*lst;
	t_kvp			*kvp;

	lst = hash_get_bucket(hash, hash_val);
	kvp = hash_find_kvp_in_bucket(lst, key);
	return (kvp);
}

t_kvp	*hash_get_all_kvp(t_hash *hash)
{
	t_kvp	*kvp;

	while (!hash->_lst && hash->_index < hash->size)
	{
		hash->_lst = hash->buckets[hash->_index];
		hash->_index++;
	}
	if (!hash->_lst)
	{
		hash_init_get_all_kvp(hash);
		return (NULL);
	}
	kvp = (t_kvp *)hash->_lst->content;
	hash->_lst = hash->_lst->next;
	return (kvp);
}

void	hash_init_get_all_kvp(t_hash *hash)
{
	hash->_index = 0;
	hash->_lst = NULL;
}
