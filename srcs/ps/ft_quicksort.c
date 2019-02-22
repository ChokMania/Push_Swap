/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramard <lramard@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:40:01 by lramard           #+#    #+#             */
/*   Updated: 2019/02/22 05:35:38 by lramard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

void	ft_display(t_checke *begina, t_checke *beginb)
{
	ft_printf("\na\t");
	while (begina)
	{
		ft_printf("%d\t", begina->n);
		begina = begina->next;
	}
	ft_printf("\nb\t");
	while (beginb)
	{
		ft_printf("%d\t", beginb->n);
		beginb = beginb->next;
	}
	ft_printf("\n");
}

void	ft_init_comp(t_ps **comp, t_checke *a, int i, int k)
{

	(*comp)->median = ft_median(a, (*comp)->median);
	(*comp)->nbblock = i;
	(*comp)->size = k;
	(*comp)->next = (t_ps*)malloc(sizeof(t_ps) * 1);
}

void	ft_sort3(t_checke *a, t_checke *b, t_checke *begina)
{
	if (ft_lstl(&a) == 2 && (a)->n > (a)->next->n)
		ft_sa(a);
	if (ft_lstl(&b) == 2 && (b)->n > (b)->next->n)
		ft_sb(b);
	if (ft_lstl(&a) >= 3)
	{
		if ((a)->n > (a)->next->n && (a)->next->n > (a)->next->next->n)
		{
			ft_printf("1");
			ft_sa(a);
			ft_ra(&a, &begina);
			ft_sa(a);
			ft_rra(&a, &begina);
			ft_sa(a);
		}
		if (((a)->n > (a)->next->n && (a)->next->n < (a)->next->next->n) && (a)->n < (a)->next->next->n)
		{
			ft_printf("2");
			ft_sa(a);
		}
		if (((a)->n > (a)->next->n && (a)->next->n < (a)->next->next->n) && (a)->n > (a)->next->next->n)
		{
			ft_printf("3");
			ft_sa(a);
			ft_ra(&a, &begina);
			ft_sa(a);
			ft_rra(&a, &begina);
		}
		if (((a)->n < (a)->next->n && (a)->next->n > (a)->next->next->n) && (a)->n > (a)->next->next->n)
		{
			ft_printf("4");
			ft_ra(&a, &begina);
			ft_sa(a);
			ft_rra(&a, &begina);
			ft_sa(a);
		}
		if (((a)->n < (a)->next->n && (a)->next->n > (a)->next->next->n) && (a)->n < (a)->next->next->n)
		{
			ft_printf("5");
			ft_ra(&a, &begina);
			ft_sa(a);
			ft_rra(&a, &begina);
		}
	}
	ft_printf("\n");
}

void	ft_suite_algo(t_checke **a, t_checke **b, t_ps **comp, t_checke	*finish)
{
	t_checke	*begina;
	t_checke	*temp;
	t_checke	*beginb;
	t_ps		*beginc;
	t_checke	*begint;
	int			k;
	int			i;
	int 		j=0;

	i = 0;
	temp = (t_checke*)malloc(sizeof(t_checke) * 1);
	begint = temp;
	beginc = *comp;
	begina = *a;
	beginb = *b;
	while ((*comp)->next)
		*comp = (*comp)->next;
	ft_mergesort(&finish);
	//if ((ft_lst_compare(*a, finish)) != 1)
	while (j < 2)
	{
		k = (*comp)->size;
		ft_printf("\n%d fois\n", j);
		ft_printf("k %d\n", k);
		while (k-- > 0)
		{
			ft_pa(a, b, &begina, &beginb);
			temp->n = begina->n;
			temp->next = (t_checke*)malloc(sizeof(t_checke) * 1);
			if (k >= 1)
				temp = temp->next;
			//passage du bloc sur stack a
		}
		temp->next = NULL;
		free(temp->next);
		temp = begint;
		ft_display(begina, beginb);
		ft_printf("T");
		ft_display(temp, temp);
		if (ft_lstl(&temp) <= 3)
		{
			ft_sort3(*a, *b, begina);
			*comp = beginc;
			while ((*comp)->next->next)
				*comp = (*comp)->next;
			free((*comp)->next);
			(*comp)->next = NULL;
			ft_printf("YOLO\n");
			ft_printf("median : %d\t", (*comp)->median);
			ft_printf("nbblock : %d\t", (*comp)->nbblock);
			ft_printf("size : %d\t\n", (*comp)->size);
		}
		else
		{
			ft_mergesort(&temp);
			ft_printf("new mediane : %d\n", (*comp)->median = ft_median(temp, (*comp)->median));
			ft_free_lst(temp);
			temp = NULL;
			while (++k < (*comp)->size)
				*a = (*a)->next;
			k = (*a)->n;
			*a = begina;
			ft_printf("k %d\n", k);
			while (k != (*a)->n)
			{
				ft_printf("a->n %d\n", (begina)->n);
				if ((*a)->n <= (*comp)->median)
				{
					ft_printf("IN\n");
					ft_pbe(a, b, &begina, &beginb);
					*a = begina;
					i++;
				}
				else
					*a = (*a)->next;
				//ft_display(begina, beginb);
			}
			*a = begina;
			(*comp)->size = i;
			ft_printf("median : %d\t", (*comp)->median);
			ft_printf("nbblock : %d\t", (*comp)->nbblock);
			ft_printf("size : %d\t\n", (*comp)->size);
		}
		j++;
		ft_printf("RES\n");
		ft_display(begina, beginb);
		ft_printf("FIN RES\n");
	}
	//ft_display(temp, temp);
	//boucle mediane jusqu.a obtenir 3 elements et passage de sblocs a droite
		//tri des 3 elements
		//recommencer avec le pssage de stack
}

t_checke *ft_quicksort(t_checke *a)
{
	t_checke	*b;
	t_checke	*beginb;
	t_ps		*comp;
	t_ps		*beginc;
	t_checke	*begina;
	t_checke	*tmp;
	t_checke	*finish;
	int			i;
	int			t;
	int			j;
	int 		k;

	b = NULL;
	i = 0;
	begina = a;
	beginb = b;
	comp = NULL;
	finish = ft_lstdup(a);
	comp = (t_ps*)malloc(sizeof(t_ps) * 1);
	beginc = comp;
	while (a->next)
		a = a->next;
	t = a->n;
	a = begina;
	k = 0;
	ft_display(begina, beginb);
	while (ft_lstl(&a) > 3)
	{
		j = 0;
		tmp = ft_lstdup(a); // LEAKS
		ft_init_comp(&comp, tmp, i, k);
		ft_free_lst(tmp);
		tmp = NULL;
		k = 0;
		while (a && ft_lstl(&a) > 2)
		{
			if (a->n <= comp->median)
			{
				ft_pbe(&a, &b, &begina, &beginb);
				a = begina;
				k++;
			}
			else
				ft_ra(&a, &begina);
			if (a->n == t)
				j++;
			else if (j != 0)
				break ;
			//ft_display(begina, beginb);
		}
		while (a->next)
			a = a->next;
		t = a->n;
		a = begina;
		b = beginb;
		ft_display(begina, beginb);
		comp = comp->next;
		i++;
	}
	tmp = ft_lstdup(a);
	ft_init_comp(&comp, tmp, i, k);
	ft_free_lst(tmp);
	free(comp->next);
	comp->next = NULL;
	comp = beginc;
	while (comp)
	{
		ft_printf("median : %d\t", comp->median);
		ft_printf("nbblock : %d\t", comp->nbblock);
		ft_printf("size : %d\t\n", comp->size);
		comp = comp->next;
	}
	comp = beginc;
	ft_display(a, b);
	ft_sort3(a, b, begina);
	ft_display(a, b);
	ft_suite_algo(&a, &b, &comp, finish);
	while (b)
		ft_pa(&a, &b, &begina, &beginb);
	/*si ft_pa -> plus de leaks*/
	ft_free_lst_ps(beginc);
	ft_free_lst(finish);
	return (begina);
}
