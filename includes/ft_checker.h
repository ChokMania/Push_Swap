/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:48:09 by judumay           #+#    #+#             */
/*   Updated: 2019/02/20 16:32:51 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H

# include <libft.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_check
{
	int				n;
	struct s_check	*next;
}				t_check;

t_check		*ft_read_inst(t_check *a, char str[1000][4]);
void		ft_error(t_check *p);
void		ft_free_lst(t_check *p);

#endif