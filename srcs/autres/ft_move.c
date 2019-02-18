/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:41:17 by judumay           #+#    #+#             */
/*   Updated: 2019/02/18 19:43:38 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <ft_checker.h>

int		*ft_intdup(int *tab, int size)
{
	int		i;
	int		*tab2;

	tab2 = (int*)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		tab2[i] = tab[i];
		i++;
	}
	return (tab2);
}

void	ft_swap_int(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ft_sb(t_checker *p)
{
	if (p->size_b == 0 || p->size_b == 1)
		return ;
	ft_swap_int(&p->tab_b[0], &p->tab_b[p->size_b - 1]);
}

void	ft_sa(t_checker *p)
{
	if (p->size_a == 0 || p->size_a == 1)
		return ;
	ft_swap_int(&p->tab_a[0], &p->tab_a[p->size_a - 1]);
}

void	ft_ss(t_checker *p)
{
	if (p->size_a == 0 || p->size_a == 1 || p->size_b == 0 || p->size_b == 1)
		return ;
	ft_sa(p);
	ft_sb(p);
}

void	ft_pa(t_checker *p)
{
	int i;

	i = 0;
	if (p->size_a == 0 || p->size_a == 1 || p->size_b == 0 || p->size_b == 1)
		return ;
	p->size_b++;
	p->tab_temp_b = (int*)malloc(sizeof(int) * p->size_b);
	p->tab_temp_b[0] = p->tab_a[0];
	while (++i < p->size_b)
		p->tab_temp_b[i] = p->tab_b[i - 1];
	p->size_temp_b = p->size_b;
	p->tab_temp_a = (int*)malloc(sizeof(int) * --p->size_a);
	i = -1;
	while (++i < p->size_a)
		p->tab_temp_a[i] = p->tab_a[i + 1];
	p->size_temp_a = p->size_a;
}

void	ft_pb(t_checker *p)
{
	int i;

	i = 0;
	if (p->size_a == 0 || p->size_a == 1 || p->size_b == 0 || p->size_b == 1)
		return ;
	p->size_a++;
	p->tab_temp_a = (int*)malloc(sizeof(int) * p->size_a);
	p->tab_temp_a[0] = p->tab_b[0];
	while (++i < p->size_a)
		p->tab_temp_a[i] = p->tab_a[i - 1];
	p->size_temp_a = p->size_a;
	p->tab_temp_b = (int*)malloc(sizeof(int) * --p->size_b);
	i = -1;
	while (++i < p->size_b)
		p->tab_temp_b[i] = p->tab_b[i + 1];
	p->size_temp_b = p->size_b;
}

void	ft_ra(t_checker *p)
{
	int i;

	i = 0;
	if (p->size_a == 0 || p->size_a == 1)
		return ;
	while (i < p->size_a - 1)
	{
		ft_swap_int(&p->tab_a[i], &p->tab_a[i + 1]);
		i++;
	}
}

void	ft_rb(t_checker *p)
{
	int i;

	i = 0;
	if (p->size_b == 0 || p->size_b == 1)
		return ;
	while (i < p->size_b - 1)
	{
		ft_swap_int(&p->tab_b[i], &p->tab_b[i + 1]);
		i++;
	}
}

void	ft_rr(t_checker *p)
{
	ft_ra(p);
	ft_rb(p);
}

void	ft_display(t_checker *p)
{
	printf(" _____\t _____\n|     |\t|     |\n|  a  |\t|  b  |\n|_____|\t|_____|\n|     |\t|     |\n|  %d  |\t|  %d  |\n|  %d  |\t|  %d  |\n|  %d  |\t|  %d  |\n|  %d  |\t|  %d  |\n|_____|\t|_____|\n",
	p->tab_a[0], p->tab_b[0], p->tab_a[1], p->tab_b[1], p->tab_a[2], p->tab_b[2], p->tab_a[3], p->tab_b[3]);
	printf("size a : %d\tsize b : %d\tsize ta : %d\tsize tb : %d\t\n", p->size_a, p->size_b, p->size_temp_a, p->size_temp_b);
}

int	main(void)
{
	t_checker *p;

	p = (t_checker*)malloc(sizeof(t_checker) * 1);
	p->tab_a = (int*)malloc(sizeof(int) * 5);
	p->tab_b = (int*)malloc(sizeof(int) * 5);

	p->size_a = 4;
	p->size_b = 4;
	p->size_temp_a = 0;
	p->size_temp_b = 0;

	p->tab_a[0] = 1;
	p->tab_a[1] = 2;
	p->tab_a[2] = 3;
	p->tab_a[3] = 4;
	p->tab_a[4] = 0;

	p->tab_b[0] = 9;
	p->tab_b[1] = 8;
	p->tab_b[2] = 7;
	p->tab_b[3] = 6;
	p->tab_b[4] = 0;


	dprintf(1, "\nRIEN\n");
	ft_display(p);
	dprintf(1, "\n\033[32msa\n");
	ft_sa(p);
	ft_display(p);
	dprintf(1, "\n\033[31msb\n");
	ft_sb(p);
	ft_display(p);
	dprintf(1, "\n\033[33msr\n");
	ft_ss(p);
	ft_display(p);
	dprintf(1, "\n\033[34mpa\n");
	ft_pa(p);
	free(p->tab_b);
	p->tab_b = ft_intdup(p->tab_temp_b, p->size_b);
	free(p->tab_temp_b);
	free(p->tab_a);
	p->tab_a = ft_intdup(p->tab_temp_a, p->size_a);
	p->tab_a[3] = 0;
	free(p->tab_temp_a);
	//leaks a cause du display et 0
	ft_display(p);
	dprintf(1, "\n\033[32mpb\n");
	ft_pb(p);
	free(p->tab_b);
	p->tab_b = ft_intdup(p->tab_temp_b, p->size_b);
	free(p->tab_temp_b);
	free(p->tab_a);
	p->tab_a = ft_intdup(p->tab_temp_a, p->size_a);
	free(p->tab_temp_a);
	//leaks a cause du display
	ft_display(p);
	dprintf(1, "\n\033[34mra\n");
	ft_ra(p);
	ft_display(p);
	dprintf(1, "\n\033[31mrb\n");
	ft_rb(p);
	ft_display(p);
	dprintf(1, "\n\033[36mrr\n");
	ft_rr(p);
	ft_display(p);
	//FREE
	free(p->tab_a);
	free(p->tab_b);
	free(p);
	return (0);
}
