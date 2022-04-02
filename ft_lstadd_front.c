/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohki <yohki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:47:20 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/12/18 08:43:32 by yohki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstadd_front(t_list **lst, t_list *newlst)
{
	if (!lst)
		return ;
	if (newlst)
		newlst->next = *lst;
	*lst = newlst;
}
