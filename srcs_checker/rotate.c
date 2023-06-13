/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihalee <jihalee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:14:57 by jihalee           #+#    #+#             */
/*   Updated: 2023/06/13 02:05:03 by jihalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_info *info)
{
	if (info->size_a <= 1)
		return ;
	info->top_a = info->top_a->next;
	info->bot_a = info->bot_a->next;
}

void	reverse_rotate_a(t_info *info)
{
	if (info->size_a <= 1)
		return ;
	info->top_a = info->top_a->prev;
	info->bot_a = info->bot_a->prev;
}

void	rotate_b(t_info *info)
{
	if (info->size_b <= 1)
		return ;
	info->top_b = info->top_b->next;
	info->bot_b = info->bot_b->next;
}

void	reverse_rotate_b(t_info *info)
{
	if (info->size_b <= 1)
		return ;
	info->top_b = info->top_b->prev;
	info->bot_b = info->bot_b->prev;
}
