/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:41:17 by judumay           #+#    #+#             */
/*   Updated: 2019/02/20 00:59:52 by judumay          ###   ########.fr       */
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
	t1 = a->n;
	while (a->next->next)
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
	t1 = b->n;
	while (b->next->next)
		b = b->next;
	t2 = b->n;
	b->n = t1;
	b = begin;
	b->n = t2;
}
/*
void	ft_ss(t_check *a, t_check *b)
{
}

void	ft_pa(t_check *a)
{
}

void	ft_pb(t_check *b)
{
}

void	ft_ra(t_check *a)
{
}

void	ft_rb(t_check *b)
{
}

void	ft_rr(t_check *a, t_check *b)
{
}

void	ft_rra(t_check *a)
{
}

void	ft_rrb(t_check *b)
{
}

void	ft_rrr(t_check *a, t_check *b)
{
}
*/
int	ft_read_inst(t_check *a, char *str)
{
	t_check		*b;
	t_check		*begina;
	t_check		*beginb;

	(void)str;
	b = (t_check*)malloc(sizeof(t_check) * 1);
	begina = a;
	beginb = b;
	b->next = (t_check*)malloc(sizeof(t_check) * 1);
	b->next = NULL;
	ft_sa(a);
	ft_sb(b);
	while (a->next)
	{
		ft_printf("%d\t", a->n);
		a = a->next;
	}
	while (b->next)
	{
		ft_printf("%d\t", b->n);
		b = b->next;
	}
	return (0);
}
