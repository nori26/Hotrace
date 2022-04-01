/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:14:09 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/10/19 21:49:13 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <limits.h>
#include <errno.h>

int	ft_atoi(const char *str)
{
	t_uchar	sign;
	t_uchar	next;
	t_ulong	num;
	t_ulong	limit;

	num = 0;
	sign = 0;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
		sign = *str++ == '-';
	limit = ft_labs((long [2]){LONG_MAX, LONG_MIN}[sign]);
	while ('0' <= *str && *str <= '9')
	{
		next = *str++ - '0';
		if (num > (limit - next) / 10)
		{
			errno = ERANGE;
			return ((long [2]){LONG_MAX, LONG_MIN}[sign]);
		}
		num = num * 10 + next;
	}
	return ((long [2]){num, -(long)(num - 1) - 1}[sign]);
}
