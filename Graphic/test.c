/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:35:15 by anmauffr          #+#    #+#             */
/*   Updated: 2019/03/05 15:16:56 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_H 4
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_SIX 22
# define KEY_FIVE 23
# define KEY_NINE 25
# define KEY_SEVEN 26
# define KEY_EIGHT 28
# define KEY_ZERO 29
# define KEY_BRACE_R 30
# define KEY_O 31
# define KEY_U 32
# define KEY_BRACE_L 33
# define KEY_I 34
# define KEY_P 35
# define KEY_L 37
# define KEY_J 38
# define KEY_K 40
# define KEY_SEMI 41
# define KEY_N 45
# define KEY_M 46
# define KEY_TAB 48
# define KEY_ESC 53
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

typedef struct	t_ptr
{
	void	*mlx;
	void	*win;
}				s_ptr;

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

int		deal_key(int key, void *param)
{
	(void)param;
	if (key == KEY_ESC)
		exit (0);
	return (0);
}

void	ft_print_rec1(s_ptr *ptr, t_coord coord, int size_x, int size_y)
{
	int memo_x;
	int memo_y;

	memo_y = coord.y;
	while (coord.y < memo_y + size_y)
		mlx_pixel_put(ptr->mlx, ptr->win, coord.x, coord.y++, 0xFFFFFF);
	memo_x = coord.x;
	while (coord.x < memo_x + size_x)
		mlx_pixel_put(ptr->mlx, ptr->win, coord.x++, coord.y, 0xFFFFFF);
	while (coord.y - memo_y > 0)
		mlx_pixel_put(ptr->mlx, ptr->win, coord.x, coord.y--, 0xFFFFFF);
	while (coord.x - memo_x > 0)
		mlx_pixel_put(ptr->mlx, ptr->win, coord.x--, coord.y, 0xFFFFFF);
}

void	ft_ok(void)
{
	s_ptr	*ptr;
	t_coord	coord;
	int			i;

	coord.x = 50;
	coord.y = 50;
	i = 0;
	ptr = (s_ptr*)malloc(sizeof(*ptr) * 1);
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, 1920, 1080, "mlx 42");
	
	while (i < 1920)
		mlx_pixel_put(ptr->mlx, ptr->win, i++, 540, 0xEEEEEE);
	ft_print_rec1(ptr, coord, 15, 50);
	
	mlx_key_hook(ptr->win, deal_key, 0);
	mlx_loop(ptr->mlx);
}

int		main()
{
	ft_ok();
	return (0);
}