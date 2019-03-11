/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:54:18 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:54:19 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mlx.h>

void		ft_error_tmp(void)
{
	ft_printf("Error !\n");
	exit(0);
}

int			exite(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_free_this(&mlx);
	exit(0);
}

void		ft_free_this(t_mlx **mlx)
{
	if ((*mlx)->begb)
		ft_free_lst((*mlx)->begb);
	(*mlx)->bega ? ft_free_lst((*mlx)->bega) : 0;
	ft_delstr((*mlx)->str, -1);
}

static void	ft_checker_b(t_mlx **mlx)
{
	if ((*mlx)->begb)
	{
		ft_free_lst((*mlx)->begb);
		(*mlx)->bega ? ft_free_lst((*mlx)->bega) : 0;
		ft_delstr((*mlx)->str, -1);
		ft_printf("KO\n");
		exit(0);
	}
}

void		ft_checke_value(t_mlx **mlx)
{
	ft_checker_b(mlx);
	while ((*mlx)->a->next)
	{
		if ((*mlx)->a->n > (*mlx)->a->next->n && ft_printf("KO\n"))
			return ;
		(*mlx)->a = (*mlx)->a->next;
	}
	ft_printf("OK\n");
}
