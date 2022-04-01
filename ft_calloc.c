/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:07:40 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/11/29 08:14:21 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_string.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	bytes;

	if (!size || !nmemb)
		return (ft_calloc(1, 1));
	bytes = nmemb * size;
	if (bytes / nmemb != size)
		return (NULL);
	if (!ft_setptr(&p, malloc(bytes)))
		return (NULL);
	return (ft_memset(p, 0, bytes));
}
