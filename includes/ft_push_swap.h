/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:15:37 by judumay           #+#    #+#             */
/*   Updated: 2019/02/07 22:48:37 by judumay          ###   ########.fr       */
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

typedef struct		s_tab
{
	int				*tab;
	size_t			len;
	size_t			size;
}					t_tab;

typedef struct		s_checker
{
	t_tab			*a;
	t_tab			*b;
	int				rotation;
	int				nbrotations;
	int				argnb;
	int				fd;
	char			*line;
	int				error;
}					t_checker;

typedef struct		s_push_swap
{
	t_tab			*a;
	t_tab			*b;
	int				l;
	int				argnb;
	int				fd;
	int				tab[14];
	int				median;
	int				lastmove;
	size_t			lastmove_count;
}					t_push_swap;

int					ft_free_c(t_checker *c);
int					ft_usage(void);;
int					ft_tabisdescending(t_tab *t);
int					ft_display_result(int result);
int					ft_strisdigit(const char *s);
void				ft_tabdel(t_tab **t);
void				ft_putllnbr(long long n);
void				checker_parsing_doubles(t_checker *c);
long				ft_atoi_strict(const char *nptr);
void				ft_tabpush(t_tab *a, t_tab *b);
t_tab				*ft_tabswap(t_tab *t);
t_tab				*ft_tabrotate(t_tab *t);
t_tab				*ft_tabrevrotate(t_tab *t);
t_tab				*ft_tabrev_leakless(t_tab *t);
t_tab				*ft_tabdup(t_tab *t);
t_tab				*ft_tabnew(size_t size);
t_tab				*ft_tabcpy(t_tab *dest, const t_tab *src);
t_checker			*checker_parsing_integers(t_checker *c, int ac, char **av);
t_checker			*checker_parsing_bash_arg(t_checker *c, char **av);
t_checker			*checker_parsing_movements(t_checker *c);
t_checker			*checker_movements(t_checker *c);
t_checker			*ft_init_c(t_checker *c);

#endif