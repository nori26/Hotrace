#include "ft_list.h"

t_clist	*ft_clstfirst(t_clist *lst)
{
	while (lst->data)
		lst = lst->next;
	return (lst->next);
}
