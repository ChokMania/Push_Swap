/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:11:58 by judumay           #+#    #+#             */
/*   Updated: 2019/02/26 10:46:34 by judumay          ###   ########.fr       */
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

t_check	**ft_list_push_fronte(t_check **begin_list, int n)
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
	return (begin_list);
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

void	ft_suite(int ret, char str[1000][5], t_check *p)
{
	char	*tmp;
	char	buf[BUF_SIZE];
	int		i;

	i = 0;
	str[i][0] = '\0';
	while ((ret = read(0, buf, 1)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(str[i], buf);
		ft_strcpy(str[i], tmp);
		free(tmp);
		if (buf[0] == '\n')
		{
			ft_check_input(str[i]) == 0 ? ft_error_check(p) : 0;
			str[++i][0] = '\0';
		}
	}
	ret == -1 ? ft_error_check(p) : 0;
	str[i][0] = 0;
}
