#include "hash.h"
#include "ft_list.h"
#include "ft_string.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

bool	hash_add(t_hash *hash, char *key, char *value)
{
	const uint64_t	hash_val = hash_gen_fnv1a(key);
	t_list			**lstp;
	t_kvp			*kvp;

	lstp = hash_get_bucket_ptr(hash, hash_val);
	kvp = hash_find_kvp_in_bucket(*lstp, key);
	if (!kvp)
	{
		kvp = hash_new_kvp(key, value, hash_val);
		if (!kvp)
			return (false);
		if (!ft_lstnew_add_front(lstp, kvp))
		{
			hash_del_kvp(kvp);
			return (false);
		}
		hash->count++;
		if (hash->count > hash->size)
			hash_expand(hash);
		return (true);
	}
	else
		return (hash_update_kvp(kvp, value));
}

t_kvp	*hash_new_kvp(char *key, char *value, uint64_t hash_val)
{
	t_kvp	*kvp;

	kvp = (t_kvp *)ft_calloc(1, sizeof(t_kvp));
	if (!kvp)
		return (NULL);
	// kvp->key = ft_strdup(key);
	// if (value)
	// 	kvp->value = ft_strdup(value);
	// if (!kvp->key || (value && !kvp->value))
	// {
	// 	hash_del_kvp(kvp);
	// 	return (NULL);
	// }
	kvp->key = key;
	kvp->value = value;
	kvp->_hash_val = hash_val;
	return (kvp);
}

bool	hash_update_kvp(t_kvp *kvp, char *value)
{
	char	*new_value;

	if (value)
		new_value = ft_strdup(value);
	else
		new_value = NULL;
	if (value && !new_value)
		return (false);
	free(kvp->value);
	kvp->value = new_value;
	return (true);
}

bool	hash_expand(t_hash *hash)
{
	t_hash	*new_hash;
	t_kvp	*kvp;

	new_hash = hash_new(hash->size * 4);
	if (!new_hash)
		return (false);
	hash_init_get_all_kvp(hash);
	kvp = hash_get_all_kvp(hash);
	while (kvp)
	{
		if (!hash_add_kvp(new_hash, kvp))
		{
			hash_destroy_with_del(&new_hash, NULL);
			return (false);
		}
		kvp = hash_get_all_kvp(hash);
	}
	hash_clear_with_del(hash, NULL);
	free(hash->buckets);
	*hash = *new_hash;
	free(new_hash);
	return (true);
}

bool	hash_add_kvp(t_hash *hash, t_kvp *kvp)
{
	t_list	**lstp;

	lstp = hash_get_bucket_ptr(hash, kvp->_hash_val);
	if (!ft_lstnew_add_front(lstp, kvp))
		return (false);
	hash->count++;
	return (true);
}
