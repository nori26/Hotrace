#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "ft_sort.h"

static void	swap_bytes(uint8_t *a, uint8_t *b, size_t size)
{
	uint8_t	t;
	size_t	i;

	i = 0;
	while (i < size)
	{
		t = a[i];
		a[i] = b[i];
		b[i] = t;
		i++;
	}
}

static void	swap_median_of_3(t_sort *sort)
{
	if (sort->cmp(sort->low, sort->mid) > 0)
		swap_bytes(sort->low, sort->mid, sort->size);
	if (sort->cmp(sort->mid, sort->high) > 0)
	{
		swap_bytes(sort->mid, sort->high, sort->size);
		if (sort->cmp(sort->low, sort->mid) > 0)
			swap_bytes(sort->low, sort->mid, sort->size);
	}
}

static uint8_t	*swap_all(t_sort *sort)
{
	while (true)
	{
		while (sort->cmp(sort->low, sort->mid) < 0)
			sort->low += sort->size;
		while (sort->cmp(sort->mid, sort->high) < 0)
			sort->high -= sort->size;
		if (sort->low >= sort->high)
			break ;
		swap_bytes(sort->low, sort->high, sort->size);
		if (sort->low == sort->mid)
			sort->mid = sort->high;
		else if (sort->high == sort->mid)
			sort->mid = sort->low;
		sort->low += sort->size;
		sort->high -= sort->size;
	}
	return (sort->high + sort->size);
}

static void	*partition(void *base, size_t nmemb, size_t size, t_compare cmp)
{
	t_sort	sort;

	if (nmemb <= 1)
		return (base + size);
	sort.low = base;
	sort.high = base + (nmemb - 1) * size;
	sort.mid = base + ((nmemb - 1) / 2) * size;
	sort.size = size;
	sort.cmp = cmp;
	swap_median_of_3(&sort);
	return (swap_all(&sort));
}

void	ft_qsort(void *base, size_t nmemb, size_t size, t_compare cmp)
{
	void	*pivot;
	size_t	nmemb_low;
	size_t	nmemb_high;

	if (nmemb <= 1)
		return ;
	pivot = partition(base, nmemb, size, cmp);
	nmemb_low = (pivot - base) / size;
	nmemb_high = nmemb - nmemb_low;
	ft_qsort(base, nmemb_low, size, cmp);
	ft_qsort(pivot, nmemb_high, size, cmp);
}
