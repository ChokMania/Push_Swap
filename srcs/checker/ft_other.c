/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 09:05:16 by judumay           #+#    #+#             */
/*   Updated: 2019/02/20 10:35:59 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>
#include <stdlib.h>

void	ft_error(t_check *p)
{
	printf("\033[31m 5Error\033[37m\n");
	free(p->next);
	exit(0);
}

void	ft_free_lst(t_check *p)
{
	if (p->next)
		ft_free_lst(p->next);
	free(p);
}
