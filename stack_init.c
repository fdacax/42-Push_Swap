/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:18:55 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/04/17 17:18:55 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stack **stack, char **argv, int argc) {
	long n;
	int i;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		ft_print_error("Error: Unless 1 number valid as argument");
	if (!check_duplicate(argv))
		ft_print_error("Error: Duplicate numbers are not allowed.");
	if (!check_numbers(argv) || !(check_arg(argv)))
		ft_print_error("Error: invalid arguments");

	i = 1;
	if (argc != 2)
	{
		while (i < argc) {
			n = ft_atol(argv[i]);
			if (n < INT_MIN || n > INT_MAX)
				ft_print_error("Error: over int limits was passed");
			ft_add_node(stack, (int) n);
			i++;
		}
	}
	else
		ft_one_argc(stack, argv);
}


void	ft_one_argc(t_stack **stack, char **str)
{
	int i;
	int j;
//	long n;

	i = 0;

	while (str[i])
	{
		j = 0;
		while ((str[i][j] == ' ') || (str[i][j] == '\t'))
			j++;
		if(str[i][j])
		{
			ft_add_node(stack, ft_atol(&str[i][j]));
		}
		while (str[i][j] != ' ' || str[i][j] != ' ')
			j++;
		i++;
	}
}

void	ft_add_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack *last;

	if(!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if(!node)
		return ;
	node->next = NULL;
	node->data = n;
	if(!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = ft_find_last_node(*stack);
		last->next = node;
		node->prev = last;
	}
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}


