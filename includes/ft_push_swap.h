/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:15:37 by judumay           #+#    #+#             */
/*   Updated: 2019/02/08 11:35:14 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <libft.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define ERROR -1
# define OK 0
# define KO 1

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct		s_checker_flags
{
	int				l;
	int				s;
	int				v;
}					t_checker_flags;

typedef struct		s_checker
{
	t_checker_flags *flags;
	t_tab			*a;
	t_tab			*b;
	int				rotation;
	int				nbrotations;
	int				argnb;
	int				fd;
	char			*line;
	int				error;
}					t_checker;

typedef struct		s_ps
{
	t_tab			*a;
	t_tab			*b;
	int				l;
	int				argnb;
	int				fd;
	int				q12;
	int				q19;
	int				q25;
	int				q32;
	int				q37;
	int				q44;
	int				median;
	int				q57;
	int				q62;
	int				q69;
	int				q75;
	int				q82;
	int				q87;
	int				q94;
	int				lastmove;
	size_t			lastmove_count;
}					t_ps;

void			ft_ps_use(void);
void			ft_ps_error(void);
void			ft_ps_mvt(t_ps *ps, int mv);


t_tab			*ft_tabnew(size_t size);
void			ft_tabdel(t_tab **t);
t_tab			*ft_tabrev(t_tab *t);
t_tab			*ft_tabdup(t_tab *t);
t_tab			*ft_tabcpy(t_tab *dest, const t_tab *src);
t_tab			*ft_tabswap(t_tab *t);
t_tab			*ft_tabrotate(t_tab *t);
t_tab			*ft_tabrevrotate(t_tab *t);
int				ft_tabmin(t_tab *t);
int				ft_tabisdescending(t_tab *t);
double			ft_tabmedian(t_tab *t);
void			ft_tabpush(t_tab *a, t_tab *b);
double			ft_tabpercentile(t_tab *t, int percentile);
t_tab			*ft_qsort(t_tab *t);
int				ft_tabisincreasing(t_tab *t);
int				ft_tabmax(t_tab *t);
size_t			ft_tabmaxpos(t_tab *t);

long			ft_atoi_strict(const char *nptr);
int				ft_strisdigit(const char *s);

//t_ps			*ft_ps_flags(t_ps *ps, int ac, char **av);
t_ps			*ft_ps_int(t_ps *ps, int ac, char **av);
t_ps			*ft_ps_args(t_ps *ps, char **av);
void			ft_ps_double(t_ps *ps);

t_ps			*ft_ps_solve(t_ps *ps);
void			ft_ps_solve2(t_ps *ps);

#endif