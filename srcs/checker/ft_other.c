/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:54:56 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:54:56 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>
#include <stdlib.h>

int		ft_intput(char *av, int ac, int j, t_mem *mem)
{
	if (ac > 2 && av[j] == 'v' && (av[j + 1] == ' ' || av[j + 1] == '\0')
		&& (mem->memv = 1))
		return (j);
	else if (av[j] == 'e' && (av[j + 1] == ' ' || av[j + 1] == '\0'))
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
	else if (av[j] == 'h' && av[j + 1] == 'e' && av[j + 2] == 'l'
		&& av[j + 3] == 'p' && (av[j + 4] == ' ' || av[j + 4] == '\0'))
		ft_printf("Usage: ./checker [-help/v/e] <numbers_list>\n");
	else if (ft_isdigit(av[j]))
		return (j);
	else
		write(2, "\033[31mError\033[37m\n", 17);
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

void	ft_error_check(t_check *p, char **str)
{
	write(2, "\033[31mError\033[37m\n", 17);
	ft_free_lst(p);
	ft_delstr(str, -1);
	exit(0);
}
