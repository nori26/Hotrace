#include "gnl_util.h"
#include "ft_list.h"
#include <stdlib.h>
#include <stdint.h>

int	save_to_line(char **line, t_list **save, char *n_ptr)
{
	size_t	size;
	size_t	new_nlen;

	new_nlen = n_ptr - ((t_buf *)((*save)->content))->buf + 1;
	size = new_nlen - ((t_buf *)((*save)->content))->n_len - 1;
	*line = malloc(size + 1);
	if (!*line)
		return (exit_gnl(&((t_buf *)((*save)->content))->start, save));
	till_ln(*line, *save, n_ptr, ((t_buf *)((*save)->content))->n_len);
	(*line)[size] = '\0';
	((t_buf *)((*save)->content))->n_len = new_nlen;
	return (1);
}

char	*till_ln(char *line, t_list *ln_buf, char *n_ptr, size_t buf_offset)
{
	size_t		i;
	uint64_t	*longline;
	t_buf		*content;
	char		*buf;

	content = ln_buf->content;
	buf = content->buf + buf_offset;
	if (!n_ptr)
		n_ptr = content->buf + content->len - 1;
	i = 0;
	if (!((uintptr_t)buf & 0b111))
	{
		longline = (uint64_t *)line;
		while (buf + i * 8 <= n_ptr - 7)
			*longline++ = ((uint64_t *)buf)[i++];
		line = (char *)longline;
		i *= 8;
	}
	while (buf + i <= n_ptr)
		*line++ = buf[i++];
	return (line);
}

static void	buf_to_line(char *line, t_list *end, char *n_ptr, void (*copy)())
{
	t_list	*lst;
	t_list	*prev;

	prev = NULL;
	lst = ((t_buf *)(end->content))->start;
	if (!n_ptr)
		end = end->next;
	while (lst != end)
	{
		copy(&line, lst->content);
		prev = lst;
		lst = lst->next;
	}
	if (!n_ptr)
		return ;
	till_ln(line, end, n_ptr, 0);
	if (prev)
		prev->next = end->next;
	else
		((t_buf *)end->content)->start = ((t_buf *)end->content)->start->next;
}

static void	lst_to_line(char *line, t_list *end, t_list *save, char *n_ptr)
{
	if (save)
		line = till_ln(line, save, NULL, ((t_buf *)(save->content))->n_len);
	if ((uintptr_t)line & 0b111)
		buf_to_line(line, end, n_ptr, copy_byte);
	else
		buf_to_line(line, end, n_ptr, copy_qword);
}

int	make_line(char **line, t_list *end, t_list **save, char *n_ptr)
{
	size_t	size;

	size = line_size(end, *save, n_ptr);
	*line = malloc(size + 1);
	if (!*line)
		return (exit_gnl(&((t_buf *)((end)->content))->start, save));
	lst_to_line(*line, end, *save, n_ptr);
	(*line)[size] = '\0';
	if (n_ptr)
	{
		ft_lstdelone(*save, free);
		*save = end;
	}
	else
		exit_gnl(&((t_buf *)((end)->content))->start, save);
	return (!!n_ptr);
}
