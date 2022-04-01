/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 09:22:56 by nosuzuki          #+#    #+#             */
/*   Updated: 2022/01/13 04:38:10 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>
#include <stdint.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	uint64_t const	*longptr;
	uint64_t		char_mask;
	uint64_t		longword;

	while (n && (uint64_t)s & 0b111)
	{
		if (*(char *)s++ == (unsigned char)c)
			return ((void *)--s);
		--n;
	}
	longptr = (uint64_t *)s;
	char_mask = (unsigned char)c * LSB_MASK;
	while (n > 8)
	{
		longword = *longptr ^ char_mask;
		if ((longword - LSB_MASK) & ~longword & MSB_MASK)
			break ;
		longptr++;
		n -= 8;
	}
	s = (const char *)longptr;
	while (n--)
		if (*(char *)s++ == (unsigned char)c)
			return ((void *)--s);
	return (NULL);
}

// void	*ft_memchr(const void *s, int c, size_t n)
// {
// 	while (n && *(unsigned char *)s++ != (unsigned char)c)
// 		n--;
// 	return ((void *)((n != 0) * (uintptr_t)--s));
// }
