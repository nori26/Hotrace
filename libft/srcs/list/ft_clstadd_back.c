#include "ft_list.h"

void	ft_clstadd_back(t_clist *sentinel, t_clist *newlst)
{
	ft_clst_insert(sentinel->prev, newlst);
}
