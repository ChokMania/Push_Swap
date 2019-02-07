/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:05:53 by anmauffr          #+#    #+#             */
/*   Updated: 2019/02/07 10:44:37 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

int		ft_printf(char *format, ...)
{
	__int32_t	ret;
	t_printf	*p;

	p = NULL;
	ret = 0;
	if (!format || !(p = init_t_printf(p)))
		return (-1);
	va_start(p->ap, format);
	ft_printf_display(p, format);
	va_end(p->ap);
	ret = p->ret;
	if (p->error == 1)
		ret = -1;
	reset_t_printf(p);
	del_t_printf(p);
	return (ret);
}
