/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:54:50 by judumay           #+#    #+#             */
/*   Updated: 2019/02/19 09:44:46 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>

int		ft_check_av(char **av)
{
	int		i;

	i = 1;
	while (av[i])
		if (ft_isdigit(ft_atoi(av[i])) == 0)
			return (0);
	return (1);
}

int		ft_check_input(char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return (0);
	else if (ft_strcmp(str, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "ss\n") == 0)
		return (2);
	else if (ft_strcmp(str, "pa\n") == 0)
		return (3);
	else if (ft_strcmp(str, "pb\n") == 0)
		return (4);
	else if (ft_strcmp(str, "ra\n") == 0)
		return (5);
	else if (ft_strcmp(str, "rb\n") == 0)
		return (6);
	else if (ft_strcmp(str, "rr\n") == 0)
		return (7);
	else if (ft_strcmp(str, "rra\n") == 0)
		return (8);
	else if (ft_strcmp(str, "rrb\n") == 0)
		return (9);
	else if (ft_strcmp(str, "rrr\n") == 0)
		return (10);
	return (-1);
}

int		main(int ac, char **av)
{
	int		ret;
	int		i;
	char	buf[4];

	(void)ac;
	(void)av;
	//if (ft_check_av(av) == 0 && ft_printf("Error\n"))
	//	return (0);
	i = 0;
	while ((ret = read(0, buf, 4)) > 0)
	{
		buf[ret] = '\0';
		if (ft_check_input(buf) == -1 && ft_printf("Error\n"))
			return (0);
		i++;
	}
	if (ret == -1 && ft_printf("Error\n"))
		return (0);
	ft_printf("Fin\n");
	return (0);
}