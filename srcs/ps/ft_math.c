/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:16:53 by judumay           #+#    #+#             */
/*   Updated: 2019/03/02 19:20:20 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>
#include <stdlib.h>

void	ft_free_lst(t_checke *p)
{
	if (p->next)
		ft_free_lst(p->next);
	free(p);
}

void	ft_free_lst_ps(t_ps *p)
{
	if (p->next)
		ft_free_lst_ps(p->next);
	free(p);
}

int		ft_median(t_checke *p, int n)
{
	t_checke	*t;
	int			i;

	t = ft_lstdup(p);
	ft_mergesort(&p);
	i = ft_lstl(&t);
	n = i % 2 == 0 ? i / 2 - 1 : i / 2;
	i = -1;
	while (++i < n)
		p = p->next;
	n = p->n;
	ft_free_lst(t);
	return (n);
}
