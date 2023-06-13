/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihalee <jihalee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:12:33 by jihalee           #+#    #+#             */
/*   Updated: 2023/06/13 01:26:21 by jihalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_silent(t_info *info)
{
	t_cdl	*tmp_1st;
	t_cdl	*tmp_2nd;

	if (info->size_a <= 1)
		return ;
	if (info->size_a == 2)
	{
		info->top_a = info->top_a->next;
		info->bot_a = info->bot_a->next;
		return ;
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

void	swap_b_silent(t_info *info)
{
	t_cdl	*tmp_1st;
	t_cdl	*tmp_2nd;

	if (info->size_b <= 1)
		return ;
	if (info->size_b == 2)
	{
		info->top_b = info->top_b->next;
		info->bot_b = info->bot_b->next;
		return ;
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

void	swap_a(t_info *info)
{
	ft_printf("sa\n");
	swap_a_silent(info);
}

void	swap_b(t_info *info)
{
	ft_printf("sb\n");
	swap_b_silent(info);
}

void	double_swap(t_info *info)
{
	ft_printf("ss\n");
	swap_a_silent(info);
	swap_b_silent(info);
}
