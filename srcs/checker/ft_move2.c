/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:09:44 by judumay           #+#    #+#             */
/*   Updated: 2019/02/20 19:29:59 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>
#include <stdlib.h>

void	ft_sa(t_check *a)
{
	int		t1;
	int		t2;
	t_check *begin;

	begin = a;
	if ((ft_lstlene(&begin) == 1 || ft_lstlene(&begin) == 0))
		return ;
	t1 = a->n;
	while (a->next)
		a = a->next;
	t2 = a->n;
	a->n = t1;
	a = begin;
	a->n = t2;
}

void	ft_sb(t_check *b)
{
	int		t1;
	int		t2;
	t_check *begin;

	begin = b;
	if ((ft_lstlene(&begin) == 1 || ft_lstlene(&begin) == 0))
		return ;
	t1 = b->n;
	while (b->next)
		b = b->next;
	t2 = b->n;
	b->n = t1;
	b = begin;
	b->n = t2;
}

void	ft_ss(t_check *a, t_check *b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_pa(t_check **a, t_check **b, t_check **begina)
{
	if (ft_lstlene(b) == 0)
		return ;
	*begina = ft_list_push_fronte(a, (*b)->n);
	ft_del_first(b);
}

void	ft_pb(t_check **a, t_check **b, t_check **beginb)
{
	if ((ft_lstlene(a) == 0) && ft_printf("ALONE\n"))
		return ;
	*beginb = ft_list_push_fronte(b, (*a)->n);
	ft_del_first(a);
}
