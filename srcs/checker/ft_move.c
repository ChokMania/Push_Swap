/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:54:38 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:54:39 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>
#include <stdlib.h>

void	ft_ra(t_check **a, t_check **begina)
{
	t_check	*t;

	t = NULL;
	if (*a && (*a)->next)
	{
		t = (*a);
		*begina = (*a)->next;
		t->next = NULL;
		(*a) = *begina;
		while ((*a)->next)
			(*a) = (*a)->next;
		(*a)->next = t;
		*a = *begina;
	}
}

void	ft_rb(t_check **b, t_check **beginb)
{
	t_check	*t;

	t = NULL;
	if (*b && (*b)->next)
	{
		t = (*b);
		*beginb = (*b)->next;
		t->next = NULL;
		(*b) = *beginb;
		while ((*b)->next)
			(*b) = (*b)->next;
		(*b)->next = t;
		*b = *beginb;
	}
}

void	ft_rr(t_check **a, t_check **b, t_check **begina, t_check **beginb)
{
	ft_ra(a, begina);
	ft_rb(b, beginb);
}

void	ft_rra(t_check **a, t_check **begina)
{
	t_check	*t;

	t = NULL;
	if (*a && (*a)->next)
	{
		while ((*a)->next->next)
			*a = (*a)->next;
		t = (*a)->next;
		(*a)->next = NULL;
		*a = *begina;
		t->next = *a;
		*begina = t;
		*a = *begina;
	}
}

void	ft_rrb(t_check **b, t_check **beginb)
{
	t_check	*t;

	t = NULL;
	if (*b && (*b)->next)
	{
		while ((*b)->next->next)
			*b = (*b)->next;
		t = (*b)->next;
		(*b)->next = NULL;
		*b = *beginb;
		t->next = *b;
		*beginb = t;
		*b = *beginb;
	}
}
