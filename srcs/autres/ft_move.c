/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:41:17 by judumay           #+#    #+#             */
/*   Updated: 2019/02/19 20:05:23 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>

void	ft_sa(t_check *p)
{
}

void	ft_sb(t_check *p)
{
}

void	ft_ss(t_check *p)
{
}

void	ft_pa(t_check *p)
{
}

void	ft_pb(t_check *p)
{
}

void	ft_ra(t_check *p)
{
}

void	ft_rb(t_check *p)
{
}

void	ft_rr(t_check *p)
{
}

void	ft_rra(t_check *p)
{
}

void	ft_rrb(t_check *p)
{
}

void	ft_rrr(t_check *p)
{
}

int	main(int ac, char **av)
{
	t_check *p;
	int i = 1;

	while (--ac)
	{
		if (!(p->next = (t_check*)malloc(sizeof(t_check) * 1)))
			ft_error(p);
		if (ft_atol(av[i]) > INT32_MAX)
			ft_error(p);
		p->n = (int)ft_atol(av[i++]);
		if (p->n == 4)
			ft_error(p);
		p = p->next;
	}
	p->next = NULL;
	return (0);
}
