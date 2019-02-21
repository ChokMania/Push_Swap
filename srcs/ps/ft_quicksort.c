/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramard <lramard@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:40:01 by lramard           #+#    #+#             */
/*   Updated: 2019/02/21 18:39:44 by lramard          ###   ########.fr       */
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

t_ps	*ft_init_comp(t_ps *comp, t_checke *a)
{
	comp = (t_ps*)malloc(sizeof(t_ps) * 1);
	comp->median = 0;
	comp->nbblock = 0;
	comp->size = ft_lstl(a);
	comp->next = NULL;
	return (comp);
}

void	ft_quicksort(t_checke *a)
{
	t_checke	*b;
	t_checke	*beginb;
	t_ps		*comp;
	t_checke	*begina;

	b = NULL;
	begina = a;
	beginb = b;
	comp = NULL;
	comp = ft_init_comp(comp, a);
	comp->median = ft_median(a, comp->median);
	ft_printf("MEDIANE : %d\n\n", comp->median);
	ft_display(a, b);
	while (a)
	{
		if (a->n <= comp->median)
			ft_pbe(&a, &b, &begina, &beginb);
		else
			break ;
		a = begina;
	}
	a = begina;
	b = beginb;
	ft_display(begina, beginb);
}