#include "ft_list.h"
#include <stdbool.h>

t_clist	*ft_clstnew_add_back(t_clist *lst, void *content)
{
	t_clist	*new;

	new = ft_clstnew(content);
	if (!new)
		return (NULL);
	ft_clstadd_back(lst, new);
	return (new);
}
