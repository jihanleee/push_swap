/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihalee <jihalee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:06:47 by jihalee           #+#    #+#             */
/*   Updated: 2023/06/13 01:26:21 by jihalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_cdl	*ft_cdlstnew(int value)
{
	t_cdl	*new;

	new = (t_cdl *)malloc(sizeof(t_cdl));
	if (new == 0)
		return (NULL);
	new->next = 0;
	new->prev = 0;
	new->value = value;
	return (new);
}

void	infoclear(t_info *info)
{
	t_cdl	*next;
	t_cdl	*current;

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
	t_cdl	*current;
	int		i;

	info->top_a = ft_cdlstnew(info->nbrs[0]);
	if (info->top_a == 0)
		return (-1);
	info->bot_a = info->top_a;
	current = info->top_a;
	i = 1;
	while (i < info->size)
	{
		current->next = ft_cdlstnew(info->nbrs[i]);
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
