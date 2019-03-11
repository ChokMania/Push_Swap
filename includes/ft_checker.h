/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:53:11 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:53:12 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H

# include <libft.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUF_SIZE 2
# define BUFF_STR 1000000

typedef struct	s_check
{
	int				n;
	struct s_check	*next;
	int				nb_size;
}				t_check;

typedef	struct	s_mem
{
	int		memv;
}				t_mem;

int				ft_lstlene(t_check **list);
void			ft_error_check(t_check *p, char **str);
int				ft_check_input(char *str);
void			ft_delstr(char **str, int ret);
char			**ft_creastr(void);
void			ft_error(t_check *p);
void			ft_free_lst(t_check *p);
void			ft_del_first(t_check **begin_list);
void			ft_sa(t_check **a, t_check **begina);
void			ft_sb(t_check **b, t_check **beginb);
void			ft_ss(t_check **a, t_check **b, t_check **begina,
	t_check **beginb);
void			ft_pa(t_check **a, t_check **b, t_check **begina,
	t_check **beginb);
void			ft_pb(t_check **a, t_check **b, t_check **begina,
	t_check **beginb);
void			ft_ra(t_check **a, t_check **begina);
void			ft_rb(t_check **b, t_check **beginb);
void			ft_rr(t_check **a, t_check **b, t_check **begina,
	t_check **beginb);
void			ft_rra(t_check **a, t_check **begina);
void			ft_rrb(t_check **b, t_check **beginb);
void			ft_rrr(t_check **a, t_check **b, t_check **begina,
	t_check **beginb);
void			ft_suite(int ret, char **str, t_check *p);
t_check			*ft_read_inst(t_check *a, char **str, int choix);
t_check			*ft_create_eleme(int n);
t_check			**ft_list_push_fronte(t_check **begin_list, int n);
int				ft_check_inpute(char *str);
int				ft_intput(char *av, int ac, int j, t_mem *mem);

int				ft_mlx(char **str, t_check *a, t_check *b);

#endif
