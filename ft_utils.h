#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <stdint.h>
typedef unsigned long	t_ulong;
typedef unsigned char	t_uchar;

int		ft_setptr(void *dest, void *p);
int		ft_utoa_len(uint32_t n, char *s, int len);
int64_t	ft_min(int64_t a, int64_t b);
t_ulong	ft_labs(long n);
void	ft_free_assign(void **dest, void *src);

#endif
