/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:23:15 by judumay           #+#    #+#             */
/*   Updated: 2019/02/20 19:30:40 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>

void	ft_rrr(t_check **a, t_check **b, t_check **begina, t_check **beginb)
{
	ft_rra(a, begina);
	ft_rrb(b, beginb);
}

t_check	*ft_apply(char str[1000][4], t_check **a)
{
	t_check		*b;
	t_check		*begina;
	t_check		*beginb;
	int			i;

	b = NULL;
	i = -1;
	begina = *a;
	beginb = b;
	while (str[++i][0] != 0)
	{
		!ft_strcmp(str[i], "sa\n") ? ft_sa(*a) : 0;
		!ft_strcmp(str[i], "sb\n") ? ft_sb(b) : 0;
		!ft_strcmp(str[i], "ss\n") ? ft_ss(*a, b) : 0;
		!ft_strcmp(str[i], "pa\n") ? ft_pa(a, &b, &begina) : 0;
		!ft_strcmp(str[i], "pb\n") ? ft_pb(a, &b, &beginb) : 0;
		!ft_strcmp(str[i], "ra\n") ? ft_ra(a, &begina) : 0;
		!ft_strcmp(str[i], "rb\n") ? ft_rb(&b, &beginb) : 0;
		!ft_strcmp(str[i], "rr\n") ? ft_rr(a, &b, &begina, &beginb) : 0;
		!ft_strcmp(str[i], "rra\n") ? ft_rra(a, &begina) : 0;
		!ft_strcmp(str[i], "rrb\n") ? ft_rrb(&b, &beginb) : 0;
		!ft_strcmp(str[i], "rrr\n") ? ft_rrr(a, &b, &begina, &beginb) : 0;
	}
	beginb ? ft_free_lst(beginb) : 0;
	return (begina);
}

t_check	*ft_read_inst(t_check *a, char str[1000][4])
{
	a = ft_apply(str, &a);
	return (a);
}
