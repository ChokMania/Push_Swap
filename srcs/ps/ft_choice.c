/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:17:23 by judumay           #+#    #+#             */
/*   Updated: 2019/03/04 09:52:25 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

t_checke	*ft_choice(t_pile *pile)
{
	t_begin		begin;
	t_ps		*comp;
	t_checke	*temp;
	t_checke	*finish;

	finish = ft_lstdup(pile->a);
	ft_mergesort(&finish);
	temp = ft_lstdup(pile->a);
	if (!(comp = (t_ps*)malloc(sizeof(t_ps) * 1)))
		return (NULL);
	ft_init_comp(&comp, temp, 0);
	ft_init_begin(&begin, pile->a, pile->b, comp);
	ft_free_lst(temp);
	if (ft_lst_compare(pile->a, finish) == 1)
		return (begin.begina);
	if (ft_lstl(&pile->a) <= 3 && !(comp->next = NULL))
		begin.begina = ft_sort3_fast(&pile->a, &begin);
	else
		ft_quicksort(pile, &begin, &comp);
	ft_free_lst_ps(comp);
	pile->b ? ft_free_lst(pile->b) : 0;
	ft_free_lst(finish);
	return (begin.begina);
}
