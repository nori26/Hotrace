#include "get_next_line.h"
#include "ft_list.h"
#include "ft_string.h"
#include "ft_utils.h"
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

static int	lst_init(t_list **lst, t_list *start)
{
	t_buf	*content;

	content = malloc(sizeof(t_buf));
	*lst = ft_lstnew(content);
	if (!content || !lst)
		return (1);
	((t_buf *)((*lst)->content))->start = start;
	return (0);
}

static void	lst_set_value(t_buf *content, size_t len, t_list *start)
{
	content->total_len = len;
	content->start = start;
}

static int	read_and_makeline(int fd, char **line, t_list **save, t_list **lst)
{
	char	*n_ptr;
	t_buf	*content;

	while (1)
	{
		content = (*lst)->content;
		content->len = read(fd, content->buf, BUFFER_SIZE);
		if (content->len == -1)
			break ;
		if (!content->len)
			return (make_line(line, *lst, save, NULL));
		content->total_len += content->len;
		if (ft_setptr(&n_ptr, ft_memchr(content->buf, '\n', content->len)))
			return (make_line(line, *lst, save, n_ptr));
		if (!(*lst)->next && lst_init(&((*lst)->next), content->start))
			break ;
		*lst = (*lst)->next;
		lst_set_value((*lst)->content, content->total_len, content->start);
	}
	return (exit_gnl(&((t_buf *)((*lst)->content))->start, save));
}

static int	gnl_init(t_list **save, t_list **lst, char **line)
{
	t_buf	*content;
	char	*n_ptr;

	if (!line)
	{
		if (*save)
			exit_gnl(&((t_buf *)((*save)->content))->start, save);
		return (-1);
	}
	if (*save)
	{
		content = (*save)->content;
		n_ptr = ft_memchr(content->buf + content->n_len, '\n',
				content->len - content->n_len);
		if (n_ptr)
			return (save_to_line(line, save, n_ptr));
		*lst = ((t_buf *)((*save)->content))->start;
	}
	if ((!*save || !*lst) && lst_init(lst, NULL))
		return (-1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*save;
	t_list			*lst;
	int				ret;

	ret = gnl_init(&save, &lst, line);
	if (ret)
		return (ret);
	lst_set_value(lst->content, 0, lst);
	return (read_and_makeline(fd, line, &save, &lst));
}
