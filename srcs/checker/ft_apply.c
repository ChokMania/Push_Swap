/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:54:32 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:54:33 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>

static void		ft_checker_b(t_check *beginb, t_check *begina, char **str)
{
	if (beginb)
	{
		ft_free_lst(beginb);
		begina ? ft_free_lst(begina) : 0;
		ft_delstr(str, -1);
		ft_printf("KO\n");
		exit(0);
	}
}

static t_check	*ft_apply(char **str, t_check *a, t_check *begina,
	t_check *beginb)
{
	t_check		*b;
	int			i;

	b = beginb;
	i = -1;
	begina = a;
	while (str[++i][0] != 0)
	{
		!ft_strcmp(str[i], "sa\n") ? ft_sa(&a, &begina) : 0;
		!ft_strcmp(str[i], "sb\n") ? ft_sb(&b, &beginb) : 0;
		!ft_strcmp(str[i], "ss\n") ? ft_ss(&a, &b, &begina, &beginb) : 0;
		!ft_strcmp(str[i], "pa\n") ? ft_pa(&a, &b, &begina, &beginb) : 0;
		!ft_strcmp(str[i], "pb\n") ? ft_pb(&a, &b, &begina, &beginb) : 0;
		!ft_strcmp(str[i], "ra\n") ? ft_ra(&a, &begina) : 0;
		!ft_strcmp(str[i], "rb\n") ? ft_rb(&b, &beginb) : 0;
		!ft_strcmp(str[i], "rr\n") ? ft_rr(&a, &b, &begina, &beginb) : 0;
		!ft_strcmp(str[i], "rra\n") ? ft_rra(&a, &begina) : 0;
		!ft_strcmp(str[i], "rrb\n") ? ft_rrb(&b, &beginb) : 0;
		!ft_strcmp(str[i], "rrr\n") ? ft_rrr(&a, &b, &begina, &beginb) : 0;
	}
	ft_checker_b(beginb, begina, str);
	return (begina);
}

t_check			*ft_read_inst(t_check *a, char **str, int choix)
{
	t_check		*begina;
	t_check		*beginb;

	beginb = NULL;
	begina = a;
	if (choix == 0)
		a = ft_apply(str, a, begina, beginb);
	else
		ft_mlx(str, begina, beginb);
	return (a);
}
