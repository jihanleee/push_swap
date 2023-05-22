#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

typedef int	t_bool;

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_info
{
	int				size;
	struct s_node	top_a;
	struct s_node	bot_a;
	int				size_a;
	struct s_node	top_b;
	struct s_node	bot_b;
	int				size_b;
}				t_info;

#endif