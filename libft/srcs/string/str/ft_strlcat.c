/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:22:17 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/11/27 13:09:33 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	dlen = ft_strnlen(dst, dstsize);
	if (dstsize == dlen)
		return (dstsize + slen);
	dst += dlen;
	while (--dstsize > dlen && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (dlen + slen);
}
