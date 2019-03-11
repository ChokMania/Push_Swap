/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:54:08 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:57:41 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mlx.h>

int				key_press(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (key == KEY_SPACEBAR)
		;
	else
		mlx->keyboard[key] = 1;
	return (0);
}

int				key_release(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (key == KEY_SPACEBAR)
		mlx->keyboard[key] = mlx->keyboard[KEY_SPACEBAR] ? 0 : 1;
	else if (key == KEY_PAD_SUB || key == KEY_PAD_ADD)
		mlx->speed = key != KEY_PAD_SUB ? 0 : 1;
	else
		mlx->keyboard[key] = 0;
	return (0);
}

t_mlx			*tareum(t_mlx *mlx)
{
	!ft_strcmp(mlx->str[mlx->i_str], "sa\n") ? ft_sa(&mlx->a, &mlx->bega) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "sb\n") ? ft_sb(&mlx->b, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "ss\n") ? ft_ss(&mlx->a, &mlx->b,
		&mlx->bega, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "pa\n") ? ft_pa(&mlx->a, &mlx->b
		, &mlx->bega, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "pb\n") ? ft_pb(&mlx->a, &mlx->b
	, &mlx->bega, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "ra\n") ? ft_ra(&mlx->a, &mlx->bega) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rb\n") ? ft_rb(&mlx->b, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rr\n") ? ft_rr(&mlx->a, &mlx->b
	, &mlx->bega, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rra\n") ? ft_rra(&mlx->a, &mlx->bega) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rrb\n") ? ft_rrb(&mlx->b, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rrr\n") ? ft_rrr(&mlx->a, &mlx->b
	, &mlx->bega, &mlx->begb) : 0;
	return (mlx);
}

t_mlx			*tareum_inv(t_mlx *mlx)
{
	!ft_strcmp(mlx->str[mlx->i_str], "sa\n") ? ft_sa(&mlx->a, &mlx->bega) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "sb\n") ? ft_sb(&mlx->b, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "ss\n") ? ft_ss(&mlx->a, &mlx->b,
		&mlx->bega, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "pa\n") ? ft_pb(&mlx->a, &mlx->b
		, &mlx->bega, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "pb\n") ? ft_pa(&mlx->a, &mlx->b
	, &mlx->bega, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "ra\n") ? ft_rra(&mlx->a, &mlx->bega) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rb\n") ? ft_rrb(&mlx->b, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rr\n") ? ft_rrr(&mlx->a, &mlx->b
	, &mlx->bega, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rra\n") ? ft_ra(&mlx->a, &mlx->bega) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rrb\n") ? ft_rb(&mlx->b, &mlx->begb) : 0;
	!ft_strcmp(mlx->str[mlx->i_str], "rrr\n") ? ft_rr(&mlx->a, &mlx->b
	, &mlx->bega, &mlx->begb) : 0;
	return (mlx);
}

int				deal_key(void *param)
{
	t_mlx	*mlx;
	int		tmp;

	mlx = (t_mlx *)param;
	(tmp = -4) && (mlx->keyboard[KEY_ESC]) ? exite(mlx) : 0;
	if ((mlx->keyboard[KEY_RIGHT] && mlx->str[mlx->i_str][0] != 0)
		|| (mlx->keyboard[KEY_LEFT] && mlx->i_str > 0))
		ft_suite_mlx(mlx);
	if (mlx->keyboard[KEY_SPACEBAR] == 1 && mlx->str[mlx->i_str][0] != 0)
	{
		tareum(mlx);
		mlx->speed == 0 ? usleep(1000) : usleep(100000);
		mlx->str[++mlx->i_str][0] == 0 ? mlx->keyboard[KEY_SPACEBAR] = 0 : 0;
	}
	ft_bzero(mlx->canvas, 4 * WINX * WINY);
	while (!(tmp += 4) || tmp < 4 * WINX * WINY)
		*(int *)&mlx->canvas[tmp] = tmp >= 4 * WINX * (WINY / 2) && tmp < 4
			* WINX * ((WINY / 2) + 1) ? 0x00FF0000 : 0x00000000;
	print_stack(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_string_put(mlx->mlx, mlx->win, WINX - 100, 10
		, 0xFFFFFF, mlx->str[mlx->i_str]);
	mlx->str[mlx->i_str][0] == 0 && mlx->i == 0 && (mlx->i = 1)
		? ft_checke_value(&mlx) : 0;
	return (0);
}
