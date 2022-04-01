#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "ft_io.h"
#include "ft_string.h"
#include "get_next_line.h"
#include "hash.h"

#include <stdio.h>

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
		if (!hash_add(dict, key, value))
		{
			ft_clst_clear(&kvlst, free);
			hash_destroy(&dict); // hash 追加失敗 TODO error handling
			return (NULL);
		}
		if (!value)
			break ;
		kvlst = kvlst->next->next;
	}
	return (dict);
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
		if (ret < 0)
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

int search_engine(t_hash* dict)
{
	char	*key;
	char	*value;
	int		ret;

	while (true)
	{
		ret = get_next_line(STDIN_FILENO, &key);
		if (ret < 0)
			return (1);
		value = hash_get(dict, key);
		ft_putendl_fd(value, STDOUT_FILENO);
		free(key);
		if (ret == 0)
			break ;
	}
	return (0);
}

int main()
{
	t_clist	*kvlst;
	t_hash	*dict;
	int		res;

	kvlst = read_kvlst();
	if (!kvlst)
		return (1);
	dict = create_dict(kvlst);
	if (!dict)
		return (1);
	ft_clst_clear(&kvlst, free);
	res = search_engine(dict);
	hash_destroy(&dict);
	return (res);
}
