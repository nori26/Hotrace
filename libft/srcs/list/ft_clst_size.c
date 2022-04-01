#include "ft_list.h"

size_t	ft_clst_size(t_clist *lst)
{
	size_t	i ;

	i = 0;
	while (lst->next->data)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
