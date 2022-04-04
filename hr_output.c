#include <unistd.h>
#include "ft_io.h"
#include "ft_list.h"
#include "hash.h"
#include "hotrace.h"
#include "wrbuf.h"

static void	print_value(char *key, char *value, t_wrbuf *wr)
{
	if (value)
		ft_puts(wr, value);
	else
	{
		ft_putstr_buf(wr, key);
		ft_puts(wr, ": Not found.");
	}
}

void	print_values_of_keylst(t_hotrace *hr)
{
	char	*key;
	char	*value;
	t_hash	*dict;
	t_clist	*keylst;
	t_wrbuf	wr;

	wr_init(&wr);
	dict = hr->dict;
	keylst = ft_clstfirst(hr->keylst);
	while (!ft_clst_isend(keylst))
	{
		key = keylst->data;
		value = hash_get(dict, key);
		print_value(key, value, &wr);
		keylst = keylst->next;
	}
	wr_end(&wr);
}
