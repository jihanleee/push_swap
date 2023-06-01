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

t_node	*ft_lstnew(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof (t_node));
	if (new == 0)
		return (NULL);
	new->next = 0;
	new->prev = 0;
	new->value = value;
	return (new);
}

void	infoclear(t_info *info)
{
	t_node	*next;
	t_node	*current;

	free (info->nbrs);
	current = info->top_a;
	info->bot_a->next = 0;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	creat_list(t_info *info)
{
	t_node	*current;
	int		i;

	info->top_a = ft_lstnew(info->nbrs[0]);
	if (info->top_a == 0)
		return (-1);
	info->bot_a = info->top_a;
	current = info->top_a;
	i = 1;
	while (i < info->size)
	{
 		current->next = ft_lstnew(info->nbrs[i]);
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

int	init_info(t_info *info, int ac, char **av)
{
	t_node	*current;
	int		i;

	info->size = ac - 1;
	info->size_a = ac - 1;
	info->size_b = 0;
	info->nbrs = (long *)malloc(sizeof (long) * (ac - 1));
	if (info->nbrs == 0)
		return (-1);
	convert_nbrs(info, ac, av);
	creat_list(info);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_node	*current;
	int		i;

	if (ac == 1)
		return (0);
	if (!is_valid(ac, av))
		return (ft_printf("Error\n"), 0);
	if (ac == 2)
		return (0);
	printf("%d", init_info(&info, ac, av));
 	current = info.top_a;
	while (1)
	{
		printf("val %d,", current->value);
		printf("prev val %d,", current->prev->value);
		printf("next val %d\n", current->next->value);
		if (current == info.bot_a)
			break;
		current = current->next;
	}
 	infoclear(&info);
	return (0);
}