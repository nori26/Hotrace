#include "hash.h"
#include "ft_list.h"
#include <stdlib.h>

void	hash_clear(t_hash *hash)
{
	hash_clear_with_del(hash, hash_del_kvp);
}

void	hash_clear_with_del(t_hash *hash, void (*del)(void *))
{
	t_list			**lstp;
	size_t			i;

	i = 0;
	while (i < hash->size)
	{
		lstp = &hash->buckets[i];
		ft_lstclear(lstp, del);
		i++;
	}
	hash->count = 0;
}

void	hash_destroy(t_hash **hashp)
{
	hash_destroy_with_del(hashp, hash_del_kvp);
}

void	hash_destroy_with_del(t_hash **hashp, void (*del)(void *))
{
	t_hash	*hash;

	if (!hashp || !*hashp)
		return ;
	hash = *hashp;
	hash_clear_with_del(hash, del);
	free(hash->buckets);
	free(hash);
	*hashp = NULL;
}
