/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 09:05:16 by judumay           #+#    #+#             */
/*   Updated: 2019/03/04 18:43:25 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>
#include <stdlib.h>

void	ft_error(t_check *p)
{
	write(2, "\033[31mError\033[37m\n", 17);
	free(p->next);
	exit(0);
}

void	ft_free_lst(t_check *p)
{
	if (p->next)
		ft_free_lst(p->next);
	free(p);
}

int		ft_check_inpute(char *str)
{
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0
	|| ft_strcmp(str, "ss") == 0 || ft_strcmp(str, "pa") == 0
	|| ft_strcmp(str, "pb") == 0 || ft_strcmp(str, "ra") == 0
	|| ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0
	|| ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrb") == 0
	|| ft_strcmp(str, "rrr") == 0 || ft_strcmp(str, "") == 0)
		return (1);
	return (0);
}

void	ft_error_check(t_check *p)
{
	write(2, "\033[31mError\033[37m\n", 17);
	ft_free_lst(p);
	exit(0);
}
