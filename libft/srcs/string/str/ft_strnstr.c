/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:30:40 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/10/19 18:10:30 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l;

	if (!*little)
		return ((char *)big);
	i = 0;
	l = ft_strlen(little);
	while (i + l - 1 < len && big[i])
		if (!(ft_strncmp(&big[i++], little, l)))
			return ((char *)&big[i - 1]);
	return (NULL);
}
