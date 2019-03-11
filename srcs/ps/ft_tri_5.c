/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:56:04 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:56:05 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>
#include <stdlib.h>

t_checke	*ft_lstndupa(t_pile *pile, t_begin *begin, t_ps **comp, int n)
{
	t_checke	*new;
	t_checke	*begine;

	if (!(new = (t_checke *)malloc(sizeof(t_checke))))
		ft_error_ps(pile, begin, *comp);
	begine = new;
	while (begin->begina && n > 0)
	{
		new->n = begin->begina->n;
		if (!(new->next = (t_checke *)malloc(sizeof(t_checke))))
			ft_error_ps(pile, begin, *comp);
		begin->begina = begin->begina->next;
		n--;
		if (begin->begina && n > 0)
			new = new->next;
	}
	free(new->next);
	new->next = NULL;
	new = begine;
	return (new);
}

void		ft_error_ps(t_pile *pile, t_begin *begin, t_ps *comp)
{
	if (pile->a)
		ft_free_lst(&pile->a);
	if (pile->b)
		ft_free_lst(&pile->b);
	if (begin->begina)
		ft_free_lst(&begin->begina);
	if (begin->beginb)
		ft_free_lst(&begin->beginb);
	if (begin->beginc)
		ft_free_lst_ps(begin->beginc);
	if (comp)
		ft_free_lst_ps(comp);
	exit(0);
}

t_checke	*ft_3fast(t_checke **a, t_begin *b)
{
	ft_lstl(a) == 2 && (*a)->n > (*a)->next->n ? ft_sa(a, &b->begina, 1) : 0;
	if (ft_lstl(a) == 3)
	{
		((*a)->n > (*a)->next->n && (*a)->next->n < (*a)->next->next->n
			&& (*a)->n < (*a)->next->next->n) || ((*a)->n < (*a)->next->n
			&& (*a)->next->n > (*a)->next->next->n && (*a)->n
			< (*a)->next->next->n) || ((*a)->n
			> (*a)->next->n && (*a)->next->n > (*a)->next->next->n
			&& (*a)->n > (*a)->next->next->n)
			? ft_sa(a, &b->begina, 1) : 0;
		(*a)->n < (*a)->next->n && (*a)->next->n > (*a)->next->next->n
			&& (*a)->n > (*a)->next->next->n ? ft_rra(a, &b->begina, 1) : 0;
		(*a)->n > (*a)->next->n && (*a)->next->n < (*a)->next->next->n
			&& (*a)->n > (*a)->next->next->n ? ft_ra(a, &b->begina, 1) : 0;
		(*a)->n < (*a)->next->n && (*a)->next->n > (*a)->next->next->n
			&& (*a)->n < (*a)->next->next->n ? ft_ra(a, &b->begina, 1) : 0;
		(*a)->n > (*a)->next->n && (*a)->next->n > (*a)->next->next->n
			&& (*a)->n > (*a)->next->next->n ? ft_sa(a, &b->begina, 1) : 0;
	}
	return (b->begina);
}
