/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramard <lramard@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:40:01 by lramard           #+#    #+#             */
/*   Updated: 2019/02/22 17:01:05 by lramard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

void	ft_display(t_checke *begina)
{
	while (begina)
	{
		ft_printf("%d\t", begina->n);
		begina = begina->next;
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
			ft_sa(a);
			ft_ra(&a, &begina);
			ft_sa(a);
			ft_rra(&a, &begina);
			ft_sa(a);
		}
		if (((a)->n > (a)->next->n && (a)->next->n < (a)->next->next->n) && (a)->n < (a)->next->next->n)
			ft_sa(a);
		if (((a)->n > (a)->next->n && (a)->next->n < (a)->next->next->n) && (a)->n > (a)->next->next->n)
		{
			ft_sa(a);
			ft_ra(&a, &begina);
			ft_sa(a);
			ft_rra(&a, &begina);
		}
		if (((a)->n < (a)->next->n && (a)->next->n > (a)->next->next->n) && (a)->n > (a)->next->next->n)
		{
			ft_ra(&a, &begina);
			ft_sa(a);
			ft_rra(&a, &begina);
			ft_sa(a);
		}
		if (((a)->n < (a)->next->n && (a)->next->n > (a)->next->next->n) && (a)->n < (a)->next->next->n)
		{
			ft_ra(&a, &begina);
			ft_sa(a);
			ft_rra(&a, &begina);
		}
	}
}


//./push_swap   1 2 3 4 5 6 7 8 9 4512 451 51 16 151 541 431 561 065 104 041 531 165 31 651 peut etre b
void	ft_suite_algo(t_checke **a, t_checke **b, t_ps *comp, t_checke	*finish)
{
	t_checke	*begina;
	t_checke	*temp;
	t_checke	*temp2;
	t_checke	*beginb;
	t_ps		*beginc;
	t_checke	*begint;
	t_checke	*begint2;
	int			k;
	int			i;
	int 		j = 0;
	int			l = 0;
	int			o = 0;

	i = 0;
	temp = NULL;
	beginc = comp;
	begina = *a;
	beginb = *b;
	temp2 = NULL;;
	ft_mergesort(&finish);
	while (o < 5 && (ft_lst_compare(*a, finish)) != 1)
	{
		while (comp->next)
			comp = comp->next;
		temp = (t_checke*)malloc(sizeof(t_checke) * 1);
		begint = temp;
		k = comp->size;
		if (ft_lstl(b) < k)
			k = ft_lstl(b);
		ft_printf("k : %d\n", k);
		while (k-- > 0)
		{
			ft_pa(a, b, &begina, &beginb);
			temp->n = begina->n;
			temp->next = (t_checke*)malloc(sizeof(t_checke) * 1);
			if (k >= 1)
				temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
		temp = begint;
		if (ft_lstl(&temp) <= 3)
		{
			ft_printf("\nIF\n");
			ft_sort3(*a, *b, begina);
			comp = beginc;
			while (comp->next->next)
				comp = comp->next;
			free(comp->next);
			comp->next = NULL;
			comp = beginc;
		}
		else
		{
			//while () recreer comp->next, nouveau block;
			//while (o++ < 3 && ft_lstl(&temp) > 3)
			//{
				ft_printf("\nAVANT\n");
				ft_printf("\na :\t");
				ft_display(*a);
				ft_printf("\nELSE\n");
				j = 0;
				i = 0;
				begint = temp;
				temp2 = ft_lstdup(temp);
				begint2 = temp2;
				ft_mergesort(&temp2);
				comp->median = ft_median(temp2, comp->median);
				ft_free_lst(temp2);
				temp2 = NULL;
				while (++k < comp->size)
					*a = (*a)->next;
				k = (*a)->n;
				*a = begina;
				while (k != (*a)->n)
				{
					if ((*a)->n <= comp->median)
					{
						ft_pbe(a, b, &begina, &beginb);
						*a = begina;
						i++;
						ft_pbe(&temp, &temp2, &begint, &beginb);
						temp = begint;
					}
					else
					{
						ft_ra(&temp, &begint);
						ft_ra(a, &begina);
						l++;
					}
				}
				ft_printf("mediane : %d\t", comp->median);
				while (l != 0)
				{
					ft_rra(a, &begina);
					l--;
				}
				*a = begina;
				ft_sort3(*a, *b, begina);
				comp->size = i;
				ft_printf("\ni : %d\n", i);
				ft_printf("\nb :\t");
				ft_display(*b);
				ft_printf("\nb :\t");
				ft_display(*b);
				ft_printf("\nt :\t");
				ft_display(temp);
			//}
		}
		ft_printf("\n\nEND\n\n");
		while (comp)
		{
			ft_printf("mediane : %d\t", comp->median);
			ft_printf("nbblock : %d\t", comp->nbblock);
			ft_printf("size    : %d\n", comp->size);
			comp = comp->next;
		}
		comp = beginc;
		ft_printf("\na :\t");
		ft_display(*a);
		ft_printf("b :\t");
		ft_display(*b);
		j++;
		free(temp);
		temp = NULL;
	}
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
	ft_display(a);
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
		}
		while (a->next)
			a = a->next;
		t = a->n;
		a = begina;
		b = beginb;
		comp = comp->next;
		i++;
	}
	tmp = ft_lstdup(a);
	ft_init_comp(&comp, tmp, i, k);
	ft_free_lst(tmp);
	free(comp->next);
	comp->next = NULL;
	comp = beginc;
	ft_sort3(a, b, begina);
	ft_printf("\na : ");
	ft_display(a);
	ft_printf("\nb : ");
	ft_display(b);
	while (comp->next)
	{
		ft_printf("mediane : %d\t", comp->median);
		ft_printf("nbblock : %d\t", comp->nbblock);
		ft_printf("size    : %d\n", comp->size);
		comp = comp->next;
	}
	comp =  beginc;
	ft_suite_algo(&a, &b, comp, finish);
	while (b)
		ft_pa(&a, &b, &begina, &beginb);
	/*si ft_pa -> plus de leaks*/
	ft_free_lst_ps(beginc);
	ft_free_lst(finish);
	//ft_display(a);
	return (begina);
}
