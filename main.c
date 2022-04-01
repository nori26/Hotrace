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

void	hr_puterr(char *place)
{
	ft_putstr_fd(place, STDERR_FILENO);
	ft_putstr_fd(" :", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
}

void	hr_handle_err( char *err_place, t_hash **dictp, t_clist **lstp)
{
	ft_clst_clear(lstp, free);
	hash_destroy(dictp);
	hr_puterr(err_place);
}

t_hash	*parse_lst_to_dict(t_clist *kvlst)
{
	t_hash	*dict;
	char	*key;
	char	*value;

	dict = hash_new(HASH_BASE_SIZE);
	if (!dict)
	{
		hr_handle_err("hash new", NULL, &kvlst);
		return (NULL);
	}
	kvlst = ft_clstfirst(kvlst);
	while (!ft_clst_isend(kvlst))
	{
		key = kvlst->data;
		value = kvlst->next->data;
		if (!hash_add(dict, key, value))
		{
			hr_handle_err("hash add", &dict, &kvlst);
			return (NULL);
		}
		if (ft_clst_isend(kvlst->next))
			break ;
		kvlst = kvlst->next->next;
	}
	return (dict);
}

t_clist	*read_lines_to_kvlst()
{
	t_clist	*kvlst;
	char	*line;
	int		ret;

	kvlst = ft_clstnew(NULL);
	if (!kvlst)
	{
		hr_puterr("lstnew");
		return (NULL);
	}
	ret = 1;
	while (ret)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret < 0)
		{
			hr_handle_err("gnl", NULL, &kvlst);
			return (NULL);
		}
		if (!line[0])
		{
			free(line);
			break ;
		}
		if (!ft_clstnew_add_back(kvlst, line))
		{
			hr_handle_err("lstnew", NULL, &kvlst);
			return (NULL);
		}
	}
	return (kvlst);
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

int print_searched_values(t_hash* dict)
{
	char	*key;
	char	*value;
	int		ret;

	ret = 1;
	while (ret)
	{
		ret = get_next_line(STDIN_FILENO, &key);
		if (ret < 0)
		{
			hr_puterr("gnl");
			return (1);
		}
		if (!(ret == 0 && !key[0]))
		{
			value = hash_get(dict, key);
			print_value(key, value);
		}
		free(key);
	}
	return (0);
}

t_hash	*create_dict()
{
	t_hash	*dict;
	t_clist	*kvlst;

	kvlst = read_lines_to_kvlst();
	if (!kvlst)
		return (NULL);
	dict = parse_lst_to_dict(kvlst);
	ft_clst_clear(&kvlst, free);
	return (dict);
}

int main()
{
	t_hash	*dict;
	int		res;

	dict = create_dict();
	if (!dict)
		return (1);
	res = print_searched_values(dict);
	hash_destroy(&dict);
	return (res);
}
