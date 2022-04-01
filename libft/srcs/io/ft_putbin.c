#include "ft_io.h"
#include <limits.h>
#include <unistd.h>

static void	make_bin(size_t n, char *box)
{
	size_t	i;
	size_t	mask;

	i = 0;
	mask = (size_t)1 << (sizeof(size_t) * CHAR_BIT - 1);
	while (mask)
	{
		box[i++] = !!(n & mask) + '0';
		mask >>= 1;
	}
	box[i] = '\0';
}

void	ft_putbin(size_t n)
{
	int		i;
	char	s[65];

	make_bin(n, s);
	i = 0;
	while (s[i])
	{
		if (i && !(i % 8))
			ft_putstr_fd(" | ", 1);
		else if (i && !(i % 4))
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
