/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:17:23 by judumay           #+#    #+#             */
/*   Updated: 2019/03/03 19:15:07 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

t_checke	*ft_choice(t_checke *a)
{
	t_begin		begin;
	t_checke	*b;
	t_ps		*comp;
	t_checke	*temp;
	t_checke	*finish;

	b = NULL;
	finish = ft_lstdup(a);
	ft_mergesort(&finish);
	temp = ft_lstdup(a);
	if (!(comp = (t_ps*)malloc(sizeof(t_ps) * 1)))
		return (NULL);
	ft_init_comp(&comp, temp, 0);
	ft_init_begin(&begin, a, b, comp);
	ft_free_lst(temp);
	if (ft_lst_compare(a, finish) == 1)
		return (begin.begina);
	if (ft_lstl(&a) <= 3)
		ft_sort3_fast(&a, &begin);
	else
		ft_quicksort(&a, &b, &begin, &comp);
	ft_free_lst_ps(comp);
	ft_free_lst(b);
	ft_free_lst(finish);
	return (begin.begina);
}
