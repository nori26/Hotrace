#include "get_next_line.h"
#include <unistd.h>
#include <stddef.h>

void	gnl_destroy(void)
{
	get_next_line(STDIN_FILENO, NULL);
}
