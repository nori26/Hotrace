/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fastrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 05:41:51 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/10/19 17:45:35 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdint.h>

size_t	ft_fastrlen(const char *str)
{
	uint64_t		longvalue;
	uint64_t const	*longptr;
	char const		*char_tmp;

	char_tmp = str;
	while ((uint64_t)char_tmp & 0b111)
		if (!*char_tmp++)
			return (--char_tmp - str);
	longptr = (uint64_t *)char_tmp;
	while (1)
	{
		longvalue = *longptr++;
		if (((longvalue - LSB_MASK) & ~longvalue & MSB_MASK))
		{
			char_tmp = (const char *)(longptr - 1);
			while (*char_tmp)
				char_tmp++;
			return (char_tmp - str);
		}
	}
}
