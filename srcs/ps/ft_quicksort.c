/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramard <lramard@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:40:01 by lramard           #+#    #+#             */
/*   Updated: 2019/02/21 18:05:32 by lramard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

void	ft_quicksort(t_checke *a)
{
	t_checke	*b;
	t_ps		*comp;
	t_checke	*begin;

	begin = a;
	comp = (t_ps*)malloc(sizeof(t_ps) * 1);
	comp->median = 0;
	comp->nbblock = 0;
	comp->size = ft_lstl(a);
	comp->next = NULL;

	b = NULL;
	comp->median = ft_median(a, comp->median);
	while (a)
	{
		if (a->n <= comp->median)
		{
			//ft_send(5);
			//ft_pb();
		}
		a = a->next;
	}
}