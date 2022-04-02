#include "ft_list.h"
#include <stdlib.h>

void	ft_clst_clear(t_clist **lst, void (*del)())
{
	t_clist	*now;
	t_clist	*end;
	t_clist	*next;

	if (!lst || !*lst)
		return ;
	end = *lst;
	now = (*lst)->next;
	while (now != end)
	{
		next = now->next;
		ft_clstdelone(now, del);
		now = next;
	}
	free(end);
	*lst = NULL;
}
