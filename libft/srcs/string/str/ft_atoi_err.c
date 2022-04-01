#include <limits.h>
#include <stdint.h>

int	ft_atoi_err(char *s, int *i)
{
	char		sign;
	uint64_t	num;

	if (!s || !*s)
		return (1);
	num = 0;
	sign = 1;
	if (*s == '-' && '0' <= s[1] && s[1] <= '9')
		sign = -!!*s++;
	if (*s == '0' && s[1])
		return (1);
	while ('0' <= *s && *s <= '9')
	{
		num = num * 10 + *s++ - '0';
		if ((sign > 0 && num > INT_MAX) || (sign < 0 && num > -(long)INT_MIN))
			return (1);
	}
	*i = sign * (int)num;
	return (*s);
}
