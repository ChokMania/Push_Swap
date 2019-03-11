/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:55:56 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:55:57 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>
#include <stdlib.h>

void		ft_tej_de_a(t_pile *pile, t_begin *begin, t_ps **comp, int n)
{
	int			j;
	int			i;

	j = (*comp)->nbblock + 1;
	if (!((*comp)->next = (t_ps*)malloc(sizeof(t_ps) * 1)))
		ft_error_ps(pile, begin, *comp);
	while (n > 3 && (i = -1))
	{
		*comp = (*comp)->next;
		pile->temp = ft_lstndupa(pile, begin, comp, n);
		ft_init_comp(comp, pile, begin, j);
		ft_free_lst(&pile->temp);
		while (i < n)
			if ((pile->a)->n <= (*comp)->median && ++(*comp)->size
				&& --n)
				ft_pb(&pile->a, &pile->b, &begin->begina, &begin->beginb);
			else if (i++)
				ft_ra(&pile->a, &begin->begina, 1);
		while (i-- > 0)
			ft_rra(&pile->a, &begin->begina, 1);
		j++;
	}
	free((*comp)->next);
	(*comp)->next = NULL;
}

void		ft_size4(t_pile *pile, t_begin *begin, t_ps **comp)
{
	int		i;
	int		new_size;

	new_size = 0;
	pile->temp = ft_lstndupb(pile, begin, comp, (*comp)->size);
	(*comp)->median = ft_median(pile, begin, comp, (*comp)->median);
	ft_free_lst(&pile->temp);
	i = -1;
	while (++i < (*comp)->size)
	{
		if ((pile->b)->n >= (*comp)->median)
		{
			ft_pa(&pile->a, &pile->b, &begin->begina, &begin->beginb);
			new_size++;
			(*comp)->size--;
			i--;
		}
		else
			ft_rb(&pile->b, &begin->beginb, 1);
	}
	if ((*comp)->nbblock != 0)
		while (i-- > 0)
			ft_rrb(&pile->b, &begin->beginb, 1);
	ft_tej_de_a(pile, begin, comp, new_size);
}

void		ft_suite_algo(t_pile *pile, t_begin *begin, t_ps **comp,
	t_checke *finish)
{
	t_ps	*memo;

	while (!(ft_lst_compare(finish, pile->a)))
	{
		*comp = begin->beginc;
		while (*comp && (*comp)->next && (memo = *comp))
			*comp = (*comp)->next;
		if ((*comp)->size <= 3)
		{
			while ((*comp)->size-- > 0)
			{
				begin->beginb->next && begin->beginb->n < begin->beginb->next->n
					? ft_sb(&pile->b, &begin->beginb, 1) : 0;
				ft_pa(&pile->a, &pile->b, &begin->begina, &begin->beginb);
			}
			if ((*comp)->nbblock != 0)
				memo->next = NULL;
			free(*comp);
		}
		else
			ft_size4(pile, begin, comp);
		ft_sort3(&pile->a, &begin->begina);
	}
}

t_checke	*ft_quicksort(t_pile *pile, t_begin *begin, t_ps **comp,
	t_checke *finish)
{
	int			i;
	int			j;

	j = 0;
	while (ft_lstl(&pile->a) > 3 && ++j)
	{
		i = ft_lstl(&pile->a);
		while (--i > -1)
			(pile->a)->n < (*comp)->median && ++(*comp)->size
				? ft_pb(&pile->a, &pile->b, &begin->begina, &begin->beginb)
				: ft_ra(&pile->a, &begin->begina, 1);
		if (ft_lstl(&pile->a) > 3 && (*comp = (*comp)->next))
		{
			pile->temp = ft_lstdup(pile->a, pile, begin, comp);
			ft_init_comp(comp, pile, begin, j);
			ft_free_lst(&pile->temp);
		}
	}
	free((*comp)->next);
	(*comp)->next = NULL;
	begin->begina = ft_3fast(&pile->a, begin);
	ft_suite_algo(pile, begin, comp, finish);
	return (begin->begina);
}
