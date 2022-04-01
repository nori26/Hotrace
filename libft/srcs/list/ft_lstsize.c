/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 22:30:57 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/10/19 17:28:19 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <limits.h>

int	ft_lstsize(t_list *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	if (size > INT_MAX)
		return (-1);
	return (size);
}
