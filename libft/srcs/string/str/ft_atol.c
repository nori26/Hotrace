#include "ft_utils.h"
#include <stdbool.h>
#include <limits.h>
#include <errno.h>

static void	skip_space(const char **str)
{
	while (**str == ' ' || ('\t' <= **str && **str <= '\r'))
		(*str)++;
}

static bool	get_sign(const char **str)
{
	bool	is_neg;

	is_neg = false;
	if (**str == '+' || **str == '-')
		is_neg = *(*str)++ == '-';
	return (is_neg);
}

static bool	to_integer(const char *str, long *n, bool is_neg)
{
	unsigned char	next;
	unsigned long	num;
	unsigned long	limit;

	num = 0;
	limit = ft_labs((long [2]){LONG_MAX, LONG_MIN}[is_neg]);
	while ('0' <= *str && *str <= '9')
	{
		next = *str++ - '0';
		if (num > (limit - next) / 10)
		{
			errno = ERANGE;
			*n = (long [2]){LONG_MAX, LONG_MIN}[is_neg];
			return (false);
		}
		num = num * 10 + next;
	}
	*n = (long [2]){num, -(long)(num - 1) - 1}[is_neg];
	return (*str == '\0');
}

bool	ft_atol(const char *str, long *n)
{
	bool	is_neg;

	*n = 0;
	skip_space(&str);
	is_neg = get_sign(&str);
	if (!*str)
		return (false);
	return (to_integer(str, n, is_neg));
}
