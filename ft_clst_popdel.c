#include "ft_list.h"

void	ft_clst_popdel(t_clist *deltarget, void (*del)())
{
	ft_clst_pop(deltarget);
	ft_clstdelone(deltarget, del);
}
