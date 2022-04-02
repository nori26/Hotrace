#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "ft_list.h"
#include "hotrace.h"

static bool	read_into_lst(t_clist *lst, bool (*is_empty)())
{
	int		ret;
	char	*line;

	ret = 1;
	while (ret)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret < 0)
		{
			hr_puterr("gnl");
			return (false);
		}
		if (is_empty(line, ret))
		{
			free(line);
			break ;
		}
		if (!ft_clstnew_add_back(lst, line))
		{
			free(line);
			hr_puterr("lstnew");
			return (false);
		}
	}
	return (true);
}

static bool	is_empty_for_kvlst(char *line, int ret)
{
	(void)ret;
	return (line[0] == '\0');
}

static bool	is_empty_for_keylst(char *line, int ret)
{
	return (ret == 0 && line[0] == '\0');
}

bool	read_into_kvlst(t_clist *kvlst)
{
	return (read_into_lst(kvlst, is_empty_for_kvlst));
}

bool	read_into_keylst(t_clist *keylst)
{
	return (read_into_lst(keylst, is_empty_for_keylst));
}
