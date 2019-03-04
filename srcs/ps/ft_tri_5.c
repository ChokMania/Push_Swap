/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 15:33:32 by judumay           #+#    #+#             */
/*   Updated: 2019/03/04 16:18:03 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

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
