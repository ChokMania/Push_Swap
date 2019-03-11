/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:55:42 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:55:43 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

void	ft_1(t_checke **a, t_checke **begina)
{
	ft_sa(a, begina, 1);
	ft_ra(a, begina, 1);
	ft_sa(a, begina, 1);
	ft_rra(a, begina, 1);
	ft_sa(a, begina, 1);
}

void	ft_2(t_checke **a, t_checke **begina)
{
	ft_sa(a, begina, 1);
	ft_ra(a, begina, 1);
	ft_sa(a, begina, 1);
	ft_rra(a, begina, 1);
}

void	ft_3(t_checke **a, t_checke **begina)
{
	ft_ra(a, begina, 1);
	ft_sa(a, begina, 1);
	ft_rra(a, begina, 1);
	ft_sa(a, begina, 1);
}

void	ft_4(t_checke **a, t_checke **begina)
{
	ft_ra(a, begina, 1);
	ft_sa(a, begina, 1);
	ft_rra(a, begina, 1);
}
