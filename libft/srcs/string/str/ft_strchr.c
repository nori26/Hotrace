/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 09:11:28 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/11/30 06:21:31 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	return ((char *)((*s == (char)c) * (uintptr_t)s));
}
