/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 05:17:05 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/10/22 22:16:47 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>
#include <stdint.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	ascii[256];

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	ft_bzero(ascii, sizeof(ascii));
	while (*set)
		ascii[(uint8_t)*set++] = 1;
	while (*s1 && ascii[(uint8_t)*s1])
		s1++;
	len = ft_strlen(s1);
	while (len && ascii[(uint8_t)*(s1 + len - 1)])
		len--;
	return (ft_substr(s1, 0, len));
}
