/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihalee <jihalee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:15:20 by jihalee           #+#    #+#             */
/*   Updated: 2023/06/12 18:15:40 by jihalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_rotate(t_info *info)
{
	if (info->size_a > 1)
	{
		info->top_a = info->top_a->next;
		info->bot_a = info->bot_a->next;
	}
	if (info->size_b > 1)
	{
		info->top_b = info->top_b->next;
		info->bot_b = info->bot_b->next;
	}
	ft_printf("rr\n");
}

void	double_reverse_rotate(t_info *info)
{
	if (info->size_a > 1)
	{
		info->top_a = info->top_a->prev;
		info->bot_a = info->bot_a->prev;
	}
	if (info->size_b > 1)
	{
		info->top_b = info->top_b->prev;
		info->bot_b = info->bot_b->prev;
	}
	ft_printf("rrr\n");
}
