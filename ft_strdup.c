/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:58:34 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/10/19 17:59:29 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_utils.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dest;

	if (!ft_setptr(&dest, malloc(ft_strlen(s) + 1)))
		return (NULL);
	return (ft_strcpy(dest, s));
}
