/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:55:49 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:55:49 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>
#include <stdlib.h>

void		ft_error(t_checke *p)
{
	write(2, "\033[31mError\033[37m\n", 17);
	free(p->next);
	exit(0);
}

int			ft_lstl(t_checke **list)
{
	int			j;
	t_checke	*t;

	t = *list;
	if (t)
	{
		j = 0;
		while (t)
		{
			t = t->next;
			j++;
		}
		return (j);
	}
	else
		return (0);
}

t_checke	*ft_lstdup(t_checke *temp, t_pile *pile, t_begin *begin,
	t_ps **comp)
{
	t_checke	*new;
	t_checke	*begine;

	if (!(new = (t_checke *)malloc(sizeof(t_checke))))
		ft_error_ps(pile, begin, *comp);
	begine = new;
	while (temp)
	{
		new->n = temp->n;
		if (!(new->next = (t_checke *)malloc(sizeof(t_checke))))
			ft_error_ps(pile, begin, *comp);
		temp = temp->next;
		if (temp)
			new = new->next;
	}
	free(new->next);
	new->next = NULL;
	new = begine;
	return (new);
}

t_checke	*ft_lstndupb(t_pile *pile, t_begin *begin, t_ps **comp, int n)
{
	t_checke	*new;
	t_checke	*begine;

	if (!(new = (t_checke *)malloc(sizeof(t_checke))))
		ft_error_ps(pile, begin, *comp);
	begine = new;
	while (begin->beginb && n > 0)
	{
		new->n = begin->beginb->n;
		if (!(new->next = (t_checke *)malloc(sizeof(t_checke))))
			ft_error_ps(pile, begin, *comp);
		begin->beginb = begin->beginb->next;
		n--;
		if (begin->beginb && n > 0)
			new = new->next;
	}
	free(new->next);
	new->next = NULL;
	new = begine;
	return (new);
}

int			ft_lst_compare(t_checke *p, t_checke *finish)
{
	while (p)
	{
		if (p->n != finish->n)
			return (0);
		p = p->next;
		finish = finish->next;
	}
	return (1);
}
