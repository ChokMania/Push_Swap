/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:54:50 by judumay           #+#    #+#             */
/*   Updated: 2019/02/19 11:40:12 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>

void	ft_free_lst(t_check *p)
{
	if (p->next)
		ft_free_lst(p->next);
	p->next = NULL;
	free(p);
}

t_check	*ft_recup(int ac, char **av)
{
	t_check		*p;
	t_check		*begin;
	int			i;

	i = 1;
	if (!(p = (t_check*)malloc(sizeof(t_check) * 1)))
		return (NULL);
	begin = p;
	while (--ac)
	{
		p->n = ft_atoi(av[i++]);
		dprintf(1, "p->n:%d\n", p->n);
		if (!(p->next = (t_check*)malloc(sizeof(t_check) * 1)))
			return (NULL);
		p = p->next;
	}
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

int		main(int ac, char **av)
{
	int		ret;
	char	buf[4];
	char	str[1000];
	t_check	*p;
	t_check *begin;

	if (ac < 2 && printf("\033[31mError\033[37m\n"))
		return (0);
	if (ft_check_av(av) == 0 && printf("\033[31mError\033[37m\n"))
		return (0);
	while ((ret = read(0, buf, 4)) > 0)
	{
		buf[ret] = '\0';
		if (ft_check_input(buf) == 0 && printf("\033[31mError\033[37m\n"))
			return (0);
		ft_strcpy(&str[ft_strlen(str)], buf);
	}
	printf("\n\nstr:\n%s", str);
	if (ret == -1 && printf("\033[31mError\033[37m\n"))
		return (0);
	p = ft_recup(ac, av);
	begin = p;
	while (p->next)
	{
		printf("\np :%d\n", p->n);
		p = p->next;
	}
	ft_free_lst(begin);
	printf("Fin\n");
	return (0);
}

//si > int ou doublons == error;