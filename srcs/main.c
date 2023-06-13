/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihalee <jihalee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:06:56 by jihalee           #+#    #+#             */
/*   Updated: 2023/06/13 14:26:11 by jihalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printinfo(t_info *info)
{
	ft_printf("size total\t %d\n", info->size);
	ft_printf("size a\t%d\n", info->size_a);
	ft_printf("size b\t%d\n", info->size_b);
}

void	printlists(t_info *info)
{
	t_cdl	*current;

	ft_printf("------------stack a ------------\n");
	current = info->top_a;
	while (info->size_a)
	{
		ft_printf("val %d,", current->value);
		ft_printf("prev val %d,", current->prev->value);
		ft_printf("next val %d\n", current->next->value);
		if (current == info->bot_a)
			break ;
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
			break ;
		current = current->next;
	}
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac == 1)
		return (0);
	if (!is_valid(av))
		return (ft_putstr_fd("Error\n", 2), 0);
	if (ac == 2)
		return (0);
	if (init_info(&info, ac, av) == -1)
		return (0);
	valtoindex(&info);
	if (is_sorted_list(&info))
		return ((infoclear(&info), 0));
	if (ac == 3)
		swap_a(&info);
	else if (ac == 4)
		sort_3(&info);
	else if (ac == 5)
		sort_4(&info);
	else if (ac == 6)
		sort_5(&info);
	else
		sort_many(&info);
	infoclear(&info);
	return (0);
}
