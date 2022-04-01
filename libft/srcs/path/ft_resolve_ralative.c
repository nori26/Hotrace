#include "ft_list.h"
#include "ft_string.h"
#include "ft_path.h"

void	pop_for_relative(t_clist *now)
{
	t_clist	*prev;
	char	*prev_path;

	prev = now->prev;
	prev_path = prev->data;
	if (prev_path && !ft_is_relative_path(prev_path))
	{
		ft_clst_popdel(prev, NULL);
		ft_clst_popdel(now, NULL);
	}
}

void	pop_for_absolute(t_clist *now)
{
	t_clist	*prev;

	prev = now->prev;
	if (!ft_clst_isend(prev))
		ft_clst_popdel(prev, NULL);
	ft_clst_popdel(now, NULL);
}

static void	resolve_relative_parent(t_clist *tokens, t_popdel popdel)
{
	char	*path;
	t_clist	*next;

	tokens = ft_clstfirst(tokens);
	while (!ft_clst_isend(tokens))
	{
		next = tokens->next;
		path = tokens->data;
		if (ft_streq(path, ".."))
			popdel(tokens);
		tokens = next;
	}
}

static void	resolve_relative_current(t_clist *tokens)
{
	char	*path;
	t_clist	*next;

	tokens = ft_clstfirst(tokens);
	while (!ft_clst_isend(tokens))
	{
		next = tokens->next;
		path = tokens->data;
		if (ft_streq(path, "."))
			ft_clst_popdel(tokens, NULL);
		tokens = next;
	}
}

void	ft_resolve_relative_path(t_clist *tokens, t_popdel popdel)
{
	resolve_relative_current(tokens);
	resolve_relative_parent(tokens, popdel);
}
