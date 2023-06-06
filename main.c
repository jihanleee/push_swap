/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihalee <jihalee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:06:56 by jihalee           #+#    #+#             */
/*   Updated: 2023/06/07 00:13:57 by jihalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	sorted;

	while (1)
	{
		sorted = 1;
		i = 0;
		while (i + 1 < size)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				sorted = 0;
			}
			i++;
		}
		if (sorted == 1)
			return ;
	}
}

long	ft_atol(const char *nptr)
{
	long	i;
	long	result;
	long	sign;

	sign = 1;
	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if (nptr[i] < '0' || nptr[i] > '9')
		return ((long)INT_MAX + 1);
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		if (result * sign < (long)INT_MIN || result * sign > (long)INT_MAX)
			return ((long)INT_MAX + 1);
		i++;
	}
	if (nptr[i] != 0)
		return ((long)INT_MAX + 1);
	return (result * sign);
}

t_bool	is_valid(char **av)
{
	int		i;
	int		j;
	long	nbr;

	i = 1;
	while (av[i])
	{
		nbr = ft_atol(av[i]);
		if (nbr < (long)INT_MIN || nbr > (long)INT_MAX)
			return (0);
		j = i + 1;
		while (av[j])
		{
			if (nbr == ft_atol(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	convert_nbrs(t_info *info, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		info->nbrs[i - 1] = ft_atol(av[i]);
		i++;
	}
	return ;
}

t_node	*ft_lstnew(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == 0)
		return (NULL);
	new->next = 0;
	new->prev = 0;
	new->value = value;
	return (new);
}

void	infoclear(t_info *info)
{
	t_node	*next;
	t_node	*current;

	free(info->nbrs);
	current = info->top_a;
	info->bot_a->next = 0;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	create_list(t_info *info)
{
	t_node	*current;
	int		i;

	info->top_a = ft_lstnew(info->nbrs[0]);
	if (info->top_a == 0)
		return (-1);
	info->bot_a = info->top_a;
	current = info->top_a;
	i = 1;
	while (i < info->size)
	{
		current->next = ft_lstnew(info->nbrs[i]);
		if (current->next == 0)
			return (infoclear(info), -1);
		current->next->prev = current;
		info->bot_a = current->next;
		current = current->next;
		info->top_a->prev = info->bot_a;
		info->bot_a->next = info->top_a;
		i++;
	}
	return (0);
}

int	init_info(t_info *info, int ac, char **av)
{
	info->size = ac - 1;
	info->size_a = ac - 1;
	info->size_b = 0;
	info->top_b = 0;
	info->bot_b = 0;
	info->nbrs = (int *)malloc(sizeof(int) * (ac - 1));
	if (info->nbrs == 0)
		return (-1);
	convert_nbrs(info, ac, av);
	create_list(info);
	ft_sort_int_tab(info->nbrs, info->size);
	return (0);
}

void	printinfo(t_info *info)
{
	ft_printf("size total\t %d\n", info->size);
	ft_printf("size a\t%d\n", info->size_a);
	ft_printf("size b\t%d\n", info->size_b);
}

void	printlists(t_info *info)
{
	t_node *current;

	ft_printf("------------stack a ------------\n");
	current = info->top_a;
	while (info->size_a)
	{
		ft_printf("val %d,", current->value);
		ft_printf("prev val %d,", current->prev->value);
		ft_printf("next val %d\n", current->next->value);
		if (current == info->bot_a)
			break;
		current = current->next;
	}
	ft_printf("------------stack b ------------\n");
	current = info->top_b;
	while (info->size_b)
	{
		ft_printf("val %d,", current->value);
		ft_printf("prev val %d,", current->prev->value);
		ft_printf("next val %d\n", current->next->value);
		if (current == info->bot_b)
			break;
		current = current->next;
	}
}

void push_a(t_info *info)
{
	t_node *tmp;

	if (info->size_b == 0)
		return;
	(info->size_b)--;
	if ((ft_printf("pa\n"), (info->size_a)++) == 0)
	{
		info->top_a = info->top_b;
		info->bot_a = info->top_a;
		info->top_b = info->top_b->next;
		info->top_b->prev = info->bot_b;
		info->bot_b->next = info->top_b;
		info->top_a->prev = info->bot_a;
		info->bot_a->next = info->top_a;
		return;
	}
	tmp = info->top_b;
	info->top_b = info->top_b->next;
	info->bot_b->next = info->top_b;
	info->top_b->prev = info->bot_b;
	tmp->next = info->top_a;
	tmp->prev = info->bot_a;
	info->top_a->prev = tmp;
	info->top_a = tmp;
	info->bot_a->next = info->top_a;
}

void push_b(t_info *info)
{
	t_node *tmp;

	if (info->size_a == 0)
		return;
	(info->size_a)--;
	if ((ft_printf("pb\n"), (info->size_b)++) == 0)
	{
		info->top_b = info->top_a;
		info->bot_b = info->top_b;
		info->top_a = info->top_a->next;
		info->top_a->prev = info->bot_a;
		info->bot_a->next = info->top_a;
		info->top_b->prev = info->bot_b;
		info->bot_b->next = info->top_b;
		return;
	}
	tmp = info->top_a;
	info->top_a = info->top_a->next;
	info->bot_a->next = info->top_a;
	info->top_a->prev = info->bot_a;
	tmp->next = info->top_b;
	tmp->prev = info->bot_b;
	info->top_b->prev = tmp;
	info->top_b = tmp;
	info->bot_b->next = info->top_b;
}

void swap_a(t_info *info)
{
	t_node *tmp_1st;
	t_node *tmp_2nd;

	if (info->size_a <= 1)
		return;
	ft_printf("sa\n");
	if (info->size_a == 2)
	{
		info->top_a = info->top_a->next;
		info->bot_a = info->bot_a->next;
		return;
	}
	tmp_1st = info->top_a;
	tmp_2nd = info->top_a->next;
	tmp_1st->next = tmp_2nd->next;
	tmp_2nd->next = tmp_1st;
	info->bot_a->next = tmp_2nd;
	info->top_a = tmp_2nd;
	info->top_a->next->prev = info->top_a;
	info->top_a->next->next->prev = info->top_a->next;
	info->top_a->prev = info->bot_a;
}

void	swap_b(t_info *info)
{
    t_node *tmp_1st;
    t_node *tmp_2nd;

    if (info->size_b <= 1)
    	return ;
	ft_printf("sb\n");
    if (info->size_b == 2)
    {
        info->top_b = info->top_b->next;
        info->bot_b = info->bot_b->next;
        return;
    }
	tmp_1st = info->top_b;
	tmp_2nd = info->top_b->next;
	tmp_1st->next = tmp_2nd->next;
	tmp_2nd->next = tmp_1st;
	info->bot_b->next = tmp_2nd;
	info->top_b = tmp_2nd;
	info->top_b->next->prev = info->top_b;
	info->top_b->next->next->prev = info->top_b->next;
	info->top_b->prev = info->bot_b;
}

void	double_swap(t_info *info)
{
	swap_a(info);
	swap_b(info);
}

void	rotate_a(t_info *info)
{
	if (info->size_a <= 1)
		return ;
	ft_printf("ra\n");
	info->top_a = info->top_a->next;
	info->bot_a = info->bot_a->next;
}

void	reverse_rotate_a(t_info *info)
{
	if (info->size_a <= 1)
		return ;
	ft_printf("rra\n");
	info->top_a = info->top_a->prev;
	info->bot_a = info->bot_a->prev;
}

void	rotate_b(t_info *info)
{
	if (info->size_b <= 1)
		return ;
	ft_printf("rb\n");
	info->top_b = info->top_b->next;
	info->bot_b = info->bot_b->next;
}

void	reverse_rotate_b(t_info *info)
{
	if (info->size_b <= 1)
		return ;
	ft_printf("rrb\n");
	info->top_b = info->top_b->prev;
	info->bot_b = info->bot_b->prev;
}

void	double_rotate(t_info *info)
{
	ft_printf("rr\n");
	rotate_a(info);
	rotate_b(info);
}

void	double_reverse_rotate(t_info *info)
{
	ft_printf("rrr\n");
	reverse_rotate_a(info);
	reverse_rotate_b(info);
}

int	ft_bsearch(int *nbrs, int size, int value)
{
	int	max;
	int	min;
	int	mid;

	min = 0;
	max = size - 1;
	mid = (min + max) / 2;
	while (1)
	{
		if (nbrs[mid] == value)
			return (mid);
		if (min >= max)
			return (-1);
		else if (nbrs[mid] < value)
			min = mid + 1;
		else if (nbrs[mid] > value)
			max = mid - 1;
		mid = (min + max) / 2;
	}
}

void	valtoindex(t_info *info)
{
	t_node	*current;

	current = info->top_a;
	while (info->size_a)
	{
		current->index = ft_bsearch(info->nbrs, info->size, current->value);
		if (current == info->bot_a)
			break;
		current = current->next;
	}
}

void	tripartition(t_info *info)
{
	while (info->size_a > (info->size) / 3)
	{
		if (info->top_a->index < (info->size) / 3)
		{
			push_b(info);
			rotate_b(info);
		}
		else if (info->top_a->index <= (info->size) * 2 / 3)
			push_b(info);
		else
			rotate_a(info);
	}
	while (info->size_a > 1)
		push_b(info);
}

int	sum_num_ops(t_info *info, int n_ra, int n_rb)
{
	int	sum;

	sum = 0;
	if (n_ra > (info->size_a - 1) / 2)
		sum += (info->size - n_ra);
	else
		sum += n_ra;
	if (n_rb > (info->size_a - 1) / 2)
		sum += (info->size - n_rb);
	else
		sum += n_rb;
	return (sum);
}

void	count_min_r(t_info *info, int *min_ra, int *min_rb)
{
	int		n_rb;
	int		n_ra;
	t_node	*current_a;
	t_node	*current_b;

	n_rb = 0;
	current_b = info->top_b;
	while (n_rb < info->size_b)
	{
		current_a = info->top_a;
		n_ra = 0;
		while (n_ra < info->size_a)
		{
			if ((current_a->index < current_b->index
				&& current_a->prev->index > current_b->index)
					&& sum_num_ops(info, n_ra, n_rb) < *min_ra + *min_rb)
			{
				*min_ra = n_ra;
				*min_rb = n_rb;
			}
			current_a = current_a->next;
			n_ra++;
		}
		current_b = current_b->next;
		n_rb++;
	}
}

void	do_minimum_rotation(t_info *info, int min_ra, int min_rb)
{
	int opp_ra;
	int	opp_rb;

	opp_ra = info->size_a - min_ra;
	opp_rb = info->size_b - min_rb;
		if (min_ra > (info->size_a - 1) / 2)
		{
			while (opp_ra--)
				reverse_rotate_a(info);
		}
		else
			while (min_ra--)
				rotate_a(info);
		if (min_rb > (info->size_b - 1) / 2)
		{
			while (opp_rb--)
				reverse_rotate_b(info);
		}
		else
			while (min_rb--)
				rotate_b(info);
}
void	sort_many(t_info *info)
{
	int		min_ra;
	int		min_rb;

	tripartition(info);
	push_a(info);
	while (info->size_b)
	{
		min_ra = info->size;
		min_rb = info->size;
		count_min_r(info, &min_ra, &min_rb);
		do_minimum_rotation(info, min_ra, min_rb);
		push_a(info);
	}
}

void	sort_3(t_info *info)
{
	int first;
	int second;
	int	third;

	first = info->top_a->index;
	second = info->top_a->next->index;
	third = info->top_a->next->next->index;
	if (first < second && second < third)
		return ;
	else if (first < third && third < second)
	{
		reverse_rotate_a(info);
		swap_a(info);
	}
	else if (second < first && first < third)
		swap_a(info);
	else if (third < first && first < second)
		reverse_rotate_a(info);
	else if (second < third && third < first)
		rotate_a(info);
	else if (third < second && second < first)
	{
		swap_a(info);
		reverse_rotate_a(info);
	}
}

void	sort_5(t_info *info)
{
	while (info->top_a->index <= 1)
		push_b(info);
	while (info->size_a >= 4)
	{
		if (info->bot_a->index <= 1)
			reverse_rotate_a(info);
		while (info->top_a->index > 1)
			rotate_a(info);
		while (info->top_a->index <= 1)
			push_b(info);
	}
	printlists(info);
	sort_3(info);
	if (info->top_b->index == 0)
		swap_b(info);
	while (info->size_b)
		push_a(info);
}

t_bool	is_sorted_list(t_info *info)
{
	int		i;
	t_node	*current;

	if (info->size_a != info->size)
		return (0);
	current = info->top_a;
	i = 0;
	while (i < info->size)
	{
		if (current->index != i)
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_info info;
	t_node *current;

	if (ac == 1)
		return (0);
	if (!is_valid(av))
		return (ft_printf("Error\n"), 0);
	if (ac == 2)
		return (0);
	init_info(&info, ac, av);
	valtoindex(&info);
	sort_many(&info);
	infoclear(&info);
	return (0);
}