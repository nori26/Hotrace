#include "ft_list.h"
#include <stdlib.h>

void	ft_clstdelone(t_clist *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (del)
		del(lst->data);
	free(lst);
}
