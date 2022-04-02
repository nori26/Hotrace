/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 01:08:37 by nosuzuki          #+#    #+#             */
/*   Updated: 2022/01/23 10:41:02 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>
#include <stdint.h>

void	*ft_memset(void *s, int c, size_t n)
{
	const uint64_t		longvalue = (unsigned char)c * LSB_MASK;
	void				*dest;
	uint64_t			*longptr;

	dest = s;
	while (n && (uintptr_t)dest & 0b111)
	{
		*(unsigned char *)dest++ = (unsigned char)c;
		n--;
	}
	longptr = dest;
	while (n >= sizeof(uint64_t))
	{
		*longptr++ = longvalue;
		n -= sizeof(uint64_t);
	}
	dest = longptr;
	while (n--)
		*(unsigned char *)dest++ = (unsigned char)c;
	return (s);
}
