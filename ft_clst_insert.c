#include "ft_list.h"

void	ft_clst_insert(t_clist *lst, t_clist *newlst)
{
	ft_clst_link(newlst, lst->next);
	ft_clst_link(lst, newlst);
}
