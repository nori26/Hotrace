#include "ft_list.h"

t_list	*ft_lstnew_add_front(t_list **lst, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
		return (NULL);
	ft_lstadd_front(lst, new);
	return (new);
}
