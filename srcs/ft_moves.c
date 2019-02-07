/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:33:31 by judumay           #+#    #+#             */
/*   Updated: 2019/02/07 22:37:06 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

int		ft_strisdigit(const char *s)
{
	size_t		i;

	i = 0;
	if (!s || !s[i])
		return (0);
	while (s[i] && ft_isdigit(s[i]))
		++i;
	if (!s[i])
		return (1);
	return (0);
}

t_tab		*ft_tabrevrotate(t_tab *t)
{
	int		tmp;
	int		tmp2;
	size_t	i;

	i = t->len - 1;
	if (!t || !t->len || t->size < t->len)
		return (t);
	tmp = t->tab[t->len - 1];
	while (i)
	{
		tmp2 = t->tab[i - 1];
		t->tab[i-- - 1] = tmp;
		tmp = tmp2;
	}
	t->tab[t->len - 1] = tmp;
	return (t);
}

t_tab		*ft_tabrotate(t_tab *t)
{
	int		tmp;
	int		tmp2;
	size_t	i;

	i = 1;
	if (!t || !t->len || t->size < t->len)
		return (t);
	tmp = t->tab[0];
	t->tab[0] = t->tab[t->len - 1];
	while (i < t->len)
	{
		tmp2 = t->tab[i];
		t->tab[i++] = tmp;
		tmp = tmp2;
	}
	return (t);
}

t_tab		*ft_tabswap(t_tab *t)
{
	int		tmp;

	if (t->size < t->len || t->len < 2)
		return (t);
	tmp = t->tab[t->len - 1];
	t->tab[t->len - 1] = t->tab[t->len - 2];
	t->tab[t->len - 2] = tmp;
	return (t);
}

void		ft_tabpush(t_tab *a, t_tab *b)
{
	if (!a->len || a->size < a->len || b->size <= b->len)
		return ;
	b->tab[b->len++] = a->tab[a->len-- - 1];
}

long		ft_atoi_strict(const char *nptr)
{
	size_t	zero;
	size_t	len;
	size_t	i;

	zero = 0;
	if (!nptr[0]
		|| !((ft_isdigit(nptr[0]) || nptr[0] == '+'
		|| nptr[0] == '-') && (ft_strisdigit(&nptr[1])
		|| (!nptr[1] && ft_isdigit(nptr[0])))))
		return (10000000000);
	len = ft_strlen(nptr);
	if ((i = 1) && nptr[0] == '0')
		++zero;
	while (i < len && nptr[i++] == '0')
		++zero;
	if (len > 11 + zero
		|| (len == 11 + zero && ft_isdigit(nptr[0]))
		|| (len == 10 + zero
		&& ft_strcmp(nptr, "2147483647") > 0)
		|| (len == 11 + zero && nptr[0] == '+'
		&& ft_strcmp(&nptr[1 + zero], "2147483647") > 0)
		|| (len == 11 + zero && nptr[0] == '-'
		&& ft_strcmp(&nptr[1 + zero], "2147483648") > 0))
		return (10000000000);
	return ((int)ft_atoi(nptr));
}
