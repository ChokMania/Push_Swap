/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:54:50 by judumay           #+#    #+#             */
/*   Updated: 2019/02/20 11:32:12 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>

t_check	*ft_recup(int ac, char **av)
{
	t_check		*p;
	t_check		*begin;
	int			i;

	i = 1;
	if (!(p = (t_check*)malloc(sizeof(t_check) * 1)))
		ft_error(p);
	begin = p;
	while (--ac)
	{
		if (!(p->next = (t_check*)malloc(sizeof(t_check) * 1)))
			ft_error(p);
		if (ft_atol(av[i]) > INT32_MAX)
			ft_error(p);
		p->n = (int)ft_atol(av[i++]);
		if (p->n == 4)
			ft_error(p);
		if (ac > 1)
			p = p->next;
	}
	free(p->next);
	p->next = NULL;
	p = begin;
	return (p);
}

int		ft_check_av(char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[++i] && (j = -1))
		while (av[i][++j])
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
	return (1);
}

int		ft_check_input(char *str)
{
	if (ft_strcmp(str, "sa\n") == 0 || ft_strcmp(str, "sb\n") == 0 ||
	ft_strcmp(str, "ss\n") == 0 || ft_strcmp(str, "pa\n") == 0 ||
	ft_strcmp(str, "pb\n") == 0 || ft_strcmp(str, "ra\n") == 0 ||
	ft_strcmp(str, "rb\n") == 0 || ft_strcmp(str, "rr\n") == 0 ||
	ft_strcmp(str, "rra\n") == 0 || ft_strcmp(str, "rrb\n") == 0 ||
	ft_strcmp(str, "rrr\n") == 0)
		return (1);
	return (0);
}

//si > int ou doublons == error;

int		main(int ac, char **av)
{
	int		ret;
	char	buf[4];
	char	str[1000];
	t_check	*p;
	t_check *begin;

	ft_bzero(str, 1000);
	if (ac < 2 && ft_printf("\033[31m 1Error\033[37m\n"))
		return (0);
	if (ft_check_av(av) == 0 && ft_printf("\033[31m 2Error\033[37m\n"))
		return (0);
	p = ft_recup(ac, av);
	begin = p;
	while ((ret = read(0, buf, 4)) > 0)
	{
		buf[ret] = '\0';
		if (ft_check_input(buf) == 0 && ft_printf("\033[31m 3Error\033[37m\n"))
			return (0);
		if (str[0] == '\0')
			ft_strcpy(&str[0], buf);
		else
			ft_strcpy(&str[ft_strlen(str)], buf);
	}
	ft_printf("\n\nstr:\n\n\n%s", str);
	if (ret == -1 && ft_printf("\033[31m 4Error\033[37m\n"))
		return (0);
	p = begin;
	begin = ft_read_inst(p, str);
	p = begin;
	ft_free_lst(begin);
	ft_printf("\033[32mOK\033[37m\n");
	return (0);
}
