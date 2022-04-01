#include <stdbool.h>
#include "ft_string.h"
#include "ft_getopt.h"

void	charset_to_table(const char *set, bool *ascii_table)
{
	ft_bzero(ascii_table, OPT_CHAR_MAX * sizeof(bool));
	while (*set)
		ascii_table[(unsigned char)*set++] = true;
}

void	ft_init_argopt(t_argopt *argopt, char **argv, char *optstr)
{
	argopt->argv = argv;
	argopt->argvidx = 1;
	argopt->stridx = 0;
	charset_to_table(optstr, argopt->opttable);
}

int	ft_getopt(t_argopt *arg)
{
	char	*str;

	str = arg->argv[arg->argvidx];
	if (!str || (!arg->stridx && !ft_is_option(str, arg->opttable)))
		return (-1);
	arg->stridx++;
	if (!str[arg->stridx])
	{
		arg->stridx = 0;
		arg->argvidx++;
		return (0);
	}
	return ((unsigned char)str[arg->stridx]);
}
