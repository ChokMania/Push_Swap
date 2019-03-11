/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:53:56 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:53:57 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <libft.h>
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

typedef struct	s_pile
{
	t_checke	*a;
	t_checke	*b;
	t_checke	*temp;
}				t_pile;

int				ft_lstl(t_checke **list);
int				ft_median(t_pile *pile, t_begin *begin, t_ps **comp, int n);
int				ft_lst_compare(t_checke *p, t_checke *finish);
void			ft_error(t_checke *p);
void			ft_printlist(t_checke *node);
void			ft_mergesort(t_checke **headref);
void			ft_free_lst(t_checke **p);
void			ft_free_lst_ps(t_ps *p);
void			ft_display(t_checke *p, t_ps *comp);
void			ft_error_ps(t_pile *pile, t_begin *begin, t_ps *comp);
void			ft_ra(t_checke **a, t_checke **begina, int n);
void			ft_rb(t_checke **b, t_checke **beginb, int n);
void			ft_rra(t_checke **a, t_checke **begina, int n);
void			ft_rrb(t_checke **b, t_checke **beginb, int n);
void			ft_sa(t_checke **a, t_checke **begina, int n);
void			ft_sb(t_checke **b, t_checke **beginb, int n);
void			ft_ss(t_checke **a, t_checke **b,
	t_checke **begina, t_checke **beginb);
void			ft_1(t_checke **a, t_checke **begina);
void			ft_2(t_checke **a, t_checke **begina);
void			ft_3(t_checke **a, t_checke **begina);
void			ft_4(t_checke **a, t_checke **begina);
void			ft_lstdel_oklm(t_checke **a, t_checke **begina, int median);
void			ft_sort3(t_checke **a, t_checke **begina);
void			ft_init_begin(t_begin *begin, t_checke *a, t_checke *b,
	t_ps *comp);
void			ft_init_comp(t_ps **comp, t_pile *pile, t_begin *begin, int i);
void			ft_pb(t_checke **a, t_checke **b, t_checke **begina,
	t_checke **beginb);
void			ft_rrr(t_checke **a, t_checke **b, t_checke **begina,
	t_checke **beginb);
void			ft_rr(t_checke **a, t_checke **b, t_checke **begina,
	t_checke **beginb);
void			ft_pa(t_checke **a, t_checke **b, t_checke **begina,
	t_checke **beginb);
t_checke		*ft_3fast(t_checke **a, t_begin *b);
t_checke		*ft_quicksort(t_pile *pile, t_begin *begin, t_ps **comp,
	t_checke *finish);
t_checke		*ft_choice(t_pile	*pile);
t_checke		*ft_lstdup(t_checke *temp, t_pile *pile, t_begin *begin,
	t_ps **comp);
t_checke		*ft_lstndupa(t_pile *pile, t_begin *begin, t_ps **comp, int n);
t_checke		*ft_lstndupb(t_pile *pile, t_begin *begin, t_ps **comp, int n);
int				ft_is_sorted(t_checke *a);
#endif
