/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 06:16:41 by nosuzuki          #+#    #+#             */
/*   Updated: 2022/01/23 10:36:20 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>
#include <stdint.h>

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
