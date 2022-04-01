#include "get_next_line.h"
#include "ft_list.h"
#include <stdint.h>
#include <stdlib.h>

static size_t	bufs_len(t_list *end, char *n_ptr)
{
	size_t	size;
	t_buf	*content;

	content = end->content;
	size = content->total_len;
	if (!n_ptr)
		return (size);
	content->n_len = n_ptr - content->buf + 1;
	size -= content->len - (content->n_len - 1);
	return (size);
}

size_t	line_size(t_list *end, t_list *save, char *n_ptr)
{
	size_t	size;

	size = bufs_len(end, n_ptr);
	if (save)
		size += ((t_buf *)(save->content))->len
			- ((t_buf *)(save->content))->n_len;
	return (size);
}

void	copy_byte(char **line, t_buf *content)
{
	ssize_t	i;

	i = 0;
	while (i < content->len)
		*(*line)++ = content->buf[i++];
}

void	copy_qword(char **line, t_buf *content)
{
	ssize_t		i;
	uint64_t	*longline;

	i = 0;
	longline = (uint64_t *)*line;
	while (content->len - i * 8 > 7)
		*longline++ = ((uint64_t *)content->buf)[i++];
	*line = (char *)longline;
	i *= 8;
	while (i < content->len)
		*(*line)++ = content->buf[i++];
}

int	exit_gnl(t_list **lst, t_list **save)
{
	t_list	*tmp;

	tmp = *lst;
	ft_lstclear(&tmp, free);
	ft_lstdelone(*save, free);
	*save = NULL;
	return (-1);
}
