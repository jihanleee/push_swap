/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihalee <jihalee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:10:36 by jihalee           #+#    #+#             */
/*   Updated: 2023/06/13 01:26:21 by jihalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_info *info)
{
	t_cdl	*tmp;

	if (info->size_b == 0)
		return ;
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
		return ;
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

void	push_b(t_info *info)
{
	t_cdl	*tmp;

	if (info->size_a == 0)
		return ;
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
		return ;
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
