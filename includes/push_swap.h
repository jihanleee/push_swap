/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihalee <jihalee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:23:54 by jihalee           #+#    #+#             */
/*   Updated: 2023/06/13 16:23:58 by jihalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef int	t_bool;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}				t_cdl;

typedef struct s_info
{
	int		size;
	int		*nbrs;
	t_cdl	*top_a;
	t_cdl	*bot_a;
	int		min_ra;
	t_bool	reverse_a;
	int		min_rb;
	t_bool	reverse_b;
	int		max_a;
	int		min_a;
	int		size_a;
	t_cdl	*top_b;
	t_cdl	*bot_b;
	int		size_b;
}				t_info;

/*utilities*/
void	ft_putstr_fd(char const *s, int fd);
void	ft_swap(int *a, int *b);
void	ft_sort_int_tab(int *tab, int size);
int		ft_bsearch(int *nbrs, int size, int value);
long	ft_atol(const char *nptr);

/*I/O, list management*/
void	convert_nbrs(t_info *info, int ac, char **av);
t_cdl	*ft_cdlstnew(int value);
void	infoclear(t_info *info);
int		create_list(t_info *info);

int		init_info(t_info *info, int ac, char **av);
void	valtoindex(t_info *info);
t_bool	is_valid(char **av);
t_bool	is_sorted_list(t_info *info);

/*stack operations*/
void	push_a(t_info *info);
void	push_b(t_info *info);

void	swap_a_silent(t_info *info);
void	swap_b_silent(t_info *info);
void	swap_a(t_info *info);
void	swap_b(t_info *info);
void	double_swap(t_info *info);

void	rotate_a(t_info *info);
void	rotate_b(t_info *info);
void	reverse_rotate_a(t_info *info);
void	reverse_rotate_b(t_info *info);

void	double_rotate(t_info *info);
void	double_reverse_rotate(t_info *info);

/*rotation sort*/
void	tripartition(t_info *info);
void	get_min_r(t_info *info, int n_ra, int n_rb);
void	simulate_r(t_info *info);
void	do_double_rotation(t_info *info);
void	do_rotation(t_info *info);

void	final_rotation(t_info *info);
void	sort_many(t_info *info);
void	sort_3(t_info *info);
void	sort_4(t_info *info);
void	sort_5(t_info *info);

/*debug*/
void	printinfo(t_info *info);
void	printlists(t_info *info);
#endif