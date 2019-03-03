/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:40:01 by lramard           #+#    #+#             */
/*   Updated: 2019/03/03 19:22:04 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

void		ft_display(t_checke *p, t_ps *comp)
{
	if (p)
	{
		ft_printf("display|\n");
		while (p)
		{
			ft_printf("n : %d\t", p->n);
			p = p->next;
		}
		ft_printf("\n");
	}
	if (comp)
	{
		ft_printf("|COMP display|\n");
		while (comp)
		{
			ft_printf("nbblock %d\t", comp->nbblock);
			ft_printf("size %d\t", comp->size);
			ft_printf("mediane %d\t\n", comp->median);
			comp = comp->next;
		}
		ft_printf("\n");
	}
}

t_checke	*ft_quicksort(t_checke **a, t_checke **b, t_begin *begin,
	t_ps **comp)
{
	t_checke	*temp;
	int			i;
	int			j;

	begin->beginb = *b;
	j = 1;
	i = ft_lstl(a);
	while (i > 0)
	{
		if ((*a)->n <= (*comp)->median)
		{
			(*comp)->size++;
			ft_pb(a, b, &begin->begina, &begin->beginb);
		}
		else
			ft_ra(a, &begin->begina, 1);
		i--;
	}
	while (ft_lstl(a) > 3)
	{
		*comp = (*comp)->next;
		temp = ft_lstdup(*a);
		ft_init_comp(comp, temp, j);
		ft_free_lst(temp);
		temp = NULL;
		i = ft_lstl(a);
		while (--i > -1)
		{
			if ((*a)->n <= (*comp)->median)
			{
				(*comp)->size++;
				ft_pb(a, b, &begin->begina, &begin->beginb);
				if (ft_lstl(a) <= 3)
					break ;
			}
			else
				ft_ra(a, &begin->begina, 1);
		}
		j++;
	}//1 trop loin
	free((*comp)->next);
	(*comp)->next = NULL;
	begin->begina = ft_sort3_fast(a, begin);
	return (begin->begina);
}
