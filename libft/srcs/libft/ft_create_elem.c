/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:26:45 by judumay           #+#    #+#             */
/*   Updated: 2018/11/26 21:27:32 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem)
	{
		elem->content = data;
		elem->next = NULL;
	}
	return (elem);
}
