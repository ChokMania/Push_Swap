/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:54:13 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:54:14 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mlx.h>

t_check		*ft_lstdup(t_check *temp)
{
	t_check	*new;
	t_check	*begine;

	if (!(new = (t_check *)malloc(sizeof(t_check))))
		return (0);
	begine = new;
	while (temp)
	{
		new->n = temp->n;
		if (!(new->next = (t_check *)malloc(sizeof(t_check))))
			return (0);
		temp = temp->next;
		if (temp)
			new = new->next;
	}
	free(new->next);
	new->next = NULL;
	new = begine;
	return (new);
}

void		ft_mergesort(t_check **headref)
{
	int			i;
	int			tmp;
	int			length;
	t_check		*begin;

	begin = *headref;
	length = ft_lstlene(headref);
	i = 0;
	while (i < length)
	{
		if (!((*headref)->next))
			(*headref) = begin;
		if ((*headref)->n > (*headref)->next->n)
		{
			tmp = (*headref)->n;
			(*headref)->n = (*headref)->next->n;
			(*headref)->next->n = tmp;
			i = 0;
		}
		else
			i++;
		(*headref) = (*headref)->next;
	}
	(*headref) = begin;
}

t_check		*ft_set_num(t_check *a)
{
	t_check		*tmp;
	t_check		*beg_a;
	t_check		*beg_tmp;
	int			i;

	beg_a = a;
	tmp = ft_lstdup(a);
	beg_tmp = tmp;
	ft_mergesort(&tmp);
	i = 1;
	while ((a = beg_a) && tmp)
	{
		while (a->n != tmp->n)
			a = a->next;
		a->nb_size = i++;
		tmp = tmp->next;
	}
	tmp = beg_tmp;
	ft_free_lst(tmp);
	return (a);
}

static void	ft_init_mlx(t_mlx *mlx, char **str, t_check *a, t_check *b)
{
	if (!(mlx->mlx = mlx_init()))
		ft_error_tmp();
	if (!(mlx->win = mlx_new_window(mlx->mlx, WINX, WINY, "Push_swap")))
		ft_error_tmp();
	if (!(mlx->img = mlx_new_image(mlx->mlx, WINX, WINY)))
		ft_error_tmp();
	ft_bzero(mlx->keyboard, sizeof(mlx->keyboard));
	mlx->canvas = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line
		, &mlx->endian);
	mlx->x = 0;
	mlx->y = 0;
	mlx->zoom = 10;
	mlx->str = str;
	mlx->i_str = 0;
	mlx->a = ft_set_num(a);
	mlx->b = b;
	mlx->max = ft_lstlene(&a);
	mlx->bega = a;
	mlx->begb = b;
	mlx->i = 0;
	mlx->speed = 0;
}

int			ft_mlx(char **str, t_check *a, t_check *b)
{
	t_mlx	mlx;

	ft_init_mlx(&mlx, str, a, b);
	mlx_hook(mlx.win, KEYPRESS, KEYPRESSMASK, key_press, &mlx);
	mlx_hook(mlx.win, KEYRELEASE, KEYRELEASEMASK, key_release, &mlx);
	mlx_hook(mlx.win, 17, KEYPRESSMASK, exite, &mlx);
	mlx_loop_hook(mlx.mlx, deal_key, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
