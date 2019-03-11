/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:54:51 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:54:51 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_checker.h>

void	ft_rrr(t_check **a, t_check **b, t_check **begina, t_check **beginb)
{
	ft_rra(a, begina);
	ft_rrb(b, beginb);
}

char	**ft_creastr(void)
{
	int		i;
	char	**str;

	if (!(str = (char**)malloc(sizeof(*str) * BUFF_STR)))
		return (0);
	i = -1;
	while (++i < BUFF_STR)
		if (!(str[i] = (char*)malloc(sizeof(**str) * 5)))
		{
			free(str);
			return (0);
		}
	return (str);
}

void	ft_delstr(char **str, int ret)
{
	while (++ret < BUFF_STR)
		free(str[ret]);
	free(str);
}
