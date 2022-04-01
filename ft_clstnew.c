#include "ft_list.h"
#include <stdlib.h>

t_clist	*ft_clstnew(void *data)
{
	t_clist	*new;

	new = malloc(sizeof(t_clist));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = new;
	new->prev = new;
	return (new);
}
