/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:06:27 by judumay           #+#    #+#             */
/*   Updated: 2019/02/07 20:41:57 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

static void		checker_display_nbrotations(t_checker *c)
{
	ft_putstr("\033[H\033[J");
	ft_putstr("\033[4mThe number of rotations\033[24m : ");
	ft_putllnbr(c->nbrotations);
	ft_putchar('\n');
}

static void		checker_display_rotation(t_checker *c)
{
	ft_putstr("\033[4mLast rotation\033[24m : ");
	if (c->rotation == SA)
		ft_putstr("sa");
	else if (c->rotation == SB)
		ft_putstr("sb");
	else if (c->rotation == SS)
		ft_putstr("ss");
	else if (c->rotation == PA)
		ft_putstr("pa");
	else if (c->rotation == PB)
		ft_putstr("pb");
	else if (c->rotation == RA)
		ft_putstr("ra");
	else if (c->rotation == RB)
		ft_putstr("rb");
	else if (c->rotation == RR)
		ft_putstr("rr");
	else if (c->rotation == RRA)
		ft_putstr("rra");
	else if (c->rotation == RRB)
		ft_putstr("rrb");
	else if (c->rotation == RRR)
		ft_putstr("rrr");
	ft_putchar('\n');
}

static void		checker_display_stacks(t_checker *c)
{
	size_t		i;

	i = 0;
	ft_putstr("\n\033[4mStacks\033[24m :\n");
	ft_putstr("/*\n");
	ft_putstr("** \033[7ma\033[27m");
	while (i < c->a->len)
	{
		ft_putstr(" ");
		ft_putllnbr(c->a->tab[i]);
		++i;
	}
	ft_putchar('\n');
	ft_putstr("** \033[7mb\033[27m");
	i = 0;
	while (i < c->b->len)
	{
		ft_putstr(" ");
		ft_putllnbr(c->b->tab[i]);
		++i;
	}
	ft_putchar('\n');
	ft_putendl("*/\n");
}

void			checker_display_v_flag(t_checker *c)
{
	checker_display_nbrotations(c);
	checker_display_rotation(c);
	checker_display_stacks(c);
}

int				ft_usage(void)
{
	ft_putendl_fd("Usage : ./checker nb1 nb2 nb3 ... nbx", 1);
	return (0);
}

int				ft_display_result(int result)
{
	if (result == OK)
	{
		ft_putendl_fd("\033[32mOK\033[0m", 1);
		return (0);
	}
	if (result == KO)
		ft_putendl_fd("\033[31mKO\033[0m", 1);
	else if (result == ERROR)
		ft_putendl_fd("\033[31mError\033[0m", 2);
	return (-1);
}
