/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:17:23 by judumay           #+#    #+#             */
/*   Updated: 2019/03/02 17:47:51 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

t_checke	*ft_choice(t_checke *a)
{
	t_begin		begin;
	t_checke	*b;

	b = NULL;
	begin.begina = a;
	begin.beginb = b;
	if (ft_lstl(&a) <= 3)
		ft_sort3_fast(a);
	else
		ft_quicksort(a);
	return (begin.begina);
}
