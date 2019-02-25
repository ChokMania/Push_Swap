/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:40:01 by lramard           #+#    #+#             */
/*   Updated: 2019/02/25 18:18:32 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

void	ft_lstdel_oklm(t_checke **a, t_checke **begina, int median)
{
	t_checke	*elem;
	t_checke	*tmp;

	elem = *a;
	while (elem && elem->n < median)
		elem = elem->next;
	if (elem)
	{
		*begina = elem;
		*a = elem;
		while (elem)
		{
			if (elem->n >= median)
			{
				tmp = elem->next;
				(*a)->next = elem;
				*a = (*a)->next;
				elem->next = tmp;
			}
			elem = elem->next;
		}
		(*a)->next = NULL;
	}
	*a = *begina;
}

void	ft_display(t_checke *begina, t_ps *comp)
{
	if (begina != NULL)
	{
		while (begina)
		{
			ft_printf("%d\t", begina->n);
			begina = begina->next;
		}
	}
	ft_printf("\n");
	if (comp != NULL)
	{
		ft_printf("mediane : %d\t", comp->median);
		ft_printf("nbblock : %d\t", comp->nbblock);
		ft_printf("size    : %d\n", comp->size);
		ft_printf("\n");
	}
}

void	ft_init_comp(t_ps **comp, t_checke *a, int i)
{

	(*comp)->median = ft_median(a, (*comp)->median);
	(*comp)->nbblock = i + 1;
	(*comp)->size = 0;
	(*comp)->next = (t_ps*)malloc(sizeof(t_ps) * 1);
}

void	ft_sort3(t_checke *a, t_checke *begina)
{
	if (ft_lstl(&a) == 2 && (a)->n > (a)->next->n)
		ft_sa(a, 1);
	if (ft_lstl(&a) >= 3)
	{
		if ((a)->n > (a)->next->n && (a)->next->n > (a)->next->next->n)
		{
			ft_sa(a, 1);
			ft_ra(&a, &begina, 1);
			ft_sa(a, 1);
			ft_rra(&a, &begina, 1);
			ft_sa(a, 1);
		}
		if (((a)->n > (a)->next->n && (a)->next->n < (a)->next->next->n) && (a)->n < (a)->next->next->n)
			ft_sa(a, 1);
		if (((a)->n > (a)->next->n && (a)->next->n < (a)->next->next->n) && (a)->n > (a)->next->next->n)
		{
			ft_sa(a, 1);
			ft_ra(&a, &begina, 1);
			ft_sa(a, 1);
			ft_rra(&a, &begina, 1);
		}
		if (((a)->n < (a)->next->n && (a)->next->n > (a)->next->next->n) && (a)->n > (a)->next->next->n)
		{
			ft_ra(&a, &begina, 1);
			ft_sa(a, 1);
			ft_rra(&a, &begina, 1);
			ft_sa(a, 1);
		}
		if (((a)->n < (a)->next->n && (a)->next->n > (a)->next->next->n) && (a)->n < (a)->next->next->n)
		{
			ft_ra(&a, &begina, 1);
			ft_sa(a, 1);
			ft_rra(&a, &begina, 1);
		}
	}
}


//./push_swap   1 2 3 4 5 6 7 8 9 4512 451 51 16 151 541 431 561 065 104 041 531 165 31 651 peut etre b
void	ft_suite_algo(t_checke **a, t_checke **b, t_ps *comp, t_checke	*finish)
{
	t_ps	*beginc;
	t_ps	*memo;
	t_checke	*beginb;
	t_checke	*begina;
	t_checke	*temp;
	t_checke	*begint;
	int i = -1;
	int k = 0;

	temp = NULL;
	begina = *a;
	beginc = comp;
	beginb = *b;
	while (ft_lst_compare(*a, finish) == 0)
	{
		while (comp->next && comp->next->next)
			comp = comp->next;
		if (comp->next)
		{
			memo = comp;
			comp = comp->next;
		}
		if (comp->size <= 3)
		{
			if (comp->size > 2)
				ft_pa(a, b, &begina, &beginb);
			ft_pa(a, b, &begina, &beginb);
			ft_pa(a, b, &begina, &beginb);
			comp = NULL;
			memo->next = NULL;
			free(comp);
		}
		else
		{
			i = -1;
			k = 0;
			temp = ft_lstndup(*b, comp->size);
			begint = temp;
			while (ft_lstl(&temp) > 3)
			{
				begint = temp;
				comp->median = ft_median(temp, comp->median);
				temp = begint;
				ft_lstdel_oklm(&temp, &begint, comp->median);
				//t on eleve nb < median
			}
			ft_free_lst(temp);
			temp = NULL;
			while (++i < comp->size)
			{
				if ((*b)->n > comp->median)
				{
					ft_pa(a, b, &begina, &beginb);
					comp->size--;
					i--;
				}
				else
				{
					ft_rb(b, &beginb, 1);
					k++;
				}
			}
			while (--k > -1)
				ft_rrb(b, &beginb, 1);
		}
		ft_sort3(*a, begina);
		comp = beginc;
	}
}

t_checke *ft_quicksort(t_checke *a)
{
	t_checke	*b;
	t_checke	*beginb;
	t_ps		*comp;
	t_ps		*beginc;
	t_checke	*begina;
	t_checke	*tmp = NULL;
	t_checke	*finish;
	int			i;
	int			t;
	int			j;

	b = NULL;
	i = 0;
	begina = a;
	beginb = b;
	comp = NULL;
	finish = ft_lstdup(a);
	ft_mergesort(&finish);
	comp = (t_ps*)malloc(sizeof(t_ps) * 1);
	beginc = comp;
	while (a->next)
		a = a->next;
	t = a->n;
	a = begina;
	comp->nbblock = 0;
	while (ft_lstl(&a) > 3)
	{
		j = 0;
		tmp = ft_lstdup(a); // LEAKS
		ft_init_comp(&comp, tmp, i);
		ft_free_lst(tmp);
		tmp = NULL;
		while (a && ft_lstl(&a) > 2)
		{
			if (a->n <= comp->median)
			{
				ft_pbe(&a, &b, &begina, &beginb);
				a = begina;
				comp->size++;
			}
			else
				ft_ra(&a, &begina, 1);
			if (a->n == t)
				j++;
			else if (j != 0)
				break ;
		}
		while (a->next)
			a = a->next;
		t = a->n;
		a = begina;
		b = beginb;
		if (ft_lstl(&a) > 3)
			comp = comp->next;
		i++;
	}
	free(comp->next);
	comp->next = NULL;
	ft_sort3(a, begina);
	comp =  beginc;
	ft_suite_algo(&a, &b, beginc, finish);
	while (b)
		ft_pa(&a, &b, &begina, &beginb);
	/*si ft_pa -> plus de leaks*/
	//ft_free_lst_ps(beginc);
	ft_free_lst(finish);
	return (begina);
}
