/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:09:44 by judumay           #+#    #+#             */
/*   Updated: 2019/02/21 14:43:59 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>
#include <stdlib.h>

void	ft_sa(t_check *a)
{
	int		t1;

	if (ft_lstlene(&a) <= 1)
		return ;
	t1 = a->n;
	a->n = a->next->n;
	a->next->n = t1;
}

void	ft_sb(t_check *b)
{
	int		t1;

	if (ft_lstlene(&b) <= 1)
		return ;
	t1 = b->n;
	b->n = b->next->n;
	b->next->n = t1;
}

void	ft_ss(t_check *a, t_check *b)
{
	ft_sa(a);
	ft_sb(b);
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
