/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:10:48 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/10/19 17:39:11 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_utils.h"
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

static	int	nbr(uint32_t n, char sign, char **ret, int len)
{
	len++;
	if (n > 9)
	{
		len = nbr(n / 10, sign, ret, len);
		if (len < 0)
			return (-1);
	}
	if (n < 10)
	{
		if (!ft_setptr(ret, malloc(len + sign + 1)))
			return (-1);
		(*ret)[len + sign] = '\0';
		len = 0;
		if (sign)
			(*ret)[len++] = '-';
	}
	(*ret)[len++] = n % 10 + '0';
	return (len);
}

char	*ft_itoa(int n)
{
	char		*ret;
	uint32_t	u;

	u = n;
	if (u > INT_MAX)
		u = ~u + 1;
	if (nbr(u, n < 0, &ret, 0) < 0)
		return (NULL);
	return (ret);
}
