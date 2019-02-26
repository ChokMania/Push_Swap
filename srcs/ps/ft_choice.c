/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:17:23 by judumay           #+#    #+#             */
/*   Updated: 2019/02/26 11:52:17 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

t_checke	*ft_choice(t_checke *begin)
{
	if (ft_lstl(&begin) <= 5)
		;
	if (ft_lstl(&begin) < 20)
		;
	ft_quicksort(begin);
	return (begin);
}
