/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:41:17 by judumay           #+#    #+#             */
/*   Updated: 2019/02/20 12:01:20 by judumay          ###   ########.fr       */
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
		//free(p);//MOLO-MOLO
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
	int	j;
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
	if (*a)
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
	if (*b)
	{
		t = (*b);
		*beginb = (*b)->next;
		(*b) = (*b)->next;
		while ((*b)->next)
			(*b) = (*b)->next;
		(*b)->next = t;
		(*b)->next->next = NULL;
	}
	*b = *beginb;
}

/*
void	ft_rr(t_check *a, t_check *b)
{
}

void	ft_rra(t_check *a)
{
}

void	ft_rrb(t_check *b)
{
}

void	ft_rrr(t_check *a, t_check *b)
{
}
*/

t_check		*ft_read_inst(t_check *a, char *str)
{
	t_check		*b;
	t_check		*begina;
	t_check		*beginb;

	(void)str;
	b = (t_check*)malloc(sizeof(t_check) * 1);
	b->n = 42;
	b->next = (t_check*)malloc(sizeof(t_check) * 1);
	b->next->n = 72;
	b->next->next = (t_check*)malloc(sizeof(t_check) * 1);
	b->next->next->n = 102;
	b->next->next->next = NULL;
	begina = a;
	beginb = b;
	ft_sa(a);
	ft_display(a, b);
	ft_sb(b);
	ft_display(a, b);
	ft_ss(a, b);
	ft_display(a, b);
	ft_pa(&a, &b, &begina);
	ft_display(a, b);
	ft_pb(&a, &b, &beginb);
	ft_display(a, b);
	ft_ra(&a, &begina);
	ft_display(a, b);
	ft_rb(&b, &beginb);
	ft_display(a, b);
	b = beginb;
	ft_free_lst(b);
	return (begina);
}
