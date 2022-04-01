#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "ft_string.h"
#include "get_next_line.h"
#include "hash.h"

#include <stdio.h>

#define HASH_BASE_SIZE 1000000

#define DEBUG printf("DEBUG\n");

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
		key = (char *)kvlst->data; // key だけの時は dict に追加しない ??
		// printf("data: %s\n", key);
		value = (char *)kvlst->next->data;
		if (!value)
			break ;
		if (!hash_add(dict, key, value))
		{
			hash_clear(dict); // hash 追加失敗 TODO error handling
			return (NULL);
		}
		kvlst = kvlst->next->next;
	}
	// kvlst 消去
	ft_clst_clear(&kvlst, free);
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

void search_engine(t_hash* dict)
{
	char *key;
	char *value;
	int ret;

	key = NULL;
	value = NULL;
	while (true)
	{
		ret = get_next_line(STDIN_FILENO, &key);
		if (ret == 0)
			break;
		if (ret < 0)
		{
			// key 取得失敗 // TODO error msg
			break;
		}
		value = hash_get(dict, key);
		// value がなかった時の処理
		if (write(STDOUT_FILENO, value, ft_strlen(value)) < 0)
		{
			// 出力失敗 // TODO error msg
			free(key);
			// free(value);
			break;
		}
		write(1, "\n", 1);
	}
	free(key);
	key = NULL;
	// free(value);
}

void destroy_dict(t_hash *dict)
{
	if (dict)
		hash_destroy(&dict);
}

int main()
{
	t_clist	*kvlst;
	t_hash	*dict;

	kvlst = read_kvlst();
	if (!kvlst)
		return (1);
	dict = create_dict(kvlst);
	search_engine(dict);
	// get_key();
	// print_value();
	destroy_dict(dict);
}
