/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 15:33:32 by judumay           #+#    #+#             */
/*   Updated: 2019/03/02 17:47:43 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

t_checke	*ft_sort3_fast(t_checke *a)
{
	t_checke	*begina;

	begina = a;
	ft_lstl(&a) == 2 && a->n > a->next->n ? ft_sa(a, 1) : 0;
	if (ft_lstl(&a) == 3)
	{
		(a->n > a->next->n && a->next->n < a->next->next->n
			&& a->n < a->next->next->n) || (a->n < a->next->n && a->next->n
				> a->next->next->n && a->n < a->next->next->n) || (a->n
					> a->next->n && a->next->n > a->next->next->n && a->n
						> a->next->next->n) ? ft_sa(a, 1) : 0;
		a->n < a->next->n && a->next->n > a->next->next->n
			&& a->n > a->next->next->n ? ft_rra(&a, &begina, 1) : 0;
		a->n > a->next->n && a->next->n < a->next->next->n
			&& a->n > a->next->next->n ? ft_ra(&a, &begina, 1) : 0;
		a->n < a->next->n && a->next->n > a->next->next->n
			&& a->n < a->next->next->n ? ft_ra(&a, &begina, 1) : 0;
		a->n > a->next->n && a->next->n > a->next->next->n
			&& a->n > a->next->next->n ? ft_sa(a, 1) : 0;
	}
	return (begina);
}