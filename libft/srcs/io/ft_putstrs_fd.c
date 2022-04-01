#include "ft_io.h"

void	ft_putstrs_fd(char **strs, int fd)
{
	while (*strs)
	{
		ft_putstr_fd(*strs, fd);
		strs++;
	}
}
