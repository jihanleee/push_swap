/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihalee <jihalee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:24:12 by jihalee           #+#    #+#             */
/*   Updated: 2023/06/13 16:21:57 by jihalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	do_inst(t_info *info, char *line)
{
	if (!ft_strcmp(line, "pa\n"))
		push_a(info);
	else if (!ft_strcmp(line, "pb\n"))
		push_b(info);
	else if (!ft_strcmp(line, "sa\n"))
		swap_a(info);
	else if (!ft_strcmp(line, "sb\n"))
		swap_b(info);
	else if (!ft_strcmp(line, "ss\n"))
		double_swap(info);
	else if (!ft_strcmp(line, "ra\n"))
		rotate_a(info);
	else if (!ft_strcmp(line, "rra\n"))
		reverse_rotate_a(info);
	else if (!ft_strcmp(line, "rb\n"))
		rotate_b(info);
	else if (!ft_strcmp(line, "rrb\n"))
		reverse_rotate_b(info);
	else if (!ft_strcmp(line, "rrr\n"))
		double_reverse_rotate(info);
	else if (!ft_strcmp(line, "rr\n"))
		double_rotate(info);
	else
		return (ft_putstr_fd("Error\n", 2), -1);
	return (0);
}

int	take_inst(t_info *info)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == 0)
			break ;
		if (do_inst(info, line) == -1)
			return (free(line), -1);
		free(line);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac == 1)
		return (0);
	if (!is_valid(av))
		return (ft_putstr_fd("Error\n", 2), 0);
	if (init_info(&info, ac, av) == -1)
		return (0);
	valtoindex(&info);
	if (take_inst(&info) == -1)
		return (infoclear(&info), 0);
	if (is_sorted_list(&info))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	infoclear(&info);
	return (0);
}
