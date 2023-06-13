/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihalee <jihalee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:08:16 by jihalee           #+#    #+#             */
/*   Updated: 2023/06/13 01:26:21 by jihalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_info(t_info *info, int ac, char **av)
{
	info->size = ac - 1;
	info->size_a = ac - 1;
	info->size_b = 0;
	info->top_b = 0;
	info->bot_b = 0;
	info->max_a = info->size - 1;
	info->min_a = info->size - 1;
	info->nbrs = (int *)malloc(sizeof(int) * (ac - 1));
	if (info->nbrs == 0)
		return (-1);
	convert_nbrs(info, ac, av);
	if (create_list(info) == -1)
		return (-1);
	ft_sort_int_tab(info->nbrs, info->size);
	return (0);
}

void	valtoindex(t_info *info)
{
	t_cdl	*current;

	current = info->top_a;
	while (info->size_a)
	{
		current->index = ft_bsearch(info->nbrs, info->size, current->value);
		if (current == info->bot_a)
			break ;
		current = current->next;
	}
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

t_bool	is_sorted_list(t_info *info)
{
	int		i;
	t_cdl	*current;

	if (info->size_a != info->size)
		return (0);
	current = info->top_a;
	i = 0;
	while (i < info->size)
	{
		if (current->index != i)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}
