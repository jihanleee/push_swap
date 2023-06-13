/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihalee <jihalee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:22:19 by jihalee           #+#    #+#             */
/*   Updated: 2023/06/13 16:23:34 by jihalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotation(t_info *info)
{
	if (info->top_a->index > (info->size_a - 1) / 2)
		while (info->top_a->index)
			reverse_rotate_a(info);
	else
		while (info->top_a->index)
			rotate_a(info);
}

void	sort_many(t_info *info)
{
	tripartition(info);
	info->max_a = info->top_a->index;
	info->min_a = info->top_a->index;
	while (info->size_b)
	{
		info->min_ra = info->size;
		info->min_rb = info->size;
		simulate_r(info);
		do_double_rotation(info);
		do_rotation(info);
		push_a(info);
		if (info->top_a->index > info->max_a)
			info->max_a = info->top_a->index;
		if (info->top_a->index < info->min_a)
			info->min_a = info->top_a->index;
	}
	if (info->top_a->index < (info->size_a - 1) / 2)
		while (info->top_a->index)
			reverse_rotate_a(info);
	else
		while (info->top_a->index)
			rotate_a(info);
}

void	sort_3(t_info *info)
{
	int	first;
	int	second;
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

void	sort_4(t_info *info)
{
	while (info->size_a > 3)
	{
		if (info->bot_a->index == 1)
			reverse_rotate_a(info);
		while (info->top_a->index != 0)
			rotate_a(info);
		while (info->top_a->index == 0)
			push_b(info);
	}
	sort_3(info);
	while (info->size_b)
		push_a(info);
}

void	sort_5(t_info *info)
{
	while (info->size_a >= 4)
	{
		if (info->bot_a->index <= 1)
			reverse_rotate_a(info);
		while (info->top_a->index > 1)
			rotate_a(info);
		while (info->top_a->index <= 1)
			push_b(info);
	}
	sort_3(info);
	if (info->top_b->index == 0)
		swap_b(info);
	while (info->size_b)
		push_a(info);
}
