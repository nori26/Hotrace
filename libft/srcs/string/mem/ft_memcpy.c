/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:42:38 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/10/19 17:46:43 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;

	d = dest;
	if (n == 0 || dest == src)
		return (dest);
	while (n--)
		*d++ = *(unsigned char *)src++;
	return (dest);
}
