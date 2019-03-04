/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:27:09 by lramard           #+#    #+#             */
/*   Updated: 2019/03/04 16:09:46 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>
#include <stdlib.h>

t_checke	*ft_recup(int ac, char **av)
{
	t_checke	*p;
	t_checke	*begin;
	int			i;

	i = 1;
	if (!(p = (t_checke*)malloc(sizeof(t_checke) * 1)))
		ft_error(p);
	begin = p;
	while (--ac)
	{
		if (!(p->next = (t_checke*)malloc(sizeof(t_checke) * 1)))
			ft_error(p);
		p->n = (int)ft_atol(av[i++]);
		if (ac > 1)
			p = p->next;
	}
	free(p->next);
	p->next = NULL;
	p = begin;
	return (p);
}

int			ft_check_av(char **av)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (av[++i] && (j = -1))
		while (av[i][++j])
			if (j == 0 && av[i][j] == '-')
				;
			else if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
	i = 0;
	while (av[++i] && (j = -1))
	{
		k = 0;
		if (ft_strlen(av[i]) > 11 || ft_atol(av[i]) > INT32_MAX
		|| ft_atol(av[i]) < INT32_MIN)
			return (0);
		while (++k != i)
		{
			if (ft_atol(av[i]) == ft_atol(av[k]))
				return (0);
		}
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_pile	pile;

	pile.a = NULL;
	pile.b = NULL;
	if ((ac < 2 || ft_check_av(av) == 0)
	&& write(2, "\033[31mError\033[37m\n", 17))
		return (0);
	pile.a = ft_recup(ac, av);
	if (ft_lstl(&pile.a) > 1)
		pile.a = ft_choice(&pile);
	ft_free_lst(&pile.a);
	return (0);
}
