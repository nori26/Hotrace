#include <unistd.h>
#include "ft_io.h"
#include "ft_list.h"
#include "hash.h"
#include "hotrace.h"

static void	print_value(char *key, char *value)
{
	if (value)
		ft_putendl_fd(value, STDOUT_FILENO);
	else
	{
		ft_putstr_fd(key, STDOUT_FILENO);
		ft_putendl_fd(": Not found.", STDOUT_FILENO);
	}
}

void	print_values_of_keylst(t_hotrace *hr)
{
	char	*key;
	char	*value;
	t_hash	*dict;
	t_clist	*keylst;

	dict = hr->dict;
	keylst = ft_clstfirst(hr->keylst);
	while (!ft_clst_isend(keylst))
	{
		key = keylst->data;
		value = hash_get(dict, key);
		print_value(key, value);
		keylst = keylst->next;
	}
}
