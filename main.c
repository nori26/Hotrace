#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "ft_io.h"
#include "ft_string.h"
#include "get_next_line.h"
#include "hash.h"

#define HASH_BASE_SIZE 1000000

typedef struct hotrace
{
	t_hash	*dict;
	t_clist	*kvlst;
	t_clist	*keylst;
}	t_hotrace;

void	hr_puterr(char *place)
{
	ft_putstr_fd(place, STDERR_FILENO);
	ft_putstr_fd(" :", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
}

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

bool	read_into_lst(t_clist *lst, bool (*is_empty)())
{
	int		ret;
	char	*line;

	ret = 1;
	while (ret)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret < 0)
		{
			hr_puterr("gnl");
			return (false);
		}
		if (is_empty(line, ret))
		{
			free(line);
			break ;
		}
		if (!ft_clstnew_add_back(lst, line))
		{
			free(line);
			hr_puterr("lstnew");
			return (false);
		}
	}
	return (true);
}

bool	is_empty_for_kvlst(char *line, int ret)
{
	(void)ret;
	return (line[0] == '\0');
}

bool	is_empty_for_keylst(char *line, int ret)
{
	return (ret == 0 && line[0] == '\0');
}

bool	read_into_kvlst(t_clist *kvlst)
{
	return (read_into_lst(kvlst, is_empty_for_kvlst));
}

bool	read_into_keylst(t_clist *keylst)
{
	return (read_into_lst(keylst, is_empty_for_keylst));
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

void	print_value(char *key, char *value)
{
	if (value)
		ft_putendl_fd(value, STDOUT_FILENO);
	else
	{
		ft_putstr_fd(key, STDOUT_FILENO);
		ft_putendl_fd(": Not found.", STDOUT_FILENO);
	}
}

void	print_values(t_hotrace *hr)
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

bool	read_into_dict(t_hotrace *hr)
{
	bool	is_ok;

	is_ok = \
		read_into_kvlst(hr->kvlst) && \
		parse_kvlst_to_hash(hr);
	ft_clst_clear(&hr->kvlst, free);
	return (is_ok);
}

int main()
{
	t_hotrace	hr;

	if (!init_hotrace(&hr) || \
		!read_into_dict(&hr) || \
		!read_into_keylst(hr.keylst))
	{
		destroy_hotrace(&hr);
		return (EXIT_FAILURE);
	}
	print_values(&hr);
	destroy_hotrace(&hr);
	return (EXIT_SUCCESS);
}
