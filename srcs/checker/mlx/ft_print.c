/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:54:23 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:54:24 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mlx.h>

void		put_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (x >= 0 && x < WINX && y >= 0 && y < WINY)
		*(int *)&mlx->canvas[y * mlx->size_line + (x * 4)] = color;
}

void		print_square_a(int x, int y, t_mlx *mlx)
{
	int i;
	int j;

	j = -1;
	while (++j <= mlx->a->nb_size * ((WINY / 2) / mlx->max) && (i = -1))
		while (++i < ((WINX - 10) / mlx->max) - (((WINX - 10) / mlx->max) / 5))
			put_pixel(mlx, x + i, y - j, color(mlx->max, mlx->a->nb_size));
}

void		print_square_b(int x, int y, t_mlx *mlx)
{
	int i;
	int j;

	j = -1;
	while (++j <= mlx->b->nb_size * ((WINY / 2) / mlx->max) && (i = -1))
		while (++i < ((WINX - 10) / mlx->max) - (((WINX - 10) / mlx->max) / 5))
			put_pixel(mlx, x + i, y + j, color(mlx->max, mlx->b->nb_size));
}

void		print_stack(t_mlx *mlx)
{
	int		i_a;
	int		i_b;

	mlx->a = mlx->bega;
	i_a = 0;
	while (++i_a && mlx->a)
	{
		print_square_a(i_a * ((WINX - 10) / mlx->max) - (WINX / mlx->max) + 15
			, (WINY / 2 - 10), mlx);
		mlx->a = mlx->a->next;
	}
	mlx->a = mlx->bega;
	mlx->b = mlx->begb;
	i_b = 0;
	while (++i_b && mlx->b)
	{
		print_square_b(i_b * ((WINX - 10) / mlx->max) - (WINX / mlx->max) + 15
			, (WINY / 2 + 10), mlx);
		mlx->b = mlx->b->next;
	}
	mlx->b = mlx->begb;
}
