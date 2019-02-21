#include <ft_push_swap.h>
#include <stdlib.h>

int		ft_median(t_checke *p, int n)
{
	t_checke	*t;
	int			i;

	t = p;
	ft_mergesort(&p);
	p = t;
	i = ft_lstl(p);
	p = t;
	n = (i % 2 == 0) ? i / 2 - 1: i / 2;
	i = -1;
	while (++i < n)
		p = p->next;
	n = p->n;
	return (n);
}
