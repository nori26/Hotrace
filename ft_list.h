#ifndef FT_LIST_H
# define FT_LIST_H
# include <stddef.h>
# include <stdbool.h>
typedef struct s_list	t_list;
typedef struct s_clist	t_clist;
struct		s_list
{
	void	*content;
	t_list	*next;
};
struct		s_clist
{
	void	*data;
	t_clist	*next;
	t_clist	*prev;
};

bool	ft_clst_isend(t_clist *lst);
t_clist	*ft_clstfirst(t_clist *lst);
t_clist	*ft_clstnew(void *data);
t_clist	*ft_clstnew_add_back(t_clist *lst, void *content);
t_list	*del_set(t_list *lst, t_list *next, void (*del)(void*));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstnew_add_front(t_list **lst, void *content);
void	ft_clst_clear(t_clist **lst, void (*del)());
void	ft_clst_insert(t_clist *lst, t_clist *newlst);
void	ft_clst_link(t_clist *front, t_clist *back);
void	ft_clstadd_back(t_clist *sentinel, t_clist *newlst);
void	ft_clstdelone(t_clist *lst, void (*del)(void*));
void	ft_lstadd_front(t_list **lst, t_list *newlst);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));

#endif
