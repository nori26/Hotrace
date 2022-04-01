#include "ft_list.h"

void	ft_clst_insert_all(t_clist *dest, t_clist **srcptr, void (*del)())
{
	t_clist	*src;

	src = *srcptr;
	ft_clst_link(src->prev, dest->next);
	ft_clst_link(dest, src->next);
	ft_clstdelone(src, del);
	*srcptr = NULL;
}
