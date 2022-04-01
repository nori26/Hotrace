#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "get_next_line.h"
#include "hash.h"

#define HASH_BASE_SIZE 1000000

void	*ft_free_pass(void *to_free, void *newptr)
{
	free(to_free);
	return (newptr);
}

t_hash	*create_dict(t_clist *kvlst)
{
	t_hash	*dict;
	char	*key;
	char	*value;

	dict = hash_new(HASH_BASE_SIZE);
	if (!dict)
	{
		ft_clst_clear(&kvlst, free);
		return (NULL);
	}
	kvlst = ft_clstfirst(kvlst);
	while (!ft_clst_isend(kvlst))
	{
		key = kvlst->data;
		value = kvlst->next->data;
		if (!value)
			break ;
		kvlst = kvlst->next->next;
	}
	return (dict);
	// hash_add(dict, key, value);
}

t_clist	*read_kvlst()
{
	t_clist	*kvlst;
	char	*line;
	int		ret;

	kvlst = ft_clstnew(NULL);
	while (true)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret != 0)
		{
			ft_clst_clear(&kvlst, free); //TODO error handling
			return (NULL);
		}
		if (!line[0])
		{
			free(line);
			break ;
		}
		ft_clstnew_add_back(kvlst, line);
	}
	return (kvlst);
}

int main()
{
	t_clist	*kvlst;
	t_hash	*dict;

	kvlst = read_kvlst();
	if (!kvlst)
		return (1);
	dict = create_dict(kvlst);
	get_key();
	print_value();
	destory_dict();
}
