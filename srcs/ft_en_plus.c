/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_en_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:32:07 by judumay           #+#    #+#             */
/*   Updated: 2019/02/07 22:49:07 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

t_tab	*ft_tabnew(size_t size)
{
	t_tab	*t;

	if (!(t = ft_memalloc(sizeof(t_tab)))
		|| !(t->tab = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	t->size = size;
	t->len = 0;
	while (size)
		t->tab[--size] = 0;
	return (t);
}

void	ft_tabdel(t_tab **t)
{
	if (t && (*t)->tab)
	{
		free((*t)->tab);
		(*t)->tab = NULL;
	}
	if (t)
		free(*t);
	*t = NULL;
}

void	ft_putllnbr(long long n)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n < 10)
		ft_putchar((char)n + '0');
	else if (n > 9)
	{
		ft_putllnbr(n / 10);
		ft_putllnbr(n % 10);
	}
}

t_tab		*ft_tabrev_leakless(t_tab *t)
{
	t_tab		*dup;
	int			tmp;
	size_t		start;
	size_t		end;

	start = 0;
	end = t->len - 1;
	if (!t->len || !(dup = ft_tabdup(t)))
		return (NULL);
	while (start < end)
	{
		tmp = dup->tab[start];
		dup->tab[start++] = dup->tab[end];
		dup->tab[end--] = tmp;
	}
	ft_tabdel(&t);
	return (dup);
}

t_tab		*ft_tabdup(t_tab *t)
{
	t_tab		*dup;

	if (!(dup = ft_tabnew(t->size)))
		return (NULL);
	dup = ft_tabcpy(dup, t);
	return (dup);
}

t_tab		*ft_tabcpy(t_tab *dest, const t_tab *src)
{
	size_t i;

	i = 0;
	while (i < src->len)
	{
		dest->tab[i] = src->tab[i];
		++i;
	}
	if (src->len > dest->len)
		dest->len = src->len;
	return (dest);
}

int		ft_tabisdescending(t_tab *t)
{
	size_t		i;

	i = 0;
	if (t->len < 1)
		return (0);
	else if (t->len == 1)
		return (1);
	while (i < t->len - 1)
	{
		if (t->tab[i] < t->tab[i + 1])
			return (0);
		++i;
	}
	return (1);
}
