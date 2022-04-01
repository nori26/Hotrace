#include "ft_list.h"
#include <stdbool.h>

bool	ft_clst_isend(t_clist *lst)
{
	return (!lst->data);
}
