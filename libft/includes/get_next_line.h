/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 06:54:19 by nosuzuki          #+#    #+#             */
/*   Updated: 2022/01/31 08:48:49 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define BUF_SIZE BUFFER_SIZE
# include <sys/types.h>
typedef struct s_list	t_list;
typedef struct s_buf
{
	char	buf[BUFFER_SIZE];
	ssize_t	len;
	size_t	total_len;
	ssize_t	n_len;
	t_list	*start;
}t_buf;

char	*till_ln(char *line, t_list *ln_buf, char *n_ptr, size_t buf_offset);
int		exit_gnl(t_list **lst, t_list **save);
int		get_next_line(int fd, char **line);
int		make_line(char **line, t_list *end, t_list **save, char *n_ptr);
int		save_to_line(char **line, t_list **save, char *n_ptr);
size_t	line_size(t_list *end, t_list *save, char *n_ptr);
void	copy_byte(char **line, t_buf *content);
void	copy_qword(char **line, t_buf *content);
void	gnl_destroy(void);

#endif
