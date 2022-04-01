/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 22:01:31 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/12/06 06:12:45 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_string.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	const char	*tmp;

	if (!size)
		return (ft_strlen(src));
	i = 0;
	tmp = src;
	while (*tmp && i++ + 1 < size)
		*dst++ = *tmp++;
	*dst = '\0';
	return (tmp - src + ft_strlen(tmp));
}
