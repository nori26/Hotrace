#include "ft_list.h"
#include <stdbool.h>

bool	ft_clst_isbegin(t_clist *lst)
{
	return (!lst->prev->data);
}
