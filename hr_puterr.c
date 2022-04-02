#include <errno.h>
#include <unistd.h>
#include <string.h>
#include "ft_io.h"

void	hr_puterr(char *place)
{
	ft_putstr_fd(place, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
}
