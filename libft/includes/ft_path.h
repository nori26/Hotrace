#ifndef FT_PATH_H
# define FT_PATH_H
# include <stdbool.h>
typedef struct s_clist	t_clist;
typedef void			(*t_popdel)(t_clist *);

bool	ft_is_relative_path(const char *path);
char	*ft_create_normalized(t_clist *tokens);
char	*ft_join_path(char *parent, char *child);
char	*ft_normalize_path(char *path);
char	*normalize_absolute(char *path);
char	*normalize_relative(char *path);
void	ft_remove_first_char(char *str);
void	ft_remove_first_slash(char *str);
void	ft_resolve_relative_path(t_clist *tokens, t_popdel popdel);
void	pop_for_absolute(t_clist *now);
void	pop_for_relative(t_clist *now);

#endif
