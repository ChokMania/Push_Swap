#include <ft_push_swap.h>

void		ft_error(t_checke *p)
{
	write(2, "\033[31mError\033[37m\n", 17);
	free(p->next);
	exit(0);
}

int			ft_lstl(t_checke **list)
{
	int			j;
	t_checke	*t;

	t = *list;
	if (t)
	{
		j = 0;
		while (t)
		{
			t = t->next;
			j++;
		}
		return (j);
	}
	else
		return (0);
}

t_checke	*ft_lstdup(t_checke *t)
{
	t_checke	*new;
	t_checke	*begin;

	if (!(new = (t_checke *)malloc(sizeof(t_checke))))
		return (t);
	begin = new;
	while (t)
	{
		new->n = t->n;
		if (!(new->next = (t_checke *)malloc(sizeof(t_checke))))
			return (t);
		t = t->next;
		if (t)
			new = new->next;
	}
	free(new->next);
	new->next = NULL;
	new = begin;
	return (new);
}

int		ft_lst_compare(t_checke *p, t_checke *finish)
{
	while (p)
	{
		if (p->n != finish->n)
			return (0);
		p = p->next;
		finish = finish->next;
	}
	return (1);
}

void	ft_free_lst(t_checke *p)
{
	if (p->next)
		ft_free_lst(p->next);
	free(p);
}

void	ft_free_lst_ps(t_ps *p)
{
	if (p->next)
		ft_free_lst_ps(p->next);
	free(p);
}