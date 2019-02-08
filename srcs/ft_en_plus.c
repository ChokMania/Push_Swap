/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_en_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:04:25 by judumay           #+#    #+#             */
/*   Updated: 2019/02/08 11:41:30 by judumay          ###   ########.fr       */
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
