/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 04:11:35 by nosuzuki          #+#    #+#             */
/*   Updated: 2022/01/26 10:47:56 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_free.h"
#include "ft_utils.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	count_blocks(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	len = !!s[i] + 1;
	while (s[i])
		len += (s[i++] == c && s[i] != c && s[i]);
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	*p;
	char	**ret;

	if (!s || !ft_setptr(&ret, malloc(sizeof(char *) * count_blocks(s, c))))
		return (NULL);
	i = 0;
	while (*s)
	{
		p = ft_strchr(s, c);
		if (p)
			len = p - s;
		else
			len = ft_strlen(s);
		if (len && !ft_setptr(&ret[i], ft_substr(s, 0, len)))
			return (ft_free_strs(&ret));
		if (len)
			s += ft_strlen(ret[i]);
		s += !len;
		i += !!len;
	}
	ret[i] = NULL;
	return (ret);
}
