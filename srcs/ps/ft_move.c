/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:55:33 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:55:34 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>
#include <stdlib.h>

void	ft_ra(t_checke **a, t_checke **begina, int n)
{
	t_checke	*t;

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
		if (n != 0)
			ft_printf("ra\n");
	}
}

void	ft_rb(t_checke **b, t_checke **beginb, int n)
{
	t_checke	*t;

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
		if (n != 0)
			ft_printf("rb\n");
	}
}

void	ft_rr(t_checke **a, t_checke **b, t_checke **begina, t_checke **beginb)
{
	ft_ra(a, begina, 0);
	ft_rb(b, beginb, 0);
	ft_printf("rr\n");
}

void	ft_rra(t_checke **a, t_checke **begina, int n)
{
	t_checke	*t;

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
		if (n != 0)
			ft_printf("rra\n");
	}
}

void	ft_rrb(t_checke **b, t_checke **beginb, int n)
{
	t_checke	*t;

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
		if (n != 0)
			ft_printf("rrb\n");
	}
}
