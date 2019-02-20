/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:11:58 by judumay           #+#    #+#             */
/*   Updated: 2019/02/20 19:13:10 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>
#include <stdlib.h>

t_check	*ft_create_eleme(int n)
{
	t_check *p;

	p = (t_check*)malloc(sizeof(t_check) * 1);
	if (p)
	{
		p->next = NULL;
		p->n = n;
	}
	return (p);
}

t_check	*ft_list_push_fronte(t_check **begin_list, int n)
{
	t_check *p;

	if (*begin_list)
	{
		p = ft_create_eleme(n);
		p->next = *begin_list;
		*begin_list = p;
	}
	else
		*begin_list = ft_create_eleme(n);
	return (*begin_list);
}

void	ft_del_first(t_check **begin_list)
{
	t_check *p;

	if (*begin_list)
	{
		p = (*begin_list)->next;
		(*begin_list) = p;
	}
}

int		ft_lstlene(t_check **list)
{
	int		j;
	t_check	*tmp;

	if (list != NULL)
	{
		tmp = *list;
		j = 0;
		while (tmp != NULL)
		{
			tmp = tmp->next;
			j++;
		}
		return (j);
	}
	else
		return (0);
}
