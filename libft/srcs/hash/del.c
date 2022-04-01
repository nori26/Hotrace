#include <stdlib.h>
#include "hash.h"
#include "ft_list.h"
#include "ft_string.h"

void	hash_del(t_hash *hash, char *key)
{
	const uint64_t	hash_val = hash_gen_fnv1a(key);
	t_list			**lstp_start;
	t_list			*lst_now;
	t_list			*lst_prev;
	t_kvp			*kvp;

	lstp_start = hash_get_bucket_ptr(hash, hash_val);
	lst_prev = NULL;
	lst_now = *lstp_start;
	while (lst_now)
	{
		kvp = (t_kvp *)lst_now->content;
		if (!ft_strcmp(kvp->key, key))
		{
			if (lst_prev)
				lst_prev->next = lst_now->next;
			else
				*lstp_start = lst_now->next;
			hash->count--;
			ft_lstdelone(lst_now, hash_del_kvp);
			return ;
		}
		lst_prev = lst_now;
		lst_now = lst_now->next;
	}
}

void	hash_del_kvp(void *content)
{
	t_kvp	*kvp;

	kvp = (t_kvp *)content;
	free(kvp->key);
	free(kvp->value);
	free(kvp);
}
