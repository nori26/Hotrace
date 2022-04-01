#include "ft_list.h"

t_clist	*ft_clst_pop(t_clist *lst)
{
	ft_clst_link(lst->prev, lst->next);
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}
