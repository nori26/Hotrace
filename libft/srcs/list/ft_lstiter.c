/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 19:07:25 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/10/19 17:31:07 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f || !lst)
		return ;
	f(lst->content);
	if (lst->next)
		ft_lstiter(lst->next, f);
}
