/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:54:29 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:54:29 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>

void	ft_check_value(t_check *p)
{
	while (p->next)
	{
		if (p->n > p->next->n && ft_printf("KO\n"))
			return ;
		p = p->next;
	}
	ft_printf("OK\n");
}

t_check	*ft_recup(int ac, char **av, int choix)
{
	t_check		*p;
	t_check		*begin;
	int			i;

	i = 1;
	if (!(p = (t_check*)malloc(sizeof(t_check) * 1)))
		ft_error(p);
	begin = p;
	i = choix == 0 ? 1 : 2;
	while (--ac > choix)
	{
		if (!(p->next = (t_check*)malloc(sizeof(t_check) * 1)))
			ft_error(p);
		p->n = (int)ft_atol(av[i++]);
		if (ac > choix + 1)
			p = p->next;
	}
	free(p->next);
	p->next = NULL;
	p = begin;
	return (p);
}

int		ft_check_av(char **av, int ac, t_mem *mem)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (av[++i] && (j = -1))
		while (av[i][++j])
			if (j == 0 && (av[i][j] == '+' || av[i][j] == '-')
				&& ft_isalnum(av[i][j + 1]))
				j = ft_intput(av[i], ac, j + 1, mem);
			else if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
	i = mem->memv;
	while (av[++i])
	{
		k = mem->memv;
		if (ft_strlen(av[i]) > 11 || ft_atol(av[i]) > INT32_MAX
			|| ft_atol(av[i]) < INT32_MIN)
			return (0);
		while (++k != i)
			if (ft_atol(av[i]) == ft_atol(av[k]))
				return (0);
	}
	return (1);
}

int		ft_check_input(char *str)
{
	if (ft_strcmp(str, "sa\n") == 0 || ft_strcmp(str, "sb\n") == 0
		|| ft_strcmp(str, "ss\n") == 0 || ft_strcmp(str, "pa\n") == 0
		|| ft_strcmp(str, "pb\n") == 0 || ft_strcmp(str, "ra\n") == 0
		|| ft_strcmp(str, "rb\n") == 0 || ft_strcmp(str, "rr\n") == 0
		|| ft_strcmp(str, "rra\n") == 0 || ft_strcmp(str, "rrb\n") == 0
		|| ft_strcmp(str, "rrr\n") == 0)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int		ret;
	char	**str;
	t_check	*p;
	t_check *begin;
	t_mem	mem;

	mem.memv = 0;
	if (ac < 2)
		return (ft_printf("Usage: ./checker [-help/v/e] <numbers_list>\n"));
	if ((ft_check_av(av, ac, &mem) == 0)
		&& write(2, "\033[31mError\033[37m\n", 17))
		return (0);
	p = ft_recup(ac, av, mem.memv);
	begin = p;
	if (!(str = ft_creastr()))
		return (0);
	ret = 0;
	ft_suite(ret, str, p);
	p = begin;
	begin = ft_read_inst(p, str, mem.memv);
	p = begin;
	ft_check_value(p);
	ft_delstr(str, -1);
	ft_free_lst(begin);
	return (0);
}
