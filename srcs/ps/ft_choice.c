/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:55:13 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:55:16 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

t_checke	*ft_choice(t_pile *pile)
{
	t_begin		begin;
	t_ps		*comp;
	t_checke	*finish;

	finish = ft_lstdup(pile->a, pile, &begin, &comp);
	begin.begina = pile->a;
	ft_mergesort(&finish);
	if (ft_lst_compare(pile->a, finish) == 1 || ft_lstl(&pile->a) <= 3)
	{
		ft_lst_compare(pile->a, finish) == 0 ? ft_3fast(&pile->a, &begin) : 0;
		ft_free_lst(&finish);
		return (pile->a);
	}
	pile->temp = ft_lstdup(pile->a, pile, &begin, &comp);
	if (!(comp = (t_ps*)malloc(sizeof(t_ps) * 1)))
		ft_error_ps(pile, &begin, comp);
	ft_init_comp(&comp, pile, &begin, 0);
	ft_init_begin(&begin, pile->a, pile->b, comp);
	ft_free_lst(&pile->temp);
	ft_quicksort(pile, &begin, &comp, finish);
	pile->b ? ft_free_lst(&pile->b) : 0;
	ft_free_lst(&finish);
	return (begin.begina);
}
