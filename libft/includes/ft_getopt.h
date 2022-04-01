#ifndef FT_GETOPT_H
# define FT_GETOPT_H
# include <stdbool.h>
# define OPT_CHAR_MAX 256
typedef struct s_argopt
{
	char	**argv;
	size_t	argvidx;
	size_t	stridx;
	bool	opttable[OPT_CHAR_MAX];
}	t_argopt;

bool	ft_is_option(char *str, bool *table);
bool	is_in_table(char c, bool *table);
bool	is_option_chars(char *str, bool *table);
int		ft_getopt(t_argopt *arg);
void	charset_to_table(const char *set, bool *ascii_table);
void	ft_init_argopt(t_argopt *argopt, char **argv, char *optstr);

#endif
