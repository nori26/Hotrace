/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:39:41 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/11/06 07:56:28 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n || (!*s1 && !*s2))
		return (0);
	while (n && *s1++ == *s2++ && (*s1 || *s2))
		n--;
	return ((n != 0) * (*(unsigned char *)--s1 - *(unsigned char *)--s2));
}
