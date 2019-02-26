/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 09:05:16 by judumay           #+#    #+#             */
/*   Updated: 2019/02/26 10:43:34 by judumay          ###   ########.fr       */
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

void	ft_error_check(t_check *p)
{
	write(2, "\033[31mError\033[37m\n", 17);
	ft_free_lst(p);
	exit(0);
}
