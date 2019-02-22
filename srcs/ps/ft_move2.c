#include <ft_push_swap.h>
#include <stdlib.h>

void	ft_sa(t_checke *a)
{
	int		t1;

	if (ft_lstl(&a) <= 1)
		return ;
	t1 = a->n;
	a->n = a->next->n;
	a->next->n = t1;
}

void	ft_sb(t_checke *b)
{
	int		t1;

	if (ft_lstl(&b) <= 1)
		return ;
	t1 = b->n;
	b->n = b->next->n;
	b->next->n = t1;
}

void	ft_ss(t_checke *a, t_checke *b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_pa(t_checke **a, t_checke **b, t_checke **begina, t_checke **beginb)
{
	t_checke	*t;

	if (*b)
	{
		t = *b;
		*b = (*b)->next;
		*beginb = *b;
		t->next = (*a);
		*a = t;
		*begina = *a;
	}
}

void	ft_pbe(t_checke **a, t_checke **b, t_checke **begina, t_checke **beginb)
{
	t_checke	*t;

	if (*a)
	{
		t = *a;
		*a = (*a)->next;
		*begina = *a;
		t->next = (*b);
		*b = t;
		*beginb = *b;
	}
}
