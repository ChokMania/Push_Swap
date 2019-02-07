/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:14:20 by judumay           #+#    #+#             */
/*   Updated: 2019/02/07 23:05:54 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

int main(int ac, char **av)
{
	t_checker		*c;

	c = NULL;
	if (ac < 2)
		return (ft_usage());
	if (!(c = ft_init_c(c)) && ft_free_c(c))
		return (ft_display_result(ERROR));
	if (!(c->a->len = (size_t)(ac - c->argnb)))
		c->error = -1;
	if (c->error && ft_free_c(c))
		return (ft_display_result(ERROR));
	if (c->a->len == 1)
		c = checker_parsing_bash_arg(c, av);
	else
		c = checker_parsing_integers(c, ac, av);
	if (c->error && ft_free_c(c))
		return (ft_display_result(ERROR));
	c->a = ft_tabrev_leakless(c->a);
	c = checker_movements(c);
	if (c->error == -1 && ft_free_c(c))
		return (ft_display_result(KO));
	else if (c->error == 1 && ft_free_c(c))
		return (ft_display_result(ERROR));
	ft_free_c(c);
	return (ft_display_result(OK));
}
