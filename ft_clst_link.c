#include "ft_list.h"

void	ft_clst_link(t_clist *front, t_clist *back)
{
	front->next = back;
	back->prev = front;
}
