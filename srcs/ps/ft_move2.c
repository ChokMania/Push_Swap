/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:55:38 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:55:39 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

void	ft_sa(t_checke **a, t_checke **begina, int n)
{
	if (ft_lstl(a) <= 1)
		return ;
	(*a) = (*a)->next;
	(*begina)->next = (*begina)->next->next;
	(*a)->next = *begina;
	*begina = *a;
	if (n != 0)
		ft_printf("sa\n");
}

void	ft_sb(t_checke **b, t_checke **beginb, int n)
{
	if (ft_lstl(b) <= 1)
		return ;
	(*b) = (*b)->next;
	(*beginb)->next = (*beginb)->next->next;
	(*b)->next = *beginb;
	*beginb = *b;
	if (n != 0)
		ft_printf("sb\n");
}

void	ft_ss(t_checke **a, t_checke **b, t_checke **begina, t_checke **beginb)
{
	ft_sa(a, begina, 0);
	ft_sb(b, beginb, 0);
	ft_printf("ss\n");
}

void	ft_pa(t_checke **a, t_checke **b, t_checke **begina, t_checke **beginb)
{
	t_checke	*t;

	if (*b)
	{
		t = *b;
		*b = (*b)->next;
		*beginb = *b;
		t->next = (*a);
		*a = t;
		*begina = *a;
		ft_printf("pa\n");
	}
}

void	ft_pb(t_checke **a, t_checke **b, t_checke **begina, t_checke **beginb)
{
	t_checke	*t;

	if (*a)
	{
		t = *a;
		*a = (*a)->next;
		*begina = *a;
		t->next = (*b);
		*b = t;
		*beginb = *b;
		ft_printf("pb\n");
	}
}
