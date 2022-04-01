/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:40:29 by nosuzuki          #+#    #+#             */
/*   Updated: 2022/01/31 08:13:28 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_utils.h"
#include <unistd.h>
#include <stdint.h>
#include <limits.h>

void	ft_putnbr_fd(int n, int fd)
{
	int			len;
	char		s[32];
	uint32_t	u;

	u = ft_labs(n);
	if (n < 0)
		s[0] = '-';
	len = ft_utoa_len(u, s, n < 0);
	write(fd, s, len);
}
