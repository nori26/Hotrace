/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 06:00:44 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/10/19 17:27:06 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*del_set(t_list *lst, t_list *next, void (*del)(void*))
{
	ft_lstdelone(lst, del);
	return (next);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst)
		return ;
	while (*lst)
		*lst = del_set(*lst, (*lst)->next, del);
}
