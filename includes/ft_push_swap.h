/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:15:37 by judumay           #+#    #+#             */
/*   Updated: 2019/02/26 12:23:11 by judumay          ###   ########.fr       */
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

typedef struct	s_begin
{
	t_checke	*begina;
	t_checke	*beginb;
	t_ps		*beginc;
}				t_begin;

void			ft_error(t_checke *p);
t_checke		*ft_choice(t_checke *begin);
int				ft_lstl(t_checke **list);
t_checke		*ft_quicksort(t_checke *a);
int				ft_median(t_checke *p, int n);
void			ft_printlist(t_checke *node);
void			ft_mergesort(t_checke **headref);
t_checke		*ft_lstdup(t_checke *t);
void			ft_free_lst(t_checke *p);
void			ft_free_lst_ps(t_ps *p);
void			ft_display(t_checke *begina, t_ps *comp);
int				ft_lst_compare(t_checke *p, t_checke *finish);
t_checke		*ft_lstndup(t_checke *t, int n);

void			ft_ra(t_checke **a, t_checke **begina, int n);
void			ft_rb(t_checke **b, t_checke **beginb, int n);
void			ft_rr(t_checke **a, t_checke **b, t_checke **begina,
	t_checke **beginb);
void			ft_rra(t_checke **a, t_checke **begina, int n);
void			ft_rrb(t_checke **b, t_checke **beginb, int n);
void			ft_sa(t_checke *a, int n);
void			ft_sb(t_checke *b, int n);
void			ft_ss(t_checke *a, t_checke *b);
void			ft_pa(t_checke **a, t_checke **b, t_checke **begina,
	t_checke **beginb);
void			ft_pbe(t_checke **a, t_checke **b, t_checke **begina,
	t_checke **beginb);
void			ft_rrr(t_checke **a, t_checke **b, t_checke **begina,
	t_checke **beginb);
void			ft_1(t_checke *a, t_checke *begina);
void			ft_2(t_checke *a, t_checke *begina);
void			ft_3(t_checke *a, t_checke *begina);
void			ft_4(t_checke *a, t_checke *begina);

#endif
