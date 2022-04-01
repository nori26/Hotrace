/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:36:23 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/10/19 18:11:05 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	l;

	l = ft_strlen(s) + 1;
	while (l)
		if (s[--l] == (char)c)
			return ((char *)s + l);
	return (NULL);
}
