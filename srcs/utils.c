/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihalee <jihalee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:03:01 by jihalee           #+#    #+#             */
/*   Updated: 2023/06/12 22:42:42 by jihalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s == 0)
		return ;
	while (*s)
		write(fd, s++, 1);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	sorted;

	while (1)
	{
		sorted = 1;
		i = 0;
		while (i + 1 < size)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				sorted = 0;
			}
			i++;
		}
		if (sorted == 1)
			return ;
	}
}

long	ft_atol(const char *nptr)
{
	long	i;
	long	result;
	long	sign;

	sign = 1;
	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if (nptr[i] < '0' || nptr[i] > '9')
		return ((long)INT_MAX + 1);
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		if (result * sign < (long)INT_MIN || result * sign > (long)INT_MAX)
			return ((long)INT_MAX + 1);
		i++;
	}
	if (nptr[i] != 0)
		return ((long)INT_MAX + 1);
	return (result * sign);
}

int	ft_bsearch(int *nbrs, int size, int value)
{
	int	max;
	int	min;
	int	mid;

	min = 0;
	max = size - 1;
	mid = (min + max) / 2;
	while (1)
	{
		if (nbrs[mid] == value)
			return (mid);
		if (min >= max)
			return (-1);
		else if (nbrs[mid] < value)
			min = mid + 1;
		else if (nbrs[mid] > value)
			max = mid - 1;
		mid = (min + max) / 2;
	}
}
