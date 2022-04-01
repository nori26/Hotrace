/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 20:15:52 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/10/19 17:32:07 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_utils.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*next;

	next = 0;
	if (!f || !lst
		|| (lst->next && !ft_setptr(&next, ft_lstmap(lst->next, f, del))))
		return (NULL);
	if (!ft_setptr(&ret, ft_lstnew(f(lst->content))))
		ft_lstclear(&next, del);
	if (ret)
		ret->next = next;
	return (ret);
}
