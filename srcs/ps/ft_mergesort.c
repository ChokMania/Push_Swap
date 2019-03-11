/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:55:29 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:55:29 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>
#include <stdlib.h>

t_checke	*ft_sortedmerge(t_checke *a, t_checke *b)
{
	t_checke *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->n <= b->n)
	{
		result = a;
		result->next = ft_sortedmerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = ft_sortedmerge(a, b->next);
	}
	return (result);
}

void		ft_frontbacksplit(t_checke *source, t_checke **frontref,
	t_checke **backref)
{
	t_checke *fast;
	t_checke *slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontref = source;
	*backref = slow->next;
	slow->next = NULL;
}

void		ft_mergesort(t_checke **headref)
{
	int			i;
	int			tmp;
	int			length;
	t_checke	*begin;

	begin = *headref;
	length = ft_lstl(headref);
	i = 0;
	while (i < length)
	{
		if (!((*headref)->next))
			(*headref) = begin;
		if ((*headref)->n > (*headref)->next->n)
		{
			tmp = (*headref)->n;
			(*headref)->n = (*headref)->next->n;
			(*headref)->next->n = tmp;
			i = 0;
		}
		else
			i++;
		(*headref) = (*headref)->next;
	}
	(*headref) = begin;
}

void		ft_printlist(t_checke *node)
{
	while (node != NULL)
	{
		ft_printf("%d ", node->n);
		node = node->next;
	}
}

void		ft_rrr(t_checke **a, t_checke **b,
	t_checke **begina, t_checke **beginb)
{
	ft_rra(a, begina, 0);
	ft_rrb(b, beginb, 0);
	ft_printf("ra\n");
}
