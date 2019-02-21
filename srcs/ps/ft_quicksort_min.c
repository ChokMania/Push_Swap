/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:57:49 by judumay           #+#    #+#             */
/*   Updated: 2019/02/21 17:09:30 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"

int		ft_quicksort_min(t_checke **a, t_checke **b)
{
	int			i;
	int			end;
	t_checke	*begin;

	begin = *a;
	i = 0;
	end = ft_lstlen(*a);
	while (i < end)
	{
		if (!((*a)->next))
			*a = begin;
		if ((*a)->n > (*a)->next->n)
			;
		else
			;
		*a = (*a)->next;
	}
	*a = begin;
	return (1);
}
