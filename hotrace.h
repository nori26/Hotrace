#ifndef HOTRACE_H
# define HOTRACE_H

typedef struct s_hash	t_hash;
typedef struct s_clist	t_clist;

typedef struct hotrace
{
	t_hash	*dict;
	t_clist	*kvlst;
	t_clist	*keylst;
}	t_hotrace;

bool	read_into_kvlst(t_clist *kvlst);
bool	read_into_keylst(t_clist *keylst);
void	hr_puterr(char *place);
void	print_values_of_keylst(t_hotrace *hr);

#endif
