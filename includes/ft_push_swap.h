/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramard <lramard@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:15:37 by judumay           #+#    #+#             */
/*   Updated: 2019/02/21 17:55:29 by lramard          ###   ########.fr       */
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

void			ft_error(t_checke *p);
t_checke		*ft_choice(t_checke *begin);
int				ft_lstl(t_checke *list);
void			ft_quicksort(t_checke *a);
int				ft_median(t_checke *p, int n);
void			ft_printlist(t_checke *node);
void			ft_mergesort(t_checke **headref);

void			ft_ra(t_checke **a, t_checke **begina);
void			ft_rb(t_checke **b, t_checke **beginb);
void			ft_rr(t_checke **a, t_checke **b, t_checke **begina,
	t_checke **beginb);
void			ft_rra(t_checke **a, t_checke **begina);
void			ft_rrb(t_checke **b, t_checke **beginb);
void			ft_sa(t_checke *a);
void			ft_sb(t_checke *b);
void			ft_ss(t_checke *a, t_checke *b);
void			ft_pa(t_checke **a, t_checke **b, t_checke **begina,
	t_checke **beginb);
void			ft_pb(t_checke **a, t_checke **b, t_checke **begina,
	t_checke **beginb);
void			ft_rrr(t_checke **a, t_checke **b, t_checke **begina,
	t_checke **beginb);

#endif