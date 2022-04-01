/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohki <yohki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:33:10 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/12/18 08:43:17 by yohki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = newlst;
	else
		ft_lstlast(*lst)->next = newlst;
}
