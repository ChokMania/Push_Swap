/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:41:17 by judumay           #+#    #+#             */
/*   Updated: 2019/02/20 17:12:03 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>
#include <stdlib.h>

void	ft_display(t_check *a, t_check *b)
{
	while (a)
	{
		ft_printf("\033[31ma : %d\t\033[0m", a->n);
		a = a->next;
	}
	while (b)
	{
		ft_printf("\033[36mb : %d\t\033[0m", b->n);
		b = b->next;
	}
	ft_printf("\n");
}

t_check	*ft_create_eleme(int n)
{
	t_check *p;

	p = (t_check*)malloc(sizeof(t_check) * 1);
	if (p)
	{
		p->next = NULL;
		p->n = n;
	}
	return (p);
}

t_check	*ft_list_push_fronte(t_check **begin_list, int n)
{
	t_check *p;

	if (*begin_list)
	{
		p = ft_create_eleme(n);
		p->next = *begin_list;
		*begin_list = p;
	}
	else
		*begin_list = ft_create_eleme(n);
	return (*begin_list);
}

void	ft_del_first(t_check **begin_list)
{
	t_check *p;

	if (*begin_list)
	{
		p = (*begin_list)->next;
		(*begin_list) = p;
	}
}

int		ft_lstlene(t_check **list)
{
	int		j;
	t_check	*tmp;

	if (list != NULL)
	{
		tmp = *list;
		j = 0;
		while (tmp != NULL)
		{
			tmp = tmp->next;
			j++;
		}
		return (j);
	}
	else
		return (0);
}

void	ft_sa(t_check *a)
{
	int		t1;
	int		t2;
	t_check *begin;

	begin = a;
	if ((ft_lstlene(&begin) == 1 || ft_lstlene(&begin) == 0)
	&& ft_printf("ALONE\n"))
		return ;
	t1 = a->n;
	while (a->next)
		a = a->next;
	t2 = a->n;
	a->n = t1;
	a = begin;
	a->n = t2;
}

void	ft_sb(t_check *b)
{
	int		t1;
	int		t2;
	t_check *begin;

	begin = b;
	if ((ft_lstlene(&begin) == 1 || ft_lstlene(&begin) == 0)
	&& ft_printf("ALONE\n"))
		return ;
	t1 = b->n;
	while (b->next)
		b = b->next;
	t2 = b->n;
	b->n = t1;
	b = begin;
	b->n = t2;
}

void	ft_ss(t_check *a, t_check *b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_pa(t_check **a, t_check **b, t_check **begina)
{
	if ((ft_lstlene(b) == 0) && ft_printf("ALONE\n"))
		return ;
	*begina = ft_list_push_fronte(a, (*b)->n);
	ft_del_first(b);
}

void	ft_pb(t_check **a, t_check **b, t_check **beginb)
{
	if ((ft_lstlene(a) == 0) && ft_printf("ALONE\n"))
		return ;
	*beginb = ft_list_push_fronte(b, (*a)->n);
	ft_del_first(a);
}

void	ft_ra(t_check **a, t_check **begina)
{
	t_check	*t;

	t = NULL;
	if ((*a)->next)
	{
		t = (*a);
		*begina = (*a)->next;
		(*a) = (*a)->next;
		while ((*a)->next)
			(*a) = (*a)->next;
		(*a)->next = t;
		(*a)->next->next = NULL;
	}
	*a = *begina;
}

void	ft_rb(t_check **b, t_check **beginb)
{
	t_check	*t;

	t = NULL;
	if ((*b)->next)
	{
		t = (*b);
		*beginb = (*b)->next;
		(*b) = (*b)->next;
		while ((*b)->next)
			(*b) = (*b)->next;
		(*b)->next = t;
		(*b)->next->next = NULL;
		*b = *beginb;
	}
}

void	ft_rr(t_check **a, t_check **b, t_check **begina, t_check **beginb)
{
	ft_ra(a, begina);
	ft_rb(b, beginb);
}

void	ft_rra(t_check **a, t_check **begina)
{
	t_check	*t;

	t = NULL;
	if ((*a)->next)
	{
		while ((*a)->next->next)
			*a = (*a)->next;
		t = (*a)->next;
		(*a)->next = NULL;
		*a = *begina;
		t->next = *a;
		*begina = t;
		*a = *begina;
	}
}

void	ft_rrb(t_check **b, t_check **beginb)
{
	t_check	*t;

	t = NULL;
	if ((*b)->next)
	{
		while ((*b)->next->next)
			*b = (*b)->next;
		t = (*b)->next;
		(*b)->next = NULL;
		*b = *beginb;
		t->next = *b;
		*beginb = t;
		*b = *beginb;
	}
}

void	ft_rrr(t_check **a, t_check **b, t_check **begina, t_check **beginb)
{
	ft_rra(a, begina);
	ft_rrb(b, beginb);
}

t_check	*ft_apply(char str[1000][4], t_check **a)
{
	t_check		*b;
	t_check		*begina;
	t_check		*beginb;
	int			i;

	b = NULL;
	i = 0;
	begina = *a;
	beginb = b;
	while (str[i][0] != 0)
	{
		!ft_strcmp(str[i], "sa\n") ? ft_sa(*a) : 0;
		!ft_strcmp(str[i], "sb\n") ? ft_sb(b) : 0;
		!ft_strcmp(str[i], "ss\n") ? ft_ss(*a, b) : 0;
		!ft_strcmp(str[i], "pa\n") ? ft_pa(a, &b, &begina) : 0;
		!ft_strcmp(str[i], "pb\n") ? ft_pb(a, &b, &beginb) : 0;
		!ft_strcmp(str[i], "ra\n") ? ft_ra(a, &begina) : 0;
		!ft_strcmp(str[i], "rb\n") ? ft_rb(&b, &beginb) : 0;
		!ft_strcmp(str[i], "rr\n") ? ft_rr(a, &b, &begina, &beginb) : 0;
		!ft_strcmp(str[i], "rra\n") ? ft_rra(a, &begina) : 0;
		!ft_strcmp(str[i], "rrb\n") ? ft_rrb(&b, &beginb) : 0;
		!ft_strcmp(str[i], "rrr\n") ? ft_rrr(a, &b, &begina, &beginb) : 0;
		i++;
	}
	b = beginb;
	ft_display(*a, b);
	if (b)
		ft_free_lst(b);
	return (begina);
}

t_check	*ft_read_inst(t_check *a, char str[1000][4])
{
	a = ft_apply(str, &a);
	return (a);
}
