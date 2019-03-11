/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:55:24 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:55:25 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>
#include <stdlib.h>

int		ft_is_sorted(t_checke *a)
{
	t_checke	*beg;

	beg = a;
	while (a)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	a = beg;
	return (1);
}

void	ft_free_lst(t_checke **p)
{
	if ((*p)->next)
		ft_free_lst(&(*p)->next);
	free(*p);
}

void	ft_free_lst_ps(t_ps *p)
{
	if (p->next)
		ft_free_lst_ps(p->next);
	free(p);
}

int		ft_median(t_pile *pile, t_begin *begin, t_ps **comp, int n)
{
	t_checke	*t;
	t_checke	*beg;
	int			i;

	beg = pile->temp;
	t = ft_lstdup(pile->temp, pile, begin, comp);
	ft_mergesort(&pile->temp);
	i = ft_lstl(&t);
	n = i % 2 == 0 ? i / 2 - 1 : i / 2;
	i = -1;
	while (++i < n)
		pile->temp = pile->temp->next;
	n = pile->temp->n;
	pile->temp = beg;
	ft_free_lst(&t);
	return (n);
}
