/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:40:01 by lramard           #+#    #+#             */
/*   Updated: 2019/03/04 11:58:54 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

void		ft_size4(t_pile *pile, t_begin *begin, t_ps **comp)
{
	(void)pile;
	(void)begin;
	(void)comp;
}

void		ft_suite_algo(t_pile *pile, t_begin *begin, t_ps **comp,
	t_checke *finish)
{
	int j = 4;
	t_ps	*memo;

	while (j-- > 0 && !(ft_lst_compare(finish, pile->a)))
	{
		*comp = begin->beginc;
		while (*comp && (*comp)->next && (memo = *comp))
			*comp = (*comp)->next;
		ft_printf("|A "); ft_display(begin->begina, begin->beginc); ft_printf("|B "); ft_display(begin->beginb, NULL);ft_printf("|FINISH "); ft_display(finish, NULL);
		if ((*comp)->size <= 3)
		{
			begin->beginb->next && begin->beginb->n < begin->beginb->next->n
				? ft_sb(&pile->b, &begin->beginb, 1) : 0;
			while ((*comp)->size-- > 0)
				ft_pa(&pile->a, &pile->b, &begin->begina, &begin->beginb);
			ft_sort3(&pile->a, &begin->begina);
			memo->next = NULL;
			free(*comp);
		}
		else
			ft_size4(pile, begin, comp);
	}
}

t_checke	*ft_quicksort(t_pile *pile, t_begin *begin, t_ps **comp,
	t_checke *finish)
{
	t_checke	*temp;
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
			temp = ft_lstdup(pile->a);
			ft_init_comp(comp, temp, j);
			ft_free_lst(temp);
		}
	}
	free((*comp)->next);
	(*comp)->next = NULL;
	begin->begina = ft_3fast(&pile->a, begin);
	ft_suite_algo(pile, begin, comp, finish);
	return (begin->begina);
}

/*
** 1 trop loin
*/
