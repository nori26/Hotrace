#ifndef HASH_H
# define HASH_H
# include "ft_list.h"
# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>
typedef struct s_kvp
{
	char		*key;
	char		*value;
	uint64_t	_hash_val;
}	t_kvp;
typedef struct s_hash
{
	t_list	**buckets;
	size_t	size;
	size_t	count;
	size_t	_index;
	t_list	*_lst;
}	t_hash;

bool		hash_add(t_hash *hash, char *key, char *value);
bool		hash_add_kvp(t_hash *hash, t_kvp *kvp);
bool		hash_exists(t_hash *hash, char *key);
bool		hash_expand(t_hash *hash);
bool		hash_update_kvp(t_kvp *kvp, char *key, char *value);
char		*hash_get(t_hash *hash, char *key);
size_t		hash_get_buckets_index(t_hash *hash, uint64_t hash_val);
t_hash		*hash_new(size_t size);
t_kvp		*hash_find_kvp_in_bucket(t_list *lst, char *key);
t_kvp		*hash_get_all_kvp(t_hash *hash);
t_kvp		*hash_get_kvp(t_hash *hash, char *key);
t_kvp		*hash_new_kvp(char *key, char *value, uint64_t hash_val);
t_list		**hash_get_bucket_ptr(t_hash *hash, uint64_t hash_val);
t_list		*hash_get_bucket(t_hash *hash, uint64_t hash_val);
uint64_t	hash_gen_fnv1a(char *s);
void		hash_clear(t_hash *hash);
void		hash_clear_with_del(t_hash *hash, void (*del)(void *));
void		hash_del(t_hash *hash, char *key);
void		hash_del_kvp(void *content);
void		hash_destroy(t_hash **hashp);
void		hash_destroy_with_del(t_hash **hashp, void (*del)(void *));
void		hash_init_get_all_kvp(t_hash *hash);

#endif
