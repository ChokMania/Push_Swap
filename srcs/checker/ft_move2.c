/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:54:44 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:54:47 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>
#include <stdlib.h>

void	ft_sa(t_check **a, t_check **begina)
{
	if (ft_lstlene(a) <= 1)
		return ;
	(*a) = (*a)->next;
	(*begina)->next = (*begina)->next->next;
	(*a)->next = *begina;
	*begina = *a;
}

void	ft_sb(t_check **b, t_check **beginb)
{
	if (ft_lstlene(b) <= 1)
		return ;
	(*b) = (*b)->next;
	(*beginb)->next = (*beginb)->next->next;
	(*b)->next = *beginb;
	*beginb = *b;
}

void	ft_ss(t_check **a, t_check **b, t_check **begina, t_check **beginb)
{
	ft_sa(a, begina);
	ft_sb(b, beginb);
}

void	ft_pa(t_check **a, t_check **b, t_check **begina, t_check **beginb)
{
	t_check	*t;

	if (*b)
	{
		t = *b;
		*b = (*b)->next;
		*beginb = *b;
		t->next = (*a);
		*a = t;
		*begina = *a;
	}
}

void	ft_pb(t_check **a, t_check **b, t_check **begina, t_check **beginb)
{
	t_check	*t;

	if (*a)
	{
		t = *a;
		*a = (*a)->next;
		*begina = *a;
		t->next = (*b);
		*b = t;
		*beginb = *b;
	}
}
