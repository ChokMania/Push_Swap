/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:15:37 by judumay           #+#    #+#             */
/*   Updated: 2019/02/21 15:43:12 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <libft.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_checke
{
	int				n;
	struct s_checke	*next;
}				t_checke;

typedef struct	s_ps
{
	int				median;
	int				nbblock;
	int				size;
	struct s_ps		*next;
}				t_ps;

void		ft_error(t_checke *p);
t_checke	*ft_choice(t_checke *begin);

#endif