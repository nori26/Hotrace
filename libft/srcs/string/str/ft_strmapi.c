/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 06:04:58 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/11/06 07:56:10 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_utils.h"
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len > UINT_MAX)
		return (NULL);
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	ft_strcpy(ret, s);
	if (!f)
		return (ret);
	i = 0;
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	return (ret);
}
