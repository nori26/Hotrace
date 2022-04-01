#include "ft_list.h"
#include <stdbool.h>

bool	ft_clst_isempty(t_clist *lst)
{
	return (lst == lst->next);
}
