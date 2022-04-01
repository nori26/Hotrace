#include "ft_io.h"

void	ft_puterr(char **msgs)
{
	ft_putstrs_fd(msgs, 2);
	ft_putchar_fd('\n', 2);
}
