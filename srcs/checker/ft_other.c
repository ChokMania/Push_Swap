/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 09:05:16 by judumay           #+#    #+#             */
/*   Updated: 2019/03/05 19:32:29 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>
#include <stdlib.h>

int		ft_intput(char *av, int j, t_mem *mem)
{
	if (av[j] == 'v')
	{
		mem->memv = 1;
		while (av[j] > '0' && av[j] < '9')
			j++;
		return (j);
	}
	else if (av[j] == 'e')
	{
		ft_printf("Voici quelques exemples pour tester checker seul :\n\n");
		ft_printf("\033[32m./checker 1 2 3\n\033[0m");
		ft_printf("\033[36mARG=`ruby -e \"puts (1..50).");
		ft_printf("to_a.shuffle.join(' ')\"`; ./checker $ARG\n\033[0m");
		ft_printf("\033[31mNe pas oublier les instructions.\033[0m\n\n");
		ft_printf("Voici quelques exemples pour tester avec push_swap :\n\n");
		ft_printf("\033[33m./push_swap 9 10 11 | ./checker 9 10 11\n\033[0m");
		ft_printf("\033[35mARG=`ruby -e \"puts (1..100).");
		ft_printf("to_a.shuffle.join(' ')\"`; ./push_swap $ARG |");
		ft_printf("./checker $ARG\n\033[0m");
	}
	else if (av[j] == 'u')
		ft_printf("Usage: ./push_swap [-u/r/e] <numbers_list>\n");
	exit(0);
}

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
