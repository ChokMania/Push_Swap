/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:40:01 by lramard           #+#    #+#             */
/*   Updated: 2019/02/28 15:39:11 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

int			ft_count(int median, t_begin begin)
{
	int i;
	t_checke *beg;

	i = 0;
	beg = begin.beginb;
	while (begin.beginb)
	{
		if (begin.beginb->n > median)
			i++;
		begin.beginb = begin.beginb->next;
	}
	begin.beginb = beg;
	return (i);
}

void		ft_find(t_checke *begina, t_checke *temp, int tab[])
{
	int			i;
	int			len;
	t_checke	*begint;

	begint = temp;
	i = 0;
	len = 0;
	while (begina)
	{
		temp = begint;
		while (temp)
		{
			if (temp->n == begina->n)
				tab[i++] = len;
			temp = temp->next;
		}
		begina = begina->next;
		len++;
	}
}

void		ft_do_rotate(t_begin *begin, t_checke **b, t_checke *temp, t_ps **comp, t_checke **a)
{
	int			i;
	//int			tab[ft_lstl(&temp)];
	t_checke 	*begb;

	temp = NULL;
	i = 3;
	begb = begin->beginb;
	while (i > 0)
	{
		if ((*b)->n >= (*comp)->median)
		{
			ft_pa(a, b, &begin->begina, &begin->beginb);
			(*comp)->size--;
			i--;
		}
		else
		{
			//ft_find(begin->begina, temp, tab);
			//if (tab[0] > ft_lstl(b) / 2)
			//	ft_rrb(b, &begin->beginb, 1);
			//else
				ft_rb(b, &begin->beginb, 1);
		}
	}
}

void		ft_split_algo(t_ps **comp, t_checke **b, t_checke **a,
	t_begin *begin)
{
	int			i;
	int			k;
	t_checke	*temp;
	t_checke	*begint;

	temp = ft_lstdup(*b);
	begint = temp;
	k = 0;
	i = -1;
	while (ft_lstl(&temp) > 3)
	{
		(*comp)->median = ft_median(temp, (*comp)->median);
		ft_lstdel_oklm(&temp, &begint, (*comp)->median);
	}
	//i = 3;
	ft_do_rotate(begin, b, temp, comp, a);
	/*while (i > 0)
	{
		if ((*b)->n >= (*comp)->median)
		{
			ft_pa(a, b, &begin->begina, &begin->beginb);
			(*comp)->size--;
			i--;
		}
		else
		{
			ft_rb(b, &begin->beginb, 1);
		}
	}*/
}

void		ft_suite_algo(t_checke *a, t_checke *b,
	t_ps *comp, t_checke *finish)
{
	t_ps		*memo;
	t_checke	*temp;
	t_checke	*begint;
	t_begin		begin;

	temp = NULL;
	begint = temp;
	ft_init_begin(&begin, a, b, comp);
	while (begin.begina->n != finish->n)
	{
		comp = begin.beginc;
		while (comp->next && comp->next->next)
			comp = comp->next;
		if (comp->next)
		{
			memo = comp;
			comp = comp->next;
		}
		if (comp->size <= 3)
		{
			temp = ft_lstdup(b);
			begint = temp;
			if (ft_lstl(&b) <= 3)
			{
				ft_lstl(&b) > 2 ? ft_pa(&a, &b, &begin.begina, &begin.beginb): 0;
				ft_lstl(&b) == 2 ? ft_pa(&a, &b, &begin.begina, &begin.beginb) : 0;
				ft_pa(&a, &b, &begin.begina, &begin.beginb);
				ft_sort3(a, begin.begina);
				return ;
			}
			if (comp->size == 3 || comp->size == 2)
			{
				while (ft_lstl(&temp) > comp->size)
				{
					comp->median = ft_median(temp, comp->median);
					ft_lstdel_oklm(&temp, &begint, comp->median);
				}
			}
			if (comp->size == 1)
			{
				comp->median = temp->n;
				while (temp)
				{
					if (temp->n > comp->median)
						comp->median = temp->n;
					temp = temp->next;
				}
				ft_lstdel_oklm(&temp, &begint, comp->median);
			}
			while (comp->size > 0)
			{
				if (b->n >= comp->median)
				{
					ft_pa(&a, &b, &begin.begina, &begin.beginb);
					comp->size--;
				}
				else
					ft_rb(&b, &begin.beginb, 1);
			}
			comp = NULL;
			memo->next = NULL;
			free(comp);
		}
		else
			ft_split_algo(&comp, &b, &a, &begin);
		ft_sort3(a, begin.begina);
	}
}

/*
** Faire des optis  dans le premier algo (pas le suite) comme :
** verifier si pas deja trier chaque pa
** si trier stop
** si pas trier comparer a  et a->next et swap
** pareil pour b
** calculer si cest plus wort de ra ou de rra
*/

t_checke	*ft_quicksort(t_checke *a)
{
	int			i;
	int			j;
	int			t;
	t_ps		*comp;
	t_ps		*beginc;
	t_checke	*b;
	t_checke	*tmp;
	t_checke	*beginb;
	t_checke	*begina;
	t_checke	*finish;

	b = NULL;
	tmp = NULL;
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
		tmp = ft_lstdup(a);
		ft_init_comp(&comp, tmp, i);
		ft_free_lst(tmp);
		tmp = NULL;
		while (a && ft_lstl(&a) >= 3)
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
	comp = beginc;
	ft_suite_algo(a, b, comp, finish);
	ft_free_lst_ps(beginc);
	ft_free_lst(finish);
	return (begina);
}
