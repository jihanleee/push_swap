#include "push_swap.h"
#include <stdio.h>

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

t_bool	is_valid(int ac, char **av)
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

void	init_info(t_info *info, int ac, char **av)
{
	info->size = ac - 1;
	info->size_a = ac - 1;
	info->size_b = 0;
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac == 1)
		return (0);
	if (!is_valid(ac, av))
		return (ft_printf("Error\n"), 0);
	if (ac == 2)
		return (0);
	init_info(t_info *info, int ac, char **av);
	return (0);
}