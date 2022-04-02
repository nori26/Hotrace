#include <stdlib.h>
#include <stdbool.h>
#include "ft_string.h"
#include "ft_list.h"
#include "hash.h"
#include "hotrace.h"

#define HASH_BASE_SIZE 1000000

void	destroy_hotrace(t_hotrace *hr)
{
	hash_destroy(&hr->dict);
	ft_clst_clear(&hr->kvlst, free);
	ft_clst_clear(&hr->keylst, free);
}

bool	init_hotrace(t_hotrace *hr)
{
	hr->dict = hash_new(HASH_BASE_SIZE);
	hr->kvlst = ft_clstnew(NULL);
	hr->keylst = ft_clstnew(NULL);
	if (!hr->dict || !hr->kvlst || !hr->keylst)
	{
		hr_puterr("init");
		return (false);
	}
	return (true);
}

bool	parse_kvlst_to_hash(t_hotrace *hr)
{
	char	*key;
	char	*value;
	t_clist	*kvlst;

	kvlst = ft_clstfirst(hr->kvlst);
	while (!ft_clst_isend(kvlst))
	{
		key = kvlst->data;
		value = kvlst->next->data;
		if (!hash_add(hr->dict, key, value))
		{
			hr_puterr("hash add");
			return (false);
		}
		if (ft_clst_isend(kvlst->next))
			break ;
		kvlst = kvlst->next->next;
	}
	return (true);
}

bool	read_into_dict(t_hotrace *hr)
{
	bool	is_ok;

	is_ok = \
		read_into_kvlst(hr->kvlst) && \
		parse_kvlst_to_hash(hr);
	ft_clst_clear(&hr->kvlst, NULL);
	return (is_ok);
}

int	main(void)
{
	t_hotrace	hr;

	if (!init_hotrace(&hr) || \
		!read_into_dict(&hr) || \
		!read_into_keylst(hr.keylst))
	{
		destroy_hotrace(&hr);
		return (EXIT_FAILURE);
	}
	print_values_of_keylst(&hr);
	destroy_hotrace(&hr);
	return (EXIT_SUCCESS);
}
