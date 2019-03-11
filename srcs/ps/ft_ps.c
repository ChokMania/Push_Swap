/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:55:53 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:55:53 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>
#include <stdlib.h>

t_checke	*ft_recup(int ac, char **av)
{
	t_checke	*p;
	t_checke	*begin;
	int			i;

	i = 1;
	if (!(p = (t_checke*)malloc(sizeof(t_checke) * 1)))
		ft_error(p);
	begin = p;
	while (--ac)
	{
		if (!(p->next = (t_checke*)malloc(sizeof(t_checke) * 1)))
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

void		ft_r(void)
{
	ft_printf("\033[32mLe jeu est constitué de 2 piles nommées a et b.\n");
	ft_printf("Au départ : \n  ◦ a contient un nombre arbitraire d’entiers ");
	ft_printf("positifs ou négatifs, sans doublons. \n  ◦ b est vide\n");
	ft_printf("Le but du jeu est de trier a dans l’ordre croissant.\n");
	ft_printf("Pour ce faire, on ne dispose que des opérations suivantes :\n");
	ft_printf("\n➜ sa : swap a - intervertit les 2 premiers éléments au somm");
	ft_printf("et de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.\n");
	ft_printf("➜ sb : swap b - intervertit les 2 premiers éléments au sommet");
	ft_printf("de la  pile b. Ne fait rien s’il n’y en a qu’un ou aucun.\n");
	ft_printf("➜ ss : sa et sb en même temps.\n➜ pa : push a - prend le ");
	ft_printf("premier élément au sommet de b et le met sur a. Ne fait rien");
	ft_printf(" si b est vide.\n➜ pb : push b - prend le premier élément au ");
	ft_printf("sommet de a et le met sur b. Ne fait rien si a est vide.\n");
	ft_printf("➜ ra : rotate a - décale d’une position vers le haut tous ");
	ft_printf("les élements de la pile a. Le premier élément devient le ");
	ft_printf("dernier.\n➜ rb : rotate b - décale d’une position vers ");
	ft_printf("le haut tous les élements de la pile b. Le premier ");
	ft_printf("élément devient le dernier.\n➜ rr : ra et rb en même temps.\n");
	ft_printf("➜ rra : reverse rotate a - décale d’une position vers le bas ");
	ft_printf("tous les élements de la pile a. Le dernier élément devient ");
	ft_printf("le premier.\n➜ rrb : reverse rotate b - décale d’une position");
	ft_printf(" vers le bas tous les élements de la pile b. Le dernier ");
	ft_printf("élément devient le premier.\n➜ rrr : rra et rrb en même ");
	ft_printf("temps.\n");
}

void		ft_tuto(char *str)
{
	if (str[1] == 'r' && (str[2] == '\0' || str[2] == ' '))
		ft_r();
	else if (str[1] == 'e' && (str[2] == '\0' || str[2] == ' '))
	{
		ft_printf("Voici quelques exemples pour tester push_swap seul :\n\n");
		ft_printf("\033[32m./push_swap 1 2 3\n\033[0m");
		ft_printf("\033[36mARG=`ruby -e \"puts (1..50).");
		ft_printf("to_a.shuffle.join(' ')\"`; ./push_swap $ARG\n\033[0m\n\n");
		ft_printf("Voici quelques exemples pour tester avec checker :\n\n");
		ft_printf("\033[33m./push_swap 9 10 11 | ./checker 9 10 11\n\033[0m");
		ft_printf("\033[35mARG=`ruby -e \"puts (1..100).");
		ft_printf("to_a.shuffle.join(' ')\"`; ./push_swap $ARG |");
		ft_printf("./checker $ARG\n\033[0m");
	}
	else if (str[1] == 'h' && str[2] == 'e' && str[3] == 'l'
		&& str[4] == 'p' && (str[5] == ' ' || str[5] == '\0'))
		ft_printf("Usage: ./push_swap [-help/r/e] <numbers_list>\n");
	else
		return ;
	exit(0);
}

int			ft_check_av(char **av)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (av[++i] && (j = -1))
		while (av[i][++j])
			if (j == 0 && (av[i][j] == '+' || av[i][j] == '-')
				&& ft_isalnum(av[i][j + 1]))
				ft_tuto(av[i]);
			else if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
	i = 0;
	while (av[++i] && (j = -1))
	{
		if (!(k = 0) && (ft_strlen(av[i]) > 11
			|| ft_atol(av[i]) > INT32_MAX || ft_atol(av[i]) < INT32_MIN))
			return (0);
		while (++k != i)
		{
			if (ft_atol(av[i]) == ft_atol(av[k]))
				return (0);
		}
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_pile	pile;

	pile.a = NULL;
	pile.b = NULL;
	if (ac < 2)
		return (ft_printf("Usage: ./push_swap [-help/r/e] <numbers_list>\n"));
	if ((ft_check_av(av) == 0)
		&& write(2, "\033[31mError\033[37m\n", 17))
		return (0);
	pile.a = ft_recup(ac, av);
	if (ft_lstl(&pile.a) > 1)
		pile.a = ft_choice(&pile);
	ft_free_lst(&pile.a);
	return (0);
}
