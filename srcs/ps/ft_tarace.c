/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tarace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:56:00 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:56:01 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>
#include <stdlib.h>

void		ft_lstdel_oklm(t_checke **a, t_checke **begina, int median)
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

void		ft_init_begin(t_begin *begin, t_checke *a, t_checke *b, t_ps *comp)
{
	(*begin).begina = a;
	(*begin).beginc = comp;
	(*begin).beginb = b;
}

void		ft_init_comp(t_ps **comp, t_pile *pile, t_begin *begin, int i)
{
	(*comp)->median = ft_median(pile, begin, comp, (*comp)->median);
	(*comp)->nbblock = i;
	(*comp)->size = 0;
	if (!((*comp)->next = (t_ps*)malloc(sizeof(t_ps) * 1)))
		ft_error_ps(pile, begin, *comp);
}

void		ft_sort3(t_checke **a, t_checke **begina)
{
	if (ft_lstl(a) == 2 && (*a)->n > (*a)->next->n)
		ft_sa(a, begina, 1);
	if (ft_lstl(a) >= 3)
	{
		if ((*a)->n > (*a)->next->n && (*a)->next->n > (*a)->next->next->n)
			ft_1(a, begina);
		if (((*a)->n > (*a)->next->n && (*a)->next->n
			< (*a)->next->next->n) && (*a)->n < (*a)->next->next->n)
			ft_sa(a, begina, 1);
		if (((*a)->n > (*a)->next->n && (*a)->next->n
			< (*a)->next->next->n) && (*a)->n > (*a)->next->next->n)
			ft_2(a, begina);
		if (((*a)->n < (*a)->next->n && (*a)->next->n
			> (*a)->next->next->n) && (*a)->n > (*a)->next->next->n)
			ft_3(a, begina);
		if (((*a)->n < (*a)->next->n && (*a)->next->n
			> (*a)->next->next->n) && (*a)->n < (*a)->next->next->n)
			ft_4(a, begina);
	}
}
