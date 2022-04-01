/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:32:54 by nosuzuki          #+#    #+#             */
/*   Updated: 2022/03/21 18:22:49 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	slen;

	if (!s || !len)
		return (ft_strdup(""));
	slen = ft_strnlen(s, start);
	if (slen < start)
		return (ft_strdup(""));
	return (ft_strndup(s + start, len));
}
