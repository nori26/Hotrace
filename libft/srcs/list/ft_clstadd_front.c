#include "ft_list.h"

void	ft_clstadd_front(t_clist *sentinel, t_clist *newlst)
{
	ft_clst_insert(sentinel, newlst);
}
