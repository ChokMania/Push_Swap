/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:12:57 by judumay           #+#    #+#             */
/*   Updated: 2019/02/07 22:37:58 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

static t_checker	*checker_parsing_movements2(t_checker *c)
{
	if (!ft_strncmp(c->line, "rrb", 3) && ft_strlen(c->line) == 3
		&& (c->rotation = RRB))
		ft_tabrevrotate(c->b);
	else if (!ft_strncmp(c->line, "rrr", 3) && ft_strlen(c->line) == 3
		&& ft_tabrevrotate(c->a) && (c->rotation = RRR))
		ft_tabrevrotate(c->b);
	else if (!ft_strncmp(c->line, "ra", 2) && ft_strlen(c->line) == 2
		&& (c->rotation = RA))
		ft_tabrotate(c->a);
	else if (!ft_strncmp(c->line, "rb", 2) && ft_strlen(c->line) == 2
		&& (c->rotation = RB))
		ft_tabrotate(c->b);
	else if (!ft_strncmp(c->line, "rr", 2) && ft_strlen(c->line) == 2
		&& ft_tabrotate(c->a) && (c->rotation = RR))
		ft_tabrotate(c->b);
	else
		c->error = 1;
	return (c);
}

t_checker			*checker_parsing_movements(t_checker *c)
{
	if (!ft_strncmp(c->line, "sa", 2) && ft_strlen(c->line) == 2
		&& (c->rotation = SA))
		ft_tabswap(c->a);
	else if (!ft_strncmp(c->line, "sb", 2) && ft_strlen(c->line) == 2
		&& (c->rotation = SB))
		ft_tabswap(c->b);
	else if (!ft_strncmp(c->line, "ss", 2) && ft_strlen(c->line) == 2
		&& ft_tabswap(c->a) && (c->rotation = SS))
		ft_tabswap(c->b);
	else if (!ft_strncmp(c->line, "pa", 2) && ft_strlen(c->line) == 2
		&& (c->rotation = PA))
		ft_tabpush(c->b, c->a);
	else if (!ft_strncmp(c->line, "pb", 2) && ft_strlen(c->line) == 2
		&& (c->rotation = PB))
		ft_tabpush(c->a, c->b);
	else if (!ft_strncmp(c->line, "rra", 3) && ft_strlen(c->line) == 3
		&& (c->rotation = RRA))
		ft_tabrevrotate(c->a);
	else
		return (checker_parsing_movements2(c));
	return (c);
}

void				checker_parsing_doubles(t_checker *c)
{
	size_t		i;
	size_t		j;
	int			tmp;
	int			zerobool;

	i = 0;
	zerobool = 0;
	while (i < c->a->len)
	{
		if (!(tmp = c->a->tab[i]))
			++zerobool;
		if (zerobool > 1 && (c->error = -1))
			return ;
		j = i++ + 1;
		while (tmp && j < c->a->len)
		{
			if (tmp == c->a->tab[j++] && (c->error = -1))
				return ;
		}
	}
}

t_checker			*checker_parsing_bash_arg(t_checker *c, char **av)
{
	char	**split;
	int		i;

	split = ft_strsplit(av[c->argnb], ' ');
	i = 0;
	while (split[i])
	{
		if (ft_atoi_strict(split[i]) == 10000000000 && (c->error = -1))
			return (c);
		c->a->tab[i] = ft_atoi(split[i]);
		ft_strdel(&split[i++]);
	}
	ft_memdel((void**)&split);
	if (!(c->a->len = (size_t)i))
	{
		ft_display_result(ERROR);
		exit(-1);
	}
	return (c);
}

t_checker			*checker_parsing_integers(t_checker *c, int ac,
	char **av)
{
	int		count;

	count = 0;
	while (c->argnb < ac)
	{
		if (ft_atoi_strict(av[c->argnb]) == 10000000000 && (c->error = -1))
			return (c);
		c->a->tab[count++] = ft_atoi(av[c->argnb]);
		++c->argnb;
	}
	return (c);
}
