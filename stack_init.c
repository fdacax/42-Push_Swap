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

void	init_stack_a(t_stack **stack, char **argv)
{
	long 	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			return ;
		ft_add_node(stack, (int)n);
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
	while ((str[i] >= 9 && str[i] <= 13) || str[i] != 32)
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
