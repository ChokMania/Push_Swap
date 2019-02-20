/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:54:50 by judumay           #+#    #+#             */
/*   Updated: 2019/02/20 19:06:04 by judumay          ###   ########.fr       */
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
		p->n = (int)ft_atol(av[i++]);
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
		if (ft_strlen(av[i]) > 11 || ft_atol(av[i]) > INT32_MAX ||
			ft_atol(av[i]) < INT32_MIN)
			return (0);
		while (++k != i)
		{
			if (ft_atol(av[i]) == ft_atol(av[k]))
				return (0);
		}
	}
	return (1);
}

//check les writes et verif si tout bien trier

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

//doublons == error;

int		main(int ac, char **av)
{
	int		ret;
	char	buf[4];
	char	str[1000][4];
	int		i;
	t_check	*p;
	t_check *begin;

	i = 0;
	ft_bzero(str, 1000);
	if (ac < 2 && ft_printf("\033[31mError\033[37m\n"))
		return (0);
	if (ft_check_av(av) == 0 && ft_printf("\033[31mError\033[37m\n"))
		return (0);
	p = ft_recup(ac, av);
	begin = p;
	while ((ret = read(0, buf, 4)) > 0)
	{
		buf[ret] = '\0';
		if (ft_check_input(buf) == 0 && ft_printf("\033[31mError\033[37m\n"))
		{
			ft_free_lst(p);
			exit(0);
		}
		ft_strcpy(str[i], buf);
		i++;
	}
	str[i][0] = 0;
	if (ret == -1 && ft_printf("\033[31mError\033[37m\n"))
	{
		ft_free_lst(p);
		exit(0);
	}
	p = begin;
	begin = ft_read_inst(p, str);
	p = begin;
	ft_free_lst(begin);
	ft_printf("\033[32mOK\033[37m\n");
	return (0);
}
