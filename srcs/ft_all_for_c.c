/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_for_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:10:02 by judumay           #+#    #+#             */
/*   Updated: 2019/02/07 20:30:56 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

t_checker	*ft_init_c(t_checker *c)
{
	if (!(c = ft_memalloc(sizeof(t_checker)))
		|| !(c->a = ft_tabnew(1000000))
		|| !(c->b = ft_tabnew(1000000)))
		return (NULL);
	c->argnb = 1;
	c->rotation = 0;
	c->nbrotations = 0;
	c->fd = 0;
	c->error = 0;
	return (c);
}

int			ft_free_c(t_checker *c)
{
	ft_tabdel(&c->a);
	ft_tabdel(&c->b);
	ft_memdel((void**)&c);
	return (1);
}
