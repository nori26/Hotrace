#include <unistd.h>
#include <stdlib.h>
#include "ft_list.h"
#include "ft_path.h"
#include "ft_string.h"

static t_clist	*split_path_to_token(char *rootpath)
{
	t_clist	*tokens;
	char	*remained;
	char	*path;

	tokens = ft_clstnew(NULL);
	if (!tokens)
		return (NULL);
	remained = rootpath;
	while (get_next_token(&remained, "/", &path))
	{
		if (!*path)
			continue ;
		if (!ft_clstnew_add_back(tokens, path))
		{
			ft_clst_clear(&tokens, NULL);
			return (NULL);
		}
	}
	return (tokens);
}

static char	*create_normalized_path(char *path, t_popdel popdel)
{
	char	*normalized;
	t_clist	*tokens;

	tokens = split_path_to_token(path);
	if (!tokens)
		return (NULL);
	ft_resolve_relative_path(tokens, popdel);
	normalized = ft_create_normalized(tokens);
	ft_clst_clear(&tokens, NULL);
	return (normalized);
}

char	*normalize_absolute(char *path)
{
	return (create_normalized_path(path, pop_for_absolute));
}

char	*normalize_relative(char *path)
{
	char	*normalized;

	normalized = create_normalized_path(path, pop_for_relative);
	ft_remove_first_slash(normalized);
	return (normalized);
}

char	*ft_normalize_path(char *path)
{
	char	*path_cpy;
	char	*normalized;

	path_cpy = ft_strdup(path);
	if (!path_cpy)
		return (NULL);
	if (path[0] == '/')
		normalized = normalize_absolute(path_cpy);
	else
		normalized = normalize_relative(path_cpy);
	free(path_cpy);
	return (normalized);
}

// void	resolve_relative_parent(t_clist *tokens)
// {
// 	char	*path;
// 	char	*prev_path;
// 	t_clist	*next;
// 	t_clist	*prev;

// 	tokens = ft_clstfirst(tokens);
// 	while (!ft_clst_isend(tokens))
// 	{
// 		next = tokens->next;
// 		prev = tokens->prev;
// 		path = tokens->data;
// 		prev_path = prev->data;
// 		if (ft_streq(path, ".."))
// 		{
// 			if (ft_clst_isend(prev))
// 				ft_clst_popdel(tokens, NULL);
// 			else if (!ft_is_relative_path(prev_path))
// 			{
// 				ft_clst_popdel(tokens->prev, NULL);
// 				ft_clst_popdel(tokens, NULL);
// 			}
// 		}
// 		tokens = next;
// 	}
// }
// #include <stdio.h>

// #define TEST(a, b) test(a, b,  __LINE__)
// bool	okok = true;

// __attribute__((destructor))
// static void destructor()
// {
// 	if (okok)
// 	    puts("OK");
// }

// void	test(char *path, char *expect, int line)
// {
// 	char *res;

// 	(void)expect;
// 	res = normalize_path(path);
// 	printf("%s\n", path);
// 	free(res);
// }
// //ft_join_path 修正
// int main()
// {
// 	// TEST("", "", NULL);
// 	// TEST("", "/", "/");
// 	// TEST("", "//", "//");
// 	// TEST("/", "", NULL);
// 	// TEST("/", "/", "/");
// 	// TEST("/", "//", "//");
// 	// TEST("//", "", NULL);
// 	// TEST("//", "/", "/");
// 	// TEST("//", "//", "//");

// 	// TEST("", "./", NULL);
// 	// TEST("", "./", NULL);
// 	// TEST("", ".//", NULL);
// 	// TEST("/", "./", "/");
// 	// TEST("/", ".//", "/");
// 	// TEST("//", "./", "//");
// 	// TEST("//", ".//", "//");

// 	// TEST("1", "a", NULL);
// 	// TEST("1", "/a", "/a");
// 	// TEST("1", "a/", NULL);
// 	// TEST("/1", "a", "/1/a");
// 	// TEST("/1", "/a", "/a");
// 	// TEST("/1", "a/", "/1/a");
// 	// TEST("1/", "a", NULL);
// 	// TEST("1/", "/a", "/a");
// 	// TEST("1/", "a/", NULL);

// 	// TEST("1", "//a", "//a");
// 	// TEST("1", "a//", NULL);
// 	// TEST("/1", "//a", "//a");
// 	// TEST("/1", "a//", "/1/a");
// 	// TEST("1/", "//a", "//a");
// 	// TEST("1/", "a//", NULL);

// 	// TEST("//1", "a", "//1/a");
// 	// TEST("//1", "/a", "/a");
// 	// TEST("//1", "a/", "//1/a");
// 	// TEST("//1", "a", "//1/a");
// 	// TEST("//1", "/a", "/a");
// 	// TEST("//1", "a/", "//1/a");
// 	// TEST("//1/", "a", "//1/a");
// 	// TEST("//1/", "/a", "/a");
// 	// TEST("//1/", "a/", "//1/a");

// 	// TEST("1", "./a", NULL);
// 	// TEST("1", ".//a", NULL);
// 	// TEST("1", "./a/", NULL);
// 	// TEST("/1", "./a", "/1/a");
// 	// TEST("/1", ".//a", "/1/a");
// 	// TEST("/1", "./a/", "/1/a");
// 	// TEST("1/", "./a", NULL);
// 	// TEST("1/", ".//a", NULL);
// 	// TEST("1/", "./a/", NULL);

// 	// TEST("//1", "./a", "//1/a");
// 	// TEST("//1", ".//a", "//1/a");
// 	// TEST("//1", "./a/", "//1/a");
// 	// TEST("//1", "./a", "//1/a");
// 	// TEST("//1", ".//a", "//1/a");
// 	// TEST("//1", "./a/", "//1/a");
// 	// TEST("//1/", "./a", "//1/a");
// 	// TEST("//1/", ".//a", "//1/a");
// 	// TEST("//1/", "./a/", "//1/a");
// }
