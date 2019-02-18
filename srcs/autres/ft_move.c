/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:41:17 by judumay           #+#    #+#             */
/*   Updated: 2019/02/18 16:47:34 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_sa(int *tab_a, int *tab_b)
{

}

int main(void)
{
	int tab_a[5] = {1, 2, 3, 4};
	int	tab_b[5] = {9, 8, 7, 6};

	ft_sa(tab_a, tab_b);
	printf("|  a  |\n|  %d  |\n|  %d  |\n|  %d  |\n|  %d  |\n",
	tab_a[0], tab_a[0], tab_a[1], tab_a[2], tab_a[3]);
	printf("|  b  |\n|  %d  |\n|  %d  |\n|  %d  |\n|  %d  |\n",
	tab_b[0], tab_b[0], tab_b[1], tab_b[2], tab_b[3]);

}