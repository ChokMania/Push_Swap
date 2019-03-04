/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:40:01 by lramard           #+#    #+#             */
/*   Updated: 2019/03/04 09:56:43 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

void		ft_suite_algo(t_pile *pile, t_begin *begin, t_ps **comp)
{
	(void)comp;
	(void)pile;
	ft_printf("|A "); ft_display(begin->begina, begin->beginc); ft_printf("|B "); ft_display(begin->beginb, NULL);
}

t_checke	*ft_quicksort(t_pile *pile, t_begin *begin, t_ps **comp)
{
	t_checke	*temp;
	int			i;
	int			j;

	j = 0;
	while (ft_lstl(&pile->a) > 3 && ++j)
	{
		i = ft_lstl(&pile->a);
		while (ft_lstl(&pile->a) > 3 && --i > -1)
			(pile->a)->n <= (*comp)->median && ++(*comp)->size
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
	begin->begina = ft_sort3_fast(&pile->a, begin);
	//ft_suite_algo(pile, begin, comp);
	return (begin->begina);
}

/*
** 1 trop loin
*/
