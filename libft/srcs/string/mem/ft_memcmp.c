/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:19:45 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/10/19 17:46:20 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n && *(unsigned char *)s1++ == *(unsigned char *)s2++)
		n--;
	return ((n != 0) * (*(unsigned char *)--s1 - *(unsigned char *)--s2));
}
