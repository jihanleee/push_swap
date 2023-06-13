/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihalee <jihalee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:21:12 by jihalee           #+#    #+#             */
/*   Updated: 2023/06/13 01:26:21 by jihalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	get_min_r(t_info *info, int n_ra, int n_rb)
{
	int	abs_ra;
	int	abs_rb;

	abs_ra = n_ra;
	abs_rb = n_rb;
	if (n_ra > (info->size_a - 1) / 2)
		abs_ra = info->size_a - n_ra;
	if (n_rb > (info->size_b - 1) / 2)
		abs_rb = info->size_b - n_rb;
	if (abs_ra + abs_rb < info->min_ra + info->min_rb)
	{
		info->min_ra = abs_ra;
		info->min_rb = abs_rb;
		info->reverse_a = (n_ra > (info->size_a - 1) / 2);
		info->reverse_b = (n_rb > (info->size_b - 1) / 2);
	}
}

void	simulate_r(t_info *info)
{
	int		n_rb;
	int		n_ra;
	t_cdl	*current_a;
	t_cdl	*current_b;

	n_rb = 0;
	current_b = info->top_b;
	while (n_rb < info->size_b)
	{
		current_a = info->top_a;
		n_ra = 0;
		while (n_ra < info->size_a)
		{
			if ((current_a->index == info->min_a
					&& (current_b->index < info->min_a
						|| current_b->index > info->max_a))
				|| ((current_a->index > current_b->index
						&& current_a->prev->index < current_b->index)))
				get_min_r(info, n_ra, n_rb);
			current_a = current_a->next;
			n_ra++;
		}
		current_b = current_b->next;
		n_rb++;
	}
}

void	do_double_rotation(t_info *info)
{
	if (info->reverse_a && info->reverse_b)
	{
		while (info->min_ra && info->min_rb)
		{
			double_reverse_rotate(info);
			(info->min_ra)--;
			(info->min_rb)--;
		}
	}
	else if (!info->reverse_a && !info->reverse_b)
	{
		while (info->min_ra && info->min_rb)
		{
			double_rotate(info);
			(info->min_ra)--;
			(info->min_rb)--;
		}
	}
}

void	do_rotation(t_info *info)
{
	while (info->reverse_a && info->min_ra)
	{
		reverse_rotate_a(info);
		(info->min_ra)--;
	}
	while (!(info->reverse_a) && info->min_ra)
	{
		rotate_a(info);
		(info->min_ra)--;
	}
	while (info->reverse_b && info->min_rb)
	{
		reverse_rotate_b(info);
		(info->min_rb)--;
	}
	while (!(info->reverse_b) && info->min_rb)
	{
		rotate_b(info);
		(info->min_rb)--;
	}
}
